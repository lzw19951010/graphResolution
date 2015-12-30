#include "graphInfo.h"

void Graph::initGraphFromFile(string infileName)	//���ļ���ʼ��ͼ��Ϣ
{
	ifstream in(infileName);
	int numOfVertices,numOfEdge,i;
	string temp;
	edgeInfo tempEdge;

	in >> temp >> numOfVertices;//��ȡ�ڵ�����

	node.resize(numOfVertices+1);//0λ������
	arcs.resize(numOfVertices+1);

	for (i = 1; i <= numOfVertices;i++)
	{
		in >> node[i].ID;
		in >> node[i].name;
		in >> node[i].x >> node[i].y >> node[i].z;
		arcs[i].resize(numOfVertices+1,MAX);
	}//��ȡ�ڵ���Ϣ
	in >> temp;//ȥ��������Ϣ
	while(!in.eof())
	{
		in >> tempEdge.start >> tempEdge.end >> tempEdge.weigh;
		arcs[tempEdge.start][tempEdge.end] = tempEdge.weigh;
		arcs[tempEdge.end][tempEdge.start] = tempEdge.weigh;
		edge.push_back(tempEdge);//��ȡ����Ϣ
	}
}

void Graph::outputToJS(string outfileName)
{
	ofstream outfile(outfileName);
	outfile << "var Graph = { \"nodes\": [";
	for(int i = 1; i < node.size(); ++i)
	{
		outfile << "{";
		outfile << "name:";
		outfile << node[i].name;
		outfile << "}";
		if(i != node.size()-1)
		{
			outfile << ",";
		}
	}
	outfile << "];, \"edges\": [";
	for(int i = 1; i < edge.size(); ++i)
	{
		outfile << "{";
		outfile << "source:";
		outfile << edge[i].start-1;
		outfile << ",target:";
		outfile << edge[i].end-1;
		outfile << "}";
		if(i != edge.size()-1)
		{
			outfile << ",";
		}
	}
	/*
	outfile << "];,\"arcs\":[";
	for(int i = 1; i < node.size(); ++i)
	{
		outfile << "[";
		for(int j = 1; j < node.size(); ++j)
		{
			outfile << arcs[i][j];
			if(j != node.size()-1)
			{
				outfile << ",";
			}
		}
		outfile << "]";
		if(i != node.size()-1)
		{
			outfile << ",";
		}
	}
	*/
	outfile << "];};";
}