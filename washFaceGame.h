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

//거품의 좌표값과, 지워짐 여부 isErased로 구성
//생성자와 각 변수의 접근자, 설정자만 존재
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
int washFaceGame();	//게임 실행
void makeBubble(bubble fiveBubble[5]);	//거품 생성
		//커서를 (x, y)로 이동
void move(short& x, short& y);			//wsad 키를 이용하여 상하좌우 한 칸씩 이동
void wipeBubble(short& x, short& y, bubble bubble[5]);	//거품 닦기
short isBubble(short& x, short& y, bubble bubble[5]);	//거품 좌표 일치하는지 확인
void printTime(int start, short x, short y);			//시작부터 경과시간 출력
void printMargin();		//전체 틀 출력
void printWelcome();	//시작 화면 출력
int printByeBye(int start);	//종료 화면 출력
void printKeyboard();	//방향키 출력
void printFrame();	//기본 게임 틀 출력
int play(short& x, short& y, bubble fiveBubble[5]);	//게임 실행
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

	for (int i = 0; i < 5; i++)	//무작위로 다섯 개의 거품 찍기
	{
		short xp = rand() % 40 + 3;
		short yp = rand() % 24 + 1;

		//거품의 (x,y) 담아놓기
		fiveBubble[i].setX(xp);
		fiveBubble[i].setY(yp);

		//해당 위치로 커서 이동하여 거품 찍기
		gotoxy(xp, yp);
		cout << "●";
		gotoxy(xp + 2, yp);
		cout << "●";
		gotoxy(xp, yp + 1);
		cout << "●";
		gotoxy(xp + 2, yp + 1);
		cout << "●";
	}
}
void move(short& x, short& y)
{
	//문자 입력받기
	char temp = _getch();

	//얼굴 내에서만 커서 이동 가능
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
		//현재 좌표가 5개의 거품 중 하나와 일치하면, 거품을 지우고 해당 거품의 isErased를 0으로 바꾸기
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
	cout << "! " << oldTime << " ! 초 경과";
	gotoxy(x, y);	//원래 위치로 돌아감
}
void printMargin()
{
	int x = 0, y = 2;
	gotoxy(x, y);
	cout << "┌";
	for (int i = 0; i < 80; i++) cout << "─";
	cout << "┐";
	for (int i = 0; i < 27; i++)
	{
		y++;
		gotoxy(x, y);
		cout << "│";
		x = 81;
		gotoxy(x, y);
		cout << "│";
		x = 0;
	}
	cout << endl;
	gotoxy(0, 29);
	cout << "└";
	for (int i = 0; i < 80; i++) cout << "─";
	cout << "┘" << endl;
}
void printWelcome()
{
	gotoxy(29, 6);
	cout << "┌";
	for (int i = 0; i < 19; i++) cout << "─";
	cout << "┐";
	gotoxy(29, 7);
	cout << "│    세수하기 게임  │";
	gotoxy(29, 8);
	cout << "└";
	for (int i = 0; i < 19; i++) cout << "─";
	cout << "┘" << endl;
	gotoxy(35, 12);
	cout << "< 도움말 >";
	gotoxy(3, 14);
	cout << "이 게임은 제한 시간 내에 얼굴에 묻은 비누거품을 다 지우면 성공하는 게임입니다.";
	gotoxy(20, 16);
	cout << "방향키를 잘 조작하여 거품으로 이동하세요!";
	gotoxy(25, 18);
	cout << "방향키 : wasd로 상하좌우 이동";
	gotoxy(27, 22);
	cout << "시작하려면 s를 누르세요 !";
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

	cout << now << "초 걸리셨습니다.";

	gotoxy(45, 26);
	if (now <= 10){
		cout << "성공입니다. 축하해요...♥♡♥" << endl << endl;
		return 1;
	}
	else{
		cout << "실패입니다. 다음 기회에...♣♧♣" << endl << endl;
		return 0;
	}
}
void printKeyboard()
{
	gotoxy(95, 8);
	cout << "┌";
	for (int i = 0; i < 6; i++) cout << "─";
	cout << "┐";
	gotoxy(95, 9);
	cout << "│      │";
	gotoxy(95, 10);
	cout << "│   W  │";
	gotoxy(95, 11);
	cout << "│      │";
	gotoxy(88, 12);
	cout << "┌";
	for (int i = 0; i < 20; i++) cout << "─";
	cout << "┐";
	gotoxy(88, 13);
	cout << "│      │      │      │";
	gotoxy(88, 14);
	cout << "│   A  │   S  │   D  │";
	gotoxy(88, 15);
	cout << "│      │      │      │";
	gotoxy(88, 16);
	cout << "└";
	for (int i = 0; i < 20; i++) cout << "─";
	cout << "┘" << endl;
	gotoxy(94, 18);
	cout << "<  방향키 >";
}
void printFrame()
{
	printKeyboard();

	int printY = 2;

	//사람 얼굴 출력하기
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
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	binaryio.close();
}
int play(short& x, short& y, bubble fiveBubble[5])
{
	int start = (int)time(0);
	printFrame();
	makeBubble(fiveBubble);

	gotoxy(x, y);

	//지워지지 않은 거품의 갯수를 담을 변수
	int bubbleCount;

	do
	{
		bubbleCount = 0;

		wipeBubble(x, y, fiveBubble);
		printTime(start, x, y);

		for (int k = 0; k < 5; k++) {
			bubbleCount += fiveBubble[k].getErased();
		}
	} while (bubbleCount);		//다 더했는데 0이 되면 실행 멈추기

	return printByeBye(start);
}