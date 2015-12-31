#include "graphInfo.h"

void Graph::initGraphFromFile(string infileName)	//从文件初始化图信息
{
	ifstream in(infileName);
	int numOfVertices,numOfEdge,i;
	string temp;
	edgeInfo tempEdge;

	in >> temp >> numOfVertices;//获取节点数量

	node.resize(numOfVertices+1);//0位置闲置
	arcs.resize(numOfVertices+1);

	for (i = 1; i <= numOfVertices;i++)
	{
		in >> node[i].ID;
		in >> node[i].name;
		in >> node[i].x >> node[i].y >> node[i].z;
		arcs[i].resize(numOfVertices+1,MAX);
	}//获取节点信息
	in >> temp;//去掉无用信息
	while(!in.eof())
	{
		in >> tempEdge.start >> tempEdge.end >> tempEdge.weigh;
		arcs[tempEdge.start][tempEdge.end] = tempEdge.weigh;
		arcs[tempEdge.end][tempEdge.start] = tempEdge.weigh;
		edge.push_back(tempEdge);//获取边信息
	}
}

void Graph::screenFromGraph(Graph &G)
{
	G.node.resize(1);
	G.edge.resize(1);
	G.arcs.resize(201);
	for (int i = 1; i <= 200; i++)
	{
		G.arcs[i].resize(201,MAX);
	}

	vector<int> id(2,1);
	G.node.push_back(node[1]);
	
	for(int i = 1; i < id.size(); ++i)
	{
		for(int j = id[i] + 1; j < node.size(); ++j)
		{
			if(arcs[id[i]][j] < MAX && find(id.begin(), id.end(), j) == id.end())
			{
				id.push_back(j);
				G.node.push_back(node[j]);
			}
			if(id.size() > 200)
			{
				break;
			}
		}
	}
	for(int i = 1; i <= 199; ++i)
	{
		for(int j = i + 1; j <= 200; ++j)
		{
			G.arcs[i][j] = arcs[id[i]][id[j]];
			G.arcs[j][i] = arcs[id[i]][id[j]];
			if(G.arcs[i][j] < MAX)
			{
				edgeInfo temp;
				temp.start = i;
				temp.end = j;
				temp.weigh = G.arcs[i][j];
				G.edge.push_back(temp);
			}
		}
	}
	
	/*
	G.node.push_back(node[1]);
	for(int i = 1; i < edge.size(); ++i)
	{
		if(edge[i].start == 1)
		{
			G.node.push_back(node[edge[i].end]);
			G.node[G.node.size()-1].ID = G.node.size() - 1;
			G.edge.push_back(edge[i]);
			G.edge[G.edge.size()-1].end = G.node[G.node.size()-1].ID;
			arcs[1][G.node[G.node.size()-1].ID] = G.edge[G.edge.size()-1].weigh;
			arcs[G.node[G.node.size()-1].ID][1] = G.edge[G.edge.size()-1].weigh;
		}
		else if(edge[i].end == 1)
		{
			G.node.push_back(node[edge[i].start]);
			G.node[G.node.size()-1].ID = G.node.size() - 1;
			G.edge.push_back(edge[i]);
			G.edge[G.edge.size()-1].start = G.node[G.node.size()-1].ID;
			arcs[1][G.node[G.node.size()-1].ID] = G.edge[G.edge.size()-1].weigh;
			arcs[G.node[G.node.size()-1].ID][1] = G.edge[G.edge.size()-1].weigh;
		}
		if(G.node.size() >= 201)
		{
			break;
		}
	}
	*/
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
	outfile << "], \"edges\": [";
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
	outfile << "],\"arcs\":[";
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
	outfile << "]};";
}