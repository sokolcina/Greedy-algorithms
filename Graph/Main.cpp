#include<unordered_set>
#include<unordered_map>
#include"Graph.h"
#include"Stopwatch.h"
#include<fstream>
typedef long long ll;

int  main()
{
	
	int n1,n2;
	ll w;
	
	ifstream input("Input.dat");
	size_t n, m;
	input >> n >> m;
	Graph<int, ll> g = Graph<int, ll>(n,m);
	char c;
	while (input >> c >> n1 >> n2 >> w)
		g.addEdge(n1, n2, w);
	input.close();

	//cout << g << endl;
	ofstream output("Output.txt");
	Stopwatch time;
	vector<Edge<int, ll>> mts = g.Mst_Prim(1);

	ll res = 0;
	for (Edge<int, ll> e : mts)
		res += e.getWeight();
	output << "Primov algoritam: " << time.elapsed() << "\n";
	/*for (Edge<int, ll> e : mts)
		output << e << ' ';*/
	output << endl<<"Minimalna cena je: "<<res<<endl;
	
	time.reset();
	mts = g.Mst_Kruskal();
	res = 0;
	
	for (Edge<int, ll> e : mts)
		res += e.getWeight();
	/*for (Edge<int, ll> e : mts)
		output << e << ' ';*/
	output << "Kruskalov algoritam: " << time.elapsed() << "\n";
	output << "Minimalna cena je: " << res << endl;

	output.close();
	system("pause");
	return 0;
}