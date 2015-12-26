#include "resolution.h"
double DIJK(Graph& G,int v0, int end, vector <int> &Q)
{
	int v,w;
	vector <int> final(G.node.size());//��final[i] == 1��˵�� ����vi���ڼ���S��
	Q.resize(G.node.size());
	vector <double> D(G.node.size());//�������·������
	for (v = 1; v < G.node.size(); v++) //ѭ�� ��ʼ��
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
		final[v] = 1; //ѡ���õ����뵽�ϼ�S��
		for (w = 1; w < G.node.size(); w++)//���µ�ǰ���·���;���
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

// Prim�㷨������С������
double Prim(Graph G, vector<edgeInfo> &eI)
{
	
	int min, i, j, k;
	vector <int> adjvex;		// ������ض����±�
	vector <int> lowcost;	// ������ض����ߵ�Ȩֵ
	adjvex.resize(G.node.size());
	lowcost.resize(G.node.size());
	lowcost[1] = 0;			// V0��Ϊ��С�������ĸ���ʼ������ȨֵΪ0
	adjvex[1] = 1;			// V0��һ������
	double length = 0;
	int start, end;
	// ��ʼ������
	for(i = 2; i < G.node.size(); i++)
	{
		lowcost[i] = G.arcs[1][i];	// ���ڽӾ����0������Ȩֵ�ȼ�������
		adjvex[i] = 1;				// ��ʼ��ȫ����ΪV0���±�
	}

	// ����������С�������Ĺ���
	for(i = 2; i < G.node.size(); i++ )
	{
		min = MAX;		// ��ʼ����СȨֵΪ65535�Ȳ�������ֵ
		j = 2;
		k = 0;

		// ����ȫ������
		while( j < G.node.size() )
		{
			// �ҳ�lowcost�����Ѵ洢����СȨֵ
			if( lowcost[j]!=0 && lowcost[j] < min )
			{
				min = lowcost[j];
				k = j;		// �����ֵ���СȨֵ���±����k���Դ�ʹ�á�
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
		lowcost[k] = 0;		// ����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ�������񣬽�����һ������ı���

		// �ڽӾ���k���������ȫ������
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