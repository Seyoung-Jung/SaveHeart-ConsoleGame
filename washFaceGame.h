#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#ifndef FSTREAM_H
#define FSTREAM_H
#include <fstream>
#endif

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

//��ǰ�� ��ǥ����, ������ ���� isErased�� ����
//�����ڿ� �� ������ ������, �����ڸ� ����
class bubble
{
public:
	bubble()
	{
		x = 0; y = 0;
		isErased = 1;
	}
	bubble(short x, short y)
	{
		this->x = x; this->y = y;
		isErased = 1;
	}
	short getX() { return x; }
	short getY() { return y; }
	bool getErased() { return isErased; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setErased(bool isErased) { this->isErased = isErased; }

private:
	short x;
	short y;
	bool isErased;
};
void visibleCursor();
int washFaceGame();	//���� ����
void makeBubble(bubble fiveBubble[5]);	//��ǰ ����
		//Ŀ���� (x, y)�� �̵�
void move(short& x, short& y);			//wsad Ű�� �̿��Ͽ� �����¿� �� ĭ�� �̵�
void wipeBubble(short& x, short& y, bubble bubble[5]);	//��ǰ �۱�
short isBubble(short& x, short& y, bubble bubble[5]);	//��ǰ ��ǥ ��ġ�ϴ��� Ȯ��
void printTime(int start, short x, short y);			//���ۺ��� ����ð� ���
void printMargin();		//��ü Ʋ ���
void printWelcome();	//���� ȭ�� ���
int printByeBye(int start);	//���� ȭ�� ���
void printKeyboard();	//����Ű ���
void printFrame();	//�⺻ ���� Ʋ ���
int play(short& x, short& y, bubble fiveBubble[5]);	//���� ����
void fontSize(int size);

int washFaceGame() {
	system("cls");
	Init();
	visibleCursor();
	printWelcome();

	bubble fiveBubble[5];

	short x = 3, y = 2;

	int result = play(x, y, fiveBubble);
	Sleep(2000);
	return result;
}
void makeBubble(bubble fiveBubble[5])
{
	srand((int)time(0));

	for (int i = 0; i < 5; i++)	//�������� �ټ� ���� ��ǰ ���
	{
		short xp = rand() % 40 + 3;
		short yp = rand() % 24 + 1;

		//��ǰ�� (x,y) ��Ƴ���
		fiveBubble[i].setX(xp);
		fiveBubble[i].setY(yp);

		//�ش� ��ġ�� Ŀ�� �̵��Ͽ� ��ǰ ���
		gotoxy(xp, yp);
		cout << "��";
		gotoxy(xp + 2, yp);
		cout << "��";
		gotoxy(xp, yp + 1);
		cout << "��";
		gotoxy(xp + 2, yp + 1);
		cout << "��";
	}
}
void move(short& x, short& y)
{
	//���� �Է¹ޱ�
	char temp = _getch();

	//�� �������� Ŀ�� �̵� ����
	if (temp == 'w' || temp == 'W') {
		if (y > 1) {
			gotoxy(x, --y);
		}
	}
	else if (temp == 'a' || temp == 'A') {
		if (x > 3) {
			gotoxy(--x, y);
		}
	}
	else if (temp == 's' || temp == 'S') {
		if (y < 26) {
			gotoxy(x, ++y);
		}
	}
	else if (temp == 'd' || temp == 'D') {
		if (x < 46) {
			gotoxy(++x, y);
		}
	}
}
void wipeBubble(short& x, short& y, bubble bubble[5])
{
	move(x, y);

	for (int j = 0; j < 5; j++)
	{
		//���� ��ǥ�� 5���� ��ǰ �� �ϳ��� ��ġ�ϸ�, ��ǰ�� ����� �ش� ��ǰ�� isErased�� 0���� �ٲٱ�
		if (isBubble(x, y, bubble))
		{
			short index = isBubble(x, y, bubble) - 1;
			gotoxy(bubble[index].getX(), bubble[index].getY());
			cout << "    ";
			gotoxy(bubble[index].getX(), bubble[index].getY() + 1);
			cout << "    ";
			gotoxy(x, y);
			bubble[index].setErased(0);
		}
	}
}
short isBubble(short& x, short& y, bubble bubble[5])
{
	for (int j = 0; j < 5; j++)
	{
		short xCoord = bubble[j].getX();
		short yCoord = bubble[j].getY();
		if (bubble[j].getErased() == true)
		{
			if (x == xCoord || x == (xCoord + 1) || x == (xCoord + 2) || x == (xCoord + 3))
			{
				if (y == yCoord || y == (yCoord + 1))
				{
					return (j + 1);
				}
			}
		}
	}

	return 0;
}
void printTime(int start, short x, short y)
{
	int oldTime = (int)(time(0) - start);
	gotoxy(60, 15);
	cout << "! " << oldTime << " ! �� ���";
	gotoxy(x, y);	//���� ��ġ�� ���ư�
}
void printMargin()
{
	int x = 0, y = 2;
	gotoxy(x, y);
	cout << "��";
	for (int i = 0; i < 80; i++) cout << "��";
	cout << "��";
	for (int i = 0; i < 27; i++)
	{
		y++;
		gotoxy(x, y);
		cout << "��";
		x = 81;
		gotoxy(x, y);
		cout << "��";
		x = 0;
	}
	cout << endl;
	gotoxy(0, 29);
	cout << "��";
	for (int i = 0; i < 80; i++) cout << "��";
	cout << "��" << endl;
}
void printWelcome()
{
	gotoxy(29, 6);
	cout << "��";
	for (int i = 0; i < 19; i++) cout << "��";
	cout << "��";
	gotoxy(29, 7);
	cout << "��    �����ϱ� ����  ��";
	gotoxy(29, 8);
	cout << "��";
	for (int i = 0; i < 19; i++) cout << "��";
	cout << "��" << endl;
	gotoxy(35, 12);
	cout << "< ���� >";
	gotoxy(3, 14);
	cout << "�� ������ ���� �ð� ���� �󱼿� ���� �񴩰�ǰ�� �� ����� �����ϴ� �����Դϴ�.";
	gotoxy(20, 16);
	cout << "����Ű�� �� �����Ͽ� ��ǰ���� �̵��ϼ���!";
	gotoxy(25, 18);
	cout << "����Ű : wasd�� �����¿� �̵�";
	gotoxy(27, 22);
	cout << "�����Ϸ��� s�� �������� !";
	while(true){
		if (_getch() == 's' || _getch() == 'S') {
			Init(); 
			visibleCursor(); 
			system("cls");
			return;
		}
	}
}
int printByeBye(int start)
{
	gotoxy(45, 25);
	double now = (double)(time(0) - start);

	cout << now << "�� �ɸ��̽��ϴ�.";

	gotoxy(45, 26);
	if (now <= 10){
		cout << "�����Դϴ�. �����ؿ�...������" << endl << endl;
		return 1;
	}
	else{
		cout << "�����Դϴ�. ���� ��ȸ��...������" << endl << endl;
		return 0;
	}
}
void printKeyboard()
{
	gotoxy(95, 8);
	cout << "��";
	for (int i = 0; i < 6; i++) cout << "��";
	cout << "��";
	gotoxy(95, 9);
	cout << "��      ��";
	gotoxy(95, 10);
	cout << "��   W  ��";
	gotoxy(95, 11);
	cout << "��      ��";
	gotoxy(88, 12);
	cout << "��";
	for (int i = 0; i < 20; i++) cout << "��";
	cout << "��";
	gotoxy(88, 13);
	cout << "��      ��      ��      ��";
	gotoxy(88, 14);
	cout << "��   A  ��   S  ��   D  ��";
	gotoxy(88, 15);
	cout << "��      ��      ��      ��";
	gotoxy(88, 16);
	cout << "��";
	for (int i = 0; i < 20; i++) cout << "��";
	cout << "��" << endl;
	gotoxy(94, 18);
	cout << "<  ����Ű >";
}
void printFrame()
{
	printKeyboard();

	int printY = 2;

	//��� �� ����ϱ�
	fstream binaryio("face.txt", ios::in | ios::binary);

	char buf[10000];

	if (binaryio.is_open()) {
		while (!binaryio.eof()) {
			binaryio.getline(buf, 10000);
			gotoxy(3, printY++);
			cout << buf << endl;
		}
	}
	else {
		cout << "������ ã�� �� �����ϴ�!" << endl;
	}

	binaryio.close();
}
int play(short& x, short& y, bubble fiveBubble[5])
{
	int start = (int)time(0);
	printFrame();
	makeBubble(fiveBubble);

	gotoxy(x, y);

	//�������� ���� ��ǰ�� ������ ���� ����
	int bubbleCount;

	do
	{
		bubbleCount = 0;

		wipeBubble(x, y, fiveBubble);
		printTime(start, x, y);

		for (int k = 0; k < 5; k++) {
			bubbleCount += fiveBubble[k].getErased();
		}
	} while (bubbleCount);		//�� ���ߴµ� 0�� �Ǹ� ���� ���߱�

	return printByeBye(start);
}