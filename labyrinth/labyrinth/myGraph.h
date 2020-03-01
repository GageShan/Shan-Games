#pragma once

#include "commons.h"

#include<graphics.h>
#include<vector>

void initGameMenu() {
	settextcolor(GREEN);
	rectangle(1050, 100, 1250, 150);//�������
	rectangle(1050, 150, 1250, 200);//�����յ�
	rectangle(1050, 200, 1250, 250);//����ϰ�
	rectangle(1050, 250, 1250, 300);//��ʼѰ·
	rectangle(1050, 300, 1250, 350);//�˳��Թ�
	RECT r1 = { 1050, 100, 1250, 150 };
	drawtext(_T("�������"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r2 = { 1050, 150, 1250, 200 };
	drawtext(_T("�����յ�"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3 = { 1050, 200, 1250, 250 };
	drawtext(_T("����ϰ�"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4 = { 1050, 250, 1250, 300 };
	drawtext(_T("��ʼѰ·"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5 = { 1050, 300, 1250, 350 };
	drawtext(_T("�˳��Թ�"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void paintMainMenu(COLORREF headColor, COLORREF tailColor, LPCTSTR text[3], int point[][4]) {
	settextcolor(headColor);
	for (int i = 0; i < 3; i++) {
		if (i == 1) { settextcolor(tailColor); }
		rectangle(point[i][0], point[i][1], point[i][2], point[i][3]);
		RECT r = { point[i][0], point[i][1], point[i][2], point[i][3] };
		drawtext(text[i], &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}


//����Ϸҳ��
void paintGameMenu(COLORREF headColor, COLORREF tailColor, LPCTSTR text[5], int point[][4]) {
	settextcolor(headColor);
	for (int i = 0; i < 5; i++) {
		if (i == 1) { settextcolor(tailColor); }
		rectangle(point[i][0], point[i][1], point[i][2], point[i][3]);
		RECT r = { point[i][0], point[i][1], point[i][2], point[i][3] };
		drawtext(text[i], &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}


//��ʼ����ҳ��
void initMainMenu() {
	settextcolor(GREEN);
	rectangle(550, 300, 750, 400);
	rectangle(550, 400, 750, 500);
	rectangle(550, 500, 750, 600);
	RECT r1 = { 550, 300, 750, 400 };
	drawtext(_T("DFS"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r2 = { 550, 400, 750, 500 };
	drawtext(_T("BFS"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3 = { 550,500,750,600 };
	drawtext(_T("EXIT"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

//���Թ�ͼ��
void PrintLine()
{
	setbkcolor(WHITE);
	cleardevice();
	//���Թ�ͼ��
	setlinecolor(BLACK);
	for (int i = 0; i <= 1000; i += 50)  line(i, 0, i, 1000);
	for (int i = 0; i <= 600; i += 50)  line(0, i, 1000, i);
}

//�����ɫ������Թ�·��
void FillColor()     
{
	srand(time(NULL)); //��ʼ�����������
	setfillcolor(RED);
	//�����ɫ���Էֱ����·���Ͳ�����·��
	int flag = 1;
	for (int i = 0; i < 1000; i += 50) {

		for (int j = 0; j < 600; j += 50) {

			//�������λ��Ϊ������״̬
			flag = rand();

			if (flag % 2 != 0 && flag % 3 != 0) {

				solidrectangle(i, j, i + 50, j + 50);
				mg[(j + 50) / 50][(i + 50) / 50] = 1;

				Sleep(10);

			}
		}
	}
}

void setWindowsName(LPCTSTR name) {
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, name);
}

void setMenuText() {
	setbkmode(TRANSPARENT);//͸������
	LOGFONT f;
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 48;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱
	//f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	setWindowsName(_T("by gageshan"));		//���ô��ھ��
}

void msg(LPCTSTR message) {
	settextcolor(GREEN);
	//rectangle(1050, 450, 1250, 500);
	LOGFONT f;
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 20;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱
	//f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	RECT r = { 1050, 450, 1250, 500 };
	drawtext(message, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	f.lfHeight = 48;                      // ��������߶�Ϊ 48
	settextstyle(&f);                     // ����������ʽ
}