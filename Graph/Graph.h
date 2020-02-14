#pragma once

#include"Edge.h"
#include"NodeWeight.h"
#include"UnionFind.h"
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<queue>

template<class T, class D>
class Graph
{
	unordered_map<Node<T>, vector<Edge<T, D>>, NodeHash<T>> map;
	vector<Edge<T, D>> edges;
public:

	Graph() {}
	~Graph() {}
	void addEdge(Node<T>& n1, Node<T>& n2, D w)
	{
		Edge<T, D> e = Edge<T, D>(n1, n2, w);
		edges.push_back(e);

		if (map.find(n1) == map.end())
			map.insert(make_pair(n1, vector<Edge<T, D>>()));
		map[n1].push_back(e);

		if (map.find(n2) == map.end())
			map.insert(make_pair(n2, vector<Edge<T, D>>()));
		map[n2].push_back(Edge<T, D>(n2, n1, w));
	}
	void addEdge(T t1, T t2, D w)
	{
		Node<T> n1 = Node<T>(t1);
		Node<T> n2 = Node<T>(t2);
		addEdge(n1, n2, w);
	}
	

	// za algoritam je mogla i jedna klasa da se koristi samo Node<T,D> npr da se sa dodatnim atributom weight
	// ali opet bi trebalo da se preklope operatori drugacije, verovatno moze i tako se realizuje
	vector<Edge<T, D>> Mst_Prim(T val) const
	{
		auto n = map.find(Node<T>(val)); // za startni cvor
		NodeWeight<T,D> start = NodeWeight<T,D>(n->first,0); // napravimo cvor pomocne klase za algoritam
		unordered_map<Node<T>, Edge<T, D>,NodeHash<T>> inMST; //za pamcenje grana koje smo izabrali od poslednjeg obidjenog cvora
		vector<Edge<T, D>> mst;								  // kako bi znali koju granu ubacujemo u rezultat
		multiset<NodeWeight<T,D>> minHeap;					  //priority_queue preko multiseta, jer postoje grane sa istim tezinama
		unordered_map<Node<T>,typename multiset<NodeWeight<T, D>>::iterator, NodeHash<T>> posIter;
		//postIter, jesu pozicije iteratora multiseta tj priority_queue
		posIter[n->first] = minHeap.insert(start); // ubacujemo poziciju pocetnog cvora
		for (auto it = map.begin(); it != map.end(); it++)
		{
			if(!(it->first==n->first))
			{ 
				NodeWeight<T, D> node = NodeWeight<T, D>(it->first, INT_MAX);// pravimo nove cvorove
				posIter[it->first] = minHeap.insert(node);//ubacujemo u minHeap i u hesh_mapi njihove pozicije u posIter
			}

		}
		
		while (!minHeap.empty())
		{
			NodeWeight<T, D> n = *minHeap.begin(); //grana koja je najlaksa sa cvorom koji smo izabrali
			minHeap.erase(minHeap.begin());
			posIter.erase(n.getData());
			auto e = inMST.find(n.getData());
			if (e != inMST.end())
				mst.push_back(e->second);
			
			for (auto it = map.at(n.getData()).begin(); it != map.at(n.getData()).end(); it++)
			{
				
				auto it1 = posIter.find(it->getEnd());
				if(it1 != posIter.end() && it1->second->isMinForNode(it->getWeight()))
				{ 
						minHeap.erase(it1->second);
						NodeWeight<T, D> n1 = NodeWeight<T, D>(it->getEnd(), it->getWeight());
						posIter[it->getEnd()] = minHeap.insert(n1);	//u cpp-u mora ovako jer moze samo da se pristupi elementima u multiset-u
						inMST[it->getEnd()] = *it;					// nije dozvoljena modifikacija i update tree-a, jer su konstantni objekti
				}
			}
		}
		return mst;
	}

	vector<Edge<T,D>> Mst_Kruskal() const
	{
		vector<Edge<T,D>> mst; // rezultat
		multiset<Edge<T,D>> minHeapEdges; //priority_queue preko multiseta
		for (auto e : edges)
		{
			// sortiranje grana
			minHeapEdges.insert(e);
		}

		UnionFind<T> uf(map.size());
		for (auto it = map.begin();it!=map.end();it++)
		{
			uf.insert(it->first, NULL);
		}
		//incijalizacija
		while (!minHeapEdges.empty())
		{
			Edge<T,D> e = *minHeapEdges.begin();
			minHeapEdges.erase(minHeapEdges.begin());
			if (!uf.IsConnected(e.getStart(), e.getEnd()))
			{
				uf.Connect(e.getStart(), e.getEnd());
				mst.push_back(e);
			}
		}
		return mst;
	}
};

template<typename T, typename D>
ostream & operator<< (ostream & os, const Graph<T, D> & g)
{
	os << "Graph" << endl;
	
	for (auto it = g.map.begin(); it != g.map.end(); it++)
	{

		{
			
			os << it->first << "  adj: "<<endl;

			for (auto it1 = it->second.begin(); it1 != it->second.end(); it1++)
				os << " Edge: " << *it1 << endl;
			os << endl;
		}

	}
	return os;
}
