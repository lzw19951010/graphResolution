#ifndef GRAPHINFO_H
#define GRAPHINFO_H
#include <string>
using namespace std;
typedef struct nodeInfo
{
	int ID;//�ڵ���
	string name;//�ڵ�����
	//�ڵ��XYZ����
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