#pragma once
#include <iostream>
using namespace std;
class Activity
{
public:
	Activity(int s, int f):start{s},finish{f}{}
	~Activity();
private:
	int start; // pocetak aktivnosti
	int finish; // kraj aktivnosti
public:
	int getStart();
	int getFinish();
	void setStart(int s);
	void setFinish(int f);
	// za potrebe algoritma preklapamo operator kako bi izvrsili sortiranje po finish
	bool operator <(const Activity& a)
	{
		return finish < a.finish;
	}
	friend ostream& operator <<(ostream& out, const Activity& a)
	{
		return out << '[' << a.start << ',' << a.finish << "] ";
	}
};

