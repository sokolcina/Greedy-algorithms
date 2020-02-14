#include"Item.h"
#include<algorithm>
#include<vector>
#include<fstream>

//funkcija koja predstavlja algoritam
double value(vector<Item> items, int capacity)
{
	sort(items.rbegin(), items.rend());
	//koristim double zbog preciznosti
	double val = 0;
	int cap = 0;
	cout << endl;
	
	for (auto it = items.begin(); it != items.end(); ++it)
		cout << *it;
	cout << endl;
	vector<Item>::iterator it;
	//iteracija do kraja niza ukoliko je kapacitet veci od sve postojece predmete ili dok se ne prepuni ranac
	//pa moramo da secemo odredjeni predmet
	for ( it = items.begin(); (it != items.end()) && (it->getW() + cap <= capacity); ++it)
	{
		val += it->getV();
		cap += it->getW();
	}
	val += (capacity - cap)*(double)it->getV() / it->getW();
	return val;
}

int main()
{

	vector<Item> items;
	ifstream input("Input.txt");
	int w, v;
	while (input >> w >> v)
		items.push_back(Item(w, v));
	input.close();
	
	for (auto it = items.begin(); it != items.end(); ++it)
		cout << *it;
	ofstream output("Output.txt");
	output << "Najveca moguca vrednost je: "<< value(items, 30)<<endl;
	output.close();

	system("pause");
	return 0;
}