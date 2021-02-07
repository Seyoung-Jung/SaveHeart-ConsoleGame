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


//이동 위치 좌표
typedef struct point
{
	short x;
	short y;
} point;

typedef point* ppoint;

//미로 2차원 배열
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

//미로 생성
void SetMaze(ppoint player, ppoint start, ppoint end)
{
	start->x = 0;
	start->y = 0;
	end->x = 19;
	end->y = 19;
	player->x = 0;
	player->y = 0;
}



//콘솔 테두리 출력
void wakeUpPrintMargin()
{
	int x = 6, y = 2;
	gotoxy(x, y);
	cout << "┌";
	for (int i = 0; i < 80; i++) cout << "─";
	cout << "┐";
	for (int i = 1; i < 25; i++)
	{
		y++;
		gotoxy(x, y);
		cout << "│";
		x += 81;
		gotoxy(x, y);
		cout << "│";
		x = 6;
	}
	cout << endl;
	gotoxy(6, 27);
	cout << "└";
	for (int i = 0; i < 80; i++) cout << "─";
	cout << "┘" << endl;
}

//게임 시작 전 화면 출력
void wakeUpPrintWelcome()
{
	wakeUpPrintMargin();
	char next;
	gotoxy(37, 7);
	cout << "┌────────────────┐" << endl;
	gotoxy(37, 8);
	cout << "│   꿈깨기 게임  │" << endl;
	gotoxy(37, 9);
	cout << "└────────────────┘" << endl;
	gotoxy(10, 12);
	cout << "당신은 꿈에서 일어나야 합니다. 깨어나지 못할시, 호감도를 지킬 수 없습니다." << endl;
	gotoxy(34, 15);
	cout << "『 게임 방식 : 미로찾기 』" << endl;

	gotoxy(27, 18);
	cout << "w : 위   s : 아래  a : 왼쪽  d : 오른쪽" << endl;
	gotoxy(38, 20);
	cout << "제한 시간 : 20초" << endl;
	gotoxy(26, 24);
	cout << "【 준비가 되셨다면 s키를 누르세요.】  ";
	while(true){
		next = _getch();
		if (next == 's') {
			Init();
			return;
		}
	}
}

//키보드 그림 출력
void wakeUpwakeUpPrintKeyboard()
{
	gotoxy(62, 15);
	cout << "┌";
	for (int i = 0; i < 6; i++) cout << "─";
	cout << "┐";
	gotoxy(62, 16);
	cout << "│      │";
	gotoxy(62, 17);
	cout << "│   W  │";
	gotoxy(62, 18);
	cout << "│      │";
	gotoxy(55, 19);
	cout << "┌";
	for (int i = 0; i < 20; i++) cout << "─";
	cout << "┐";
	gotoxy(55, 20);
	cout << "│      │      │      │";
	gotoxy(55, 21);
	cout << "│   A  │   S  │   D  │";
	gotoxy(55, 22);
	cout << "│      │      │      │";
	gotoxy(55, 23);
	cout << "└";
	for (int i = 0; i < 20; i++) cout << "─";
	cout << "┘" << endl;
	gotoxy(61, 25);
	cout << "<  방향키 >";
}

//미로 출력
void PrintMaze(int maze[][20])
{
	wakeUpPrintMargin();
	int x = 10, y = 4; //콘솔 테두리 안에서 기준 좌표
	for (int i = 0; i < 20; i++)
	{
		gotoxy(x, y);
		for (int j = 0; j < 20; j++)
		{
			if (maze[i][j] == 0) //벽
				cout << "■";
			else if (maze[i][j] == 1) //길
				cout << "  ";
			else if (maze[i][j] == 2) //출발지
				cout << "★";
			else if (maze[i][j] == 3) //도착지
				cout << "☆";
		}
		cout << endl;
		y++;
	}
	gotoxy(x, y + 1);
	cout << "w : 위   s : 아래  a : 왼쪽  d : 오른쪽" << endl;

	wakeUpwakeUpPrintKeyboard();
}

//위치 이동
void wakeUpMovePlayer(int maze[20][20], ppoint player, char cinput)
{
	int x = 12, y = 4;
	switch (cinput)
	{
	case 'w': //위
		if ((player->y > 0) && maze[player->y - 1][player->x] !=0) //미로 끝이 아니고, 가고자 하는 방향이 뚫린 길이어야함
		{
			//미로문자가 2byte라 좌표*2
			//현재 좌표에서 커서로 2번 뒤로 가야 현재 위치에 2byte 출력 가능하다.
			gotoxy(x+2 * player->x-2, y+player->y); 
			cout << "  "; //현재 위치에 공백 출력
			--(player->y);
			gotoxy(x+2 * player->x-2, y+player->y);
			cout << "☆"; //이동한 위치에 별 출력
			gotoxy(x+2 * player->x-2, y+player->y); //커서가 현재 위치에 있어야 하므로 별 위치로 이동
		} break;

	case 's':  //아래
		if ((player->y < 20) && maze[player->y + 1][player->x] !=0)
		{
			gotoxy(x+2 * player->x-2,y+ player->y);
			cout << "  ";
			++(player->y);
			gotoxy(x+2 * player->x-2,y+ player->y);
			cout << "☆";
			gotoxy(x+2 * player->x - 2, y+player->y);
		} break;

	case 'a': //왼쪽
		if ((player->x > 0) && maze[player->y][player->x - 1] !=0)
		{
			gotoxy(x + 2 * player->x - 2, y + player->y);
			cout << "  ";
			--(player->x);
			gotoxy(x+2 * player->x-2, y+player->y);
			cout << "☆";
			gotoxy(x+2 * player->x - 2, y+player->y);
		} break;

	case 'd': //오른쪽
		if ((player->x < 20) && maze[player->y][player->x+1] !=0)
		{
			gotoxy(x+2 * player->x - 2, y+player->y);
			cout << "  ";
			++(player->x);
			//gotoxy(x+2 * player->x-2, y+player->y);
			cout << "☆";
			gotoxy(x+2 * player->x - 2, y+player->y);
		} break;
	}
}

//진행시간 출력
void wakeUpPrintTime(int start, short x, short y)
{
	int oldTime = (clock() - start)/1000;
	gotoxy(60, 10);
	cout << "【 " << oldTime << "초 경과 】";
	gotoxy(x, y);   //원래 위치로 돌아감
}

//게임 진행
int wakeUpPlayGame(ppoint player, ppoint end)
{
	int startTime = clock(); //타이머 시작

	while (true) //도착할때까지
	{
		char cinput = _getch();
		wakeUpMovePlayer(maze, player, cinput);
		wakeUpPrintTime(startTime, 12, 4);
		if (player->x == end->x && player->y == end->y) break; //도착
	}

	int endTime = clock(); //타이머 종료
	gotoxy(55, 13);
	if ((endTime - startTime )/1000< 20){
		cout << "『 꿈에서 깨어났습니다. 』" << endl;
		return 1;
	}
	else{
		cout << "『 꿈에서 깨어나지 못했습니다. 』" << endl;
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