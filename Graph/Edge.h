#pragma once
#include"Node.h"

template<class T,class D>
class Edge
{
public:
	Edge(Node<T> s, Node<T> e, D w):start{s},end{e},weight{w}{}
	Edge(){}
	~Edge() {}
private:
	Node<T> start;
	Node<T> end;
	D weight;
public:
	D getWeight() const  {
		return weight;
	}
	Node<T> getStart() const {
		return start;
	}
	Node<T> getEnd() const {
		return end;
	}
	bool operator==(const Edge<T, D> & e)const
	{
		if ((e.start == start && e.end == end && e.weight == weight)||
			(e.start==end && e.end==start && e.weight==weight))
			return true;
		else return false;
	}
	bool operator <(const Edge<T, D> e) const
	{
		return weight < e.getWeight();
	}
};


template<class T, class D>
struct EdgeHash
{
	size_t operator() (const Edge<T, D>& e) const
	{
		size_t h1 = hash<T>()(e.getStart().getData());
		size_t h2 = hash<T>()(e.getEnd().getData());
		llabs(h1 += h2);
		size_t h3 = hash<D>()(e.getWeight());
		return h1 ^ (h3 << 1);
	//	return hash<T>()(e.getStart().getData());
	}
};

template<typename T, typename D>
ostream& operator <<(ostream& out, const Edge<T, D> & e)
{
	return out << '[' << e.getStart() << ',' << e.getEnd() << ',' << e.getWeight() << ']';
}
