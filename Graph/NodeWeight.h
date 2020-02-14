#pragma once
#include"Node.h"

template<class T,class D>
class NodeWeight
{
public:
	NodeWeight() { data = NULL; weight = 0; }
	NodeWeight(Node<T>_data, D _weight) :data{ _data }, weight{ _weight }{}
	NodeWeight(T t):data{Node<T>(t) },weight{0}{}
	~NodeWeight(){}
private:
	Node<T> data;
	D weight;
public:
	Node<T> getData() const { return data; }
	D getWeight() const { return weight; }

	bool operator<(const NodeWeight<T,D>& n) const
	{
		return weight < n.getWeight();
	}
	bool operator==(const NodeWeight<T, D>& n) const
	{
		return data == n.data;
	}
	void setWeight(D w)  const { weight = w; }
	bool isMinForNode(D w) const
	{
		return w < weight;
	}
};
template<class T,class D>
struct EdgeCompare {
	bool operator() (const NodeWeight<T, D>& n1, const NodeWeight<T, D>& n2) const {
		return !(n1 == n2) && (n1 < n2);
	}
};
template<class T,class D>
struct NodeWeightHash
{
	size_t operator() (const NodeWeight<T,D>& n) const {
		return hash<T>()(n.getData().getData());
	}
};
