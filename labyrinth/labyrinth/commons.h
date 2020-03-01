#pragma once
#include <ctime>

//����ֵ
const int MAXNSIZE = 1010;
const int MAXN = 14;
const int MAXM = 22;

//��������
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

//�����յ�
int sx = -1, sy = -1;
int ex = -1, ey = -1;

//�Թ�����
int mg[MAXN][MAXM] = { 0 };

struct Node {
	int x, y, pre, index;
	Node(int x, int y, int pre) {
		this->x = x;
		this->y = y;
		this->pre = pre;
	}
	Node(int x, int y, int pre, int index) {
		this->x = x;
		this->y = y;
		this->pre = pre;
		this->index = index;
	}
};