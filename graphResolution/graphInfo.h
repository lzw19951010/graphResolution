#ifndef GRAPHINFO_H
#define GRAPHINFO_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
#define MAX 10000
typedef struct nodeInfo
{
	int ID;//节点编号
	string name;//节点名称
	//节点的XYZ坐标
	double x;
	double y;
	double z;
}nodeInfo;

typedef struct edgeInfo
{
	int start;
	int end;
	double weigh;
}edgeInfo;

class Graph
{
public:
	vector <nodeInfo> node;
	vector <edgeInfo> edge;
	vector < vector <double> > arcs; //邻接矩阵
	Graph(){};
	~Graph(){};

	void initGraphFromFile(string infileName);
	void outputToJS(string outfileName);

};
#endif