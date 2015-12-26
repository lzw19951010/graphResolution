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

