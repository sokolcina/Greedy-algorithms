#include<unordered_set>
#include<unordered_map>
#include"Graph.h"
#include<fstream>
int  main()
{
	
	char n1,n2;
	int w;
	Graph<char, int> g = Graph<char, int>();
	ifstream input("Input.txt");
	while (input >> n1 >> n2 >> w)
		g.addEdge(n1, n2, w);
	input.close();

	//cout << g << endl;
	ofstream output("Output.txt");
	vector<Edge<char, int>> mts = g.Mst_Prim('B');
	int res = 0;
	for (Edge<char, int> e : mts)
		res += e.getWeight();
	output << "Primov algoritam:" << endl;
	for (Edge<char, int> e : mts)
		output << e << ' ';
	output << endl<<"Minimalna cena je: "<<res<<endl;
	

	mts = g.Mst_Kruskal();
	res = 0;
	output << "Kruskalov algoritam:" << endl;
	for (Edge<char, int> e : mts)
		res += e.getWeight();
	for (Edge<char, int> e : mts)
		output << e << ' ';
	output << endl << "Minimalna cena je: " << res << endl;
	
	system("pause");
	return 0;
}