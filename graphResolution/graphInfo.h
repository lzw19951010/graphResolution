#ifndef GRAPHINFO_H
#define GRAPHINFO_H
#include <string>
using namespace std;
typedef struct nodeInfo
{
	int ID;//节点编号
	string name;//节点名称
	//节点的XYZ坐标
	int x;
	int y;
	int z;
}nodeInfo;

typedef struct edgeInfo
{
	int start;
	int end;
	double weigh;
}edgeInfo;
#endif