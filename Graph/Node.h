#pragma once
#include<iostream>

using namespace std;

template <class T>
class Node
{
public:
	Node(T _data):data{_data}{}
	Node() { data = NULL; }
	~Node() {}
private:
	T data;
public:

	T getData() const { return data; }
	void setData(const T & _data) const
	{
		data = _data;
	}
	void setData(T & _data)
	{
		data = _data;
	}
	bool operator==(const Node & b)  const
	{
		return (data == b.data);
	}
	bool operator<(const Node & b) const
	{
		return data < b.data;
	}
	Node<T>& operator=(const Node<T>& n)
	{
		if (this != &n)
		{
			T d = n.data;
			this->data = d;
			return *this;
		}
		else return *this;
	}
};

template<class T>
struct NodeHash
{
	size_t operator() (const Node<T>& n) const {
		return hash<T>()(n.getData());
	}
};

template<class T>
ostream & operator<<(ostream& out, const Node<T>& node)
{
	return out << "[Node: " << node.getData() << "]";
}