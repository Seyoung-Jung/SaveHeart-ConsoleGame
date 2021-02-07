#ifndef CTIME_H
#define CTIME_H
#include <ctime>
#endif

#ifndef WINDOWS_H
#define WINDOWS_H
#include <Windows.h>
#endif

#ifndef CONIO_H
#define CONIO_H
#include <conio.h>
#endif

#ifndef __UTIL_H__
#define __UTIL_H__
#include "util.h"
#endif

using namespace std;


//�̵� ��ġ ��ǥ
typedef struct point
{
	short x;
	short y;
} point;

typedef point* ppoint;

//�̷� 2���� �迭
int maze[20][20] = {
{ 2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0 },
{ 0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0 },
{ 0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0 },
{ 0,1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0 },
{ 0,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0 },
{ 0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0 },
{ 0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0 },
{ 1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
{ 0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0 },
{ 0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0 },
{ 0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0 },
{ 0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
{ 0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0 },
{ 0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0 },
{ 0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0 },
{ 0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0 },
{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,3 }
};

//�̷� ����
void SetMaze(ppoint player, ppoint start, ppoint end)
{
	start->x = 0;
	start->y = 0;
	end->x = 19;
	end->y = 19;
	player->x = 0;
	player->y = 0;
}



//�ܼ� �׵θ� ���
void wakeUpPrintMargin()
{
	int x = 6, y = 2;
	gotoxy(x, y);
	cout << "��";
	for (int i = 0; i < 80; i++) cout << "��";
	cout << "��";
	for (int i = 1; i < 25; i++)
	{
		y++;
		gotoxy(x, y);
		cout << "��";
		x += 81;
		gotoxy(x, y);
		cout << "��";
		x = 6;
	}
	cout << endl;
	gotoxy(6, 27);
	cout << "��";
	for (int i = 0; i < 80; i++) cout << "��";
	cout << "��" << endl;
}

//���� ���� �� ȭ�� ���
void wakeUpPrintWelcome()
{
	wakeUpPrintMargin();
	char next;
	gotoxy(37, 7);
	cout << "������������������������������������" << endl;
	gotoxy(37, 8);
	cout << "��   �ޱ��� ����  ��" << endl;
	gotoxy(37, 9);
	cout << "������������������������������������" << endl;
	gotoxy(10, 12);
	cout << "����� �޿��� �Ͼ�� �մϴ�. ����� ���ҽ�, ȣ������ ��ų �� �����ϴ�." << endl;
	gotoxy(34, 15);
	cout << "�� ���� ��� : �̷�ã�� ��" << endl;

	gotoxy(27, 18);
	cout << "w : ��   s : �Ʒ�  a : ����  d : ������" << endl;
	gotoxy(38, 20);
	cout << "���� �ð� : 20��" << endl;
	gotoxy(26, 24);
	cout << "�� �غ� �Ǽ̴ٸ� sŰ�� ��������.��  ";
	while(true){
		next = _getch();
		if (next == 's') {
			Init();
			return;
		}
	}
}

//Ű���� �׸� ���
void wakeUpwakeUpPrintKeyboard()
{
	gotoxy(62, 15);
	cout << "��";
	for (int i = 0; i < 6; i++) cout << "��";
	cout << "��";
	gotoxy(62, 16);
	cout << "��      ��";
	gotoxy(62, 17);
	cout << "��   W  ��";
	gotoxy(62, 18);
	cout << "��      ��";
	gotoxy(55, 19);
	cout << "��";
	for (int i = 0; i < 20; i++) cout << "��";
	cout << "��";
	gotoxy(55, 20);
	cout << "��      ��      ��      ��";
	gotoxy(55, 21);
	cout << "��   A  ��   S  ��   D  ��";
	gotoxy(55, 22);
	cout << "��      ��      ��      ��";
	gotoxy(55, 23);
	cout << "��";
	for (int i = 0; i < 20; i++) cout << "��";
	cout << "��" << endl;
	gotoxy(61, 25);
	cout << "<  ����Ű >";
}

//�̷� ���
void PrintMaze(int maze[][20])
{
	wakeUpPrintMargin();
	int x = 10, y = 4; //�ܼ� �׵θ� �ȿ��� ���� ��ǥ
	for (int i = 0; i < 20; i++)
	{
		gotoxy(x, y);
		for (int j = 0; j < 20; j++)
		{
			if (maze[i][j] == 0) //��
				cout << "��";
			else if (maze[i][j] == 1) //��
				cout << "  ";
			else if (maze[i][j] == 2) //�����
				cout << "��";
			else if (maze[i][j] == 3) //������
				cout << "��";
		}
		cout << endl;
		y++;
	}
	gotoxy(x, y + 1);
	cout << "w : ��   s : �Ʒ�  a : ����  d : ������" << endl;

	wakeUpwakeUpPrintKeyboard();
}

//��ġ �̵�
void wakeUpMovePlayer(int maze[20][20], ppoint player, char cinput)
{
	int x = 12, y = 4;
	switch (cinput)
	{
	case 'w': //��
		if ((player->y > 0) && maze[player->y - 1][player->x] !=0) //�̷� ���� �ƴϰ�, ������ �ϴ� ������ �ո� ���̾����
		{
			//�̷ι��ڰ� 2byte�� ��ǥ*2
			//���� ��ǥ���� Ŀ���� 2�� �ڷ� ���� ���� ��ġ�� 2byte ��� �����ϴ�.
			gotoxy(x+2 * player->x-2, y+player->y); 
			cout << "  "; //���� ��ġ�� ���� ���
			--(player->y);
			gotoxy(x+2 * player->x-2, y+player->y);
			cout << "��"; //�̵��� ��ġ�� �� ���
			gotoxy(x+2 * player->x-2, y+player->y); //Ŀ���� ���� ��ġ�� �־�� �ϹǷ� �� ��ġ�� �̵�
		} break;

	case 's':  //�Ʒ�
		if ((player->y < 20) && maze[player->y + 1][player->x] !=0)
		{
			gotoxy(x+2 * player->x-2,y+ player->y);
			cout << "  ";
			++(player->y);
			gotoxy(x+2 * player->x-2,y+ player->y);
			cout << "��";
			gotoxy(x+2 * player->x - 2, y+player->y);
		} break;

	case 'a': //����
		if ((player->x > 0) && maze[player->y][player->x - 1] !=0)
		{
			gotoxy(x + 2 * player->x - 2, y + player->y);
			cout << "  ";
			--(player->x);
			gotoxy(x+2 * player->x-2, y+player->y);
			cout << "��";
			gotoxy(x+2 * player->x - 2, y+player->y);
		} break;

	case 'd': //������
		if ((player->x < 20) && maze[player->y][player->x+1] !=0)
		{
			gotoxy(x+2 * player->x - 2, y+player->y);
			cout << "  ";
			++(player->x);
			//gotoxy(x+2 * player->x-2, y+player->y);
			cout << "��";
			gotoxy(x+2 * player->x - 2, y+player->y);
		} break;
	}
}

//����ð� ���
void wakeUpPrintTime(int start, short x, short y)
{
	int oldTime = (clock() - start)/1000;
	gotoxy(60, 10);
	cout << "�� " << oldTime << "�� ��� ��";
	gotoxy(x, y);   //���� ��ġ�� ���ư�
}

//���� ����
int wakeUpPlayGame(ppoint player, ppoint end)
{
	int startTime = clock(); //Ÿ�̸� ����

	while (true) //�����Ҷ�����
	{
		char cinput = _getch();
		wakeUpMovePlayer(maze, player, cinput);
		wakeUpPrintTime(startTime, 12, 4);
		if (player->x == end->x && player->y == end->y) break; //����
	}

	int endTime = clock(); //Ÿ�̸� ����
	gotoxy(55, 13);
	if ((endTime - startTime )/1000< 20){
		cout << "�� �޿��� ������ϴ�. ��" << endl;
		return 1;
	}
	else{
		cout << "�� �޿��� ����� ���߽��ϴ�. ��" << endl;
		return 0;
	}
}

int wakeUpGame()
{	
	system("cls");
	Init();
	wakeUpPrintWelcome();
	point start, end, player;
	SetMaze(&player, &start, &end);
	PrintMaze(maze);
	int result = wakeUpPlayGame(&player, &end);
	return result;
}