#include "graphInfo.h"
#include "resolution.h"
int main()
{
	Graph G;
	string infileName = "3.Coauthorships in Network Science.net";
	G.initGraphFromFile(infileName);
	vector <int> Q;
	int v0 = 1;
	int destination = 947;
	double res = DIJK(G,v0,destination,Q);
	if (destination == v0)
	{
		cout << v0 <<"-"<<v0<< " "<< 0 <<endl;
	}
	else if (res == MAX)
	{
		cout << "NO PATH" << endl;
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
	
	return 0;
}