#pragma once
#include <iostream>
using namespace std;
//pomocna klasa
class Item
{
public:
	Item();
	~Item();
	Item(int ww,int vv):w{ww},v{vv}{}
private:
	int v;//vrednost
	int w;//tezina
public:
	int getV();
	int getW();
	void setV(int vv);
	void setW(int ww);
	bool operator < (const Item& i)
	{
		double r1 = (double)v / w; //racunanje vrednosti za deo prve stavke
		double r2 = (double)i.v / w; //racunanje vrednosti za deo druge stavke
		return r1 < r2;
	}
	
	friend ostream & operator <<(ostream &out, const Item& i);
};

