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