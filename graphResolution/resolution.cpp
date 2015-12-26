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

// Prim算法生成最小生成树
double Prim(Graph G, vector<edgeInfo> &eI)
{
	
	int min, i, j, k;
	vector <int> adjvex;		// 保存相关顶点下标
	vector <int> lowcost;	// 保存相关顶点间边的权值
	adjvex.resize(G.node.size());
	lowcost.resize(G.node.size());
	lowcost[1] = 0;			// V0作为最小生成树的根开始遍历，权值为0
	adjvex[1] = 1;			// V0第一个加入
	double length = 0;
	int start, end;
	// 初始化操作
	for(i = 2; i < G.node.size(); i++)
	{
		lowcost[i] = G.arcs[1][i];	// 将邻接矩阵第0行所有权值先加入数组
		adjvex[i] = 1;				// 初始化全部先为V0的下标
	}

	// 真正构造最小生成树的过程
	for(i = 2; i < G.node.size(); i++ )
	{
		min = MAX;		// 初始化最小权值为65535等不可能数值
		j = 2;
		k = 0;

		// 遍历全部顶点
		while( j < G.node.size() )
		{
			// 找出lowcost数组已存储的最小权值
			if( lowcost[j]!=0 && lowcost[j] < min )
			{
				min = lowcost[j];
				k = j;		// 将发现的最小权值的下标存入k，以待使用。
			}
			j++;
		}
		if(min == MAX)
		{
			break;
		}
		length += G.arcs[adjvex[k]][k];
		edgeInfo e;
		e.start = adjvex[k];
		e.end = k;
		e.weigh = G.arcs[adjvex[k]][k];
		eI.push_back(e);
		lowcost[k] = 0;		// 将当前顶点的权值设置为0，表示此顶点已经完成任务，进行下一个顶点的遍历

		// 邻接矩阵k行逐个遍历全部顶点
		for( j=2; j < G.node.size(); j++ )
		{
			if( lowcost[j]!=0 && G.arcs[k][j] < lowcost[j] )
			{
				lowcost[j] = G.arcs[k][j];
				adjvex[j] = k;	
			}
		}
	}

	return length;
	
}