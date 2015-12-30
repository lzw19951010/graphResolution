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
	int ID;//�ڵ���
	string name;//�ڵ�����
	//�ڵ��XYZ����
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
	vector < vector <double> > arcs; //�ڽӾ���
	Graph(){};
	~Graph(){};

	void initGraphFromFile(string infileName);
	void outputToJS(string outfileName);

};
#endif