#include "resolution.h"
double DIJK(Graph& G,int v0, int end, vector <int> &Q)
{
	int v,w;
	vector <int> final(G.node.size());//若final[i] == 1则说明 顶点vi已在集合S中
	Q.resize(G.node.size());
	vector <double> D(G.node.size());//保存最短路径长度
	for (v = 1; v < G.node.size(); v++) //循环 初始化
	{
		final[v] = 0; 
		D[v] = G.arcs[v0][v];
		if(D[v] == MAX)    
			Q[v] = -1;
		else 
			Q[v] = v0;
	}
	D[v0] = 0; final[v0] = 1; 
	for (int i = 1; i < G.node.size()-1; i++)
	{
		double min = MAX;
		for (w = 1; w < G.node.size(); w++)
		{
			if (!final[w])
			{
				if (D[w] < min) 
				{
					v = w; 
					min = D[w];
				}
			}
		}
		final[v] = 1; //选出该点后加入到合集S中
		for (w = 1; w < G.node.size(); w++)//更新当前最短路径和距离
		{
			if (!final[w] && (min+G.arcs[v][w]<D[w]))
			{
				D[w] = min + G.arcs[v][w];
				Q[w] = v;
			}
		}
	}
	return D[end];
}

