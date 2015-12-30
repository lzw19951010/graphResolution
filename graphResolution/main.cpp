#include "graphInfo.h"
#include "resolution.h"
int main()
{
	Graph G;
	string infileName = "2.Online Social Network.net";
	G.initGraphFromFile(infileName);
	/*
	vector <int> Q;
	int v0, destination;
	cin >> v0 >> destination;
	double res = DIJK(G,v0,destination,Q);
	if (destination == v0)
	{
		cout << v0 <<"-"<<v0<< " "<< 0 <<endl;
	}
	else if (res == MAX)
	{
		cout << "NO PATH" << endl;
		system("pause");
	}
	else
	{
		int pre = destination;
		vector <int> stack;
		stack.clear();
		while (pre != v0)
		{
			stack.push_back(Q[pre]);
			pre = Q[pre];
		}
		for (int j = stack.size() - 1; j >= 0 ; j--)
		{
			cout <<  stack[j] <<"-";
		}
		cout << destination<< " " << res << endl;
	}
	vector<edgeInfo> V;

	double sum = Prim(G, V);
	cout << sum << endl;
	for(int i = 0; i < V.size(); ++i)
	{
		cout << V[i].start << "-" << V[i].end << " ";
	}
	*/

	G.outputToJS("graph.js");
	
	return 0;
}