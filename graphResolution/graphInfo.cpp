#include "graphInfo.h"

void Graph::initGraphFromFile(string infileName)	//从文件初始化图信息
{
	ifstream in(infileName);
	int numOfVertices,numOfEdge,i;
	string temp;
	edgeInfo tempEdge;
	char tempChar;

	in >> temp >> numOfVertices;//获取节点数量

	node.resize(numOfVertices+1);//0位置闲置

	for (i = 1; i <= numOfVertices;i++)
	{
		in >> node[i].ID;
		in >> tempChar;
		getline(in,node[i].name,'"');
		in >> node[i].x >> node[i].y >> node[i].z;
	}//获取节点信息
	in >> temp;//去掉无用信息
	while(!in.eof())
	{
		in >> tempEdge.start >> tempEdge.end >> tempEdge.weigh;
		edge.push_back(tempEdge);//获取边信息
	}
}