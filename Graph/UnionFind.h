#pragma once
#include"Node.h"
#include"Edge.h"
#include<unordered_map>
template<class T>
class UnionFind
{
	unordered_map<Node<T>, Node<T>, NodeHash<T>> parent;
public:
	UnionFind(size_t n)
	{
		parent.reserve(n);
	}
	void insert (Node<T> n1, Node<T> n2)
	{
		parent[n1] = n2;
	}
	~UnionFind(){}

	bool IsConnected(Node<T> n1, Node<T> n2)
	{
		Node<T> node1Component, node2Component;
		node1Component = FindRootOfComponent(n1);
		node2Component = FindRootOfComponent(n2);
		return (node1Component == node2Component);
	}

public:
	void Connect(Node<T> n1, Node<T> n2)
	{
		Node<T> node1Component = FindRootOfComponent(n1);
		Node<T> node2Component = FindRootOfComponent(n2);
		parent[node2Component]= node1Component;
	}

private:
	Node<T> FindRootOfComponent(Node<T> n) 
	{
		Node<T> root = n;
		while (!(parent[root] == NULL))
			root = parent[root];
		return root;
	}
};

