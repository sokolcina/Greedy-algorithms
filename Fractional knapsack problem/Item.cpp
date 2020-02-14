#include "Item.h"



Item::Item()
{
	v = 0;
	w = 0;
}


Item::~Item()
{
}


int Item::getV()
{
	// TODO: Add your implementation code here.
	return v;
}


int Item::getW()
{
	// TODO: Add your implementation code here.
	return w;
}


void Item::setV(int vv)
{
	v = vv;
}


void Item::setW(int ww)
{
	w = ww;
}

ostream & operator<<(ostream & out, const Item & i)
{
	return out << '[' << i.w << ',' << i.v << "] ";
}
