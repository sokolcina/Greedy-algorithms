#include "Activity.h"
#include<algorithm>
#include<vector> // najbolje je da koristimo vector jer pretpostavljamo da mogu da postoje dve razlicite aktivnosti
#include<fstream>// sa istim pocetkom vremena i istim krajem

vector<Activity> findActivities(vector<Activity>& activities)
{
	vector<Activity> result;
	sort(activities.begin(), activities.end()); // sortiramo u rastucem poretku po zavrsnom vremenu
	int k = 0;
	result.push_back(activities[0]); // ubacimo u rezultat prvu aktivnost koju menadzer obavlja
	for(int i=1;i<activities.size();i++) // pocinjemo od druge aktivnosti
		if (activities[i].getStart() >= activities[k].getFinish()) // trazimo narednu aktivnost koja pocinje tacno
		{														   // kada se zavrsava trenutna aktivnost ili nakon nje
			result.push_back(activities[i]);
			k = i;
		}
	return result;
}

int main()
{
	vector<Activity> activities;
	ifstream input("Input.txt");
	int s, f;
	while (input>>s>>f)
		activities.push_back(Activity(s, f));
	input.close();

	vector<Activity> result;
	result = findActivities(activities);

	ofstream output("Output.txt");
	output << "Aktivnosti: ";
	for (auto it = activities.cbegin(); it != activities.cend(); ++it)
	{
		output << *it;
		cout << *it;
	}
	cout << endl;
	output << endl <<"Izabrane aktivnosti: ";
	for (auto it = result.cbegin(); it != result.cend(); ++it)
	{
		output << *it;
		cout << *it;
	}
	
	output.close();
	system("pause");
	return 0;
}