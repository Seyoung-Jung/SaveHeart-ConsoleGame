#ifndef __IOSTREAM_H__
#define __IOSTREAM_H__
#include <iostream>
#endif

#ifndef __WINDOWS_H__
#define __WINDOWS_H__
#include <windows.h>
#endif

#ifndef __CONIO_H__
#define __CONIO_H__
#include <conio.h>
#endif


void ScreenInit();
void ScreenClear();
void ScreenFlipping();
void ScreenRelease();
void ScreenPrint(int x, int y, char *string);
void BufferPrint(int index, int x, int y, char *string);
void SetColor(unsigned short color);


static int g_nScreenIndex;
static HANDLE g_hScreen[2];


void ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	// ȭ�� ���� 2���� �����.
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);


	// Ŀ���� �����.
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);
}

void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 1200*300, Coor, &dw);
}

void ScreenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

void ScreenPrint(int x, int y, char *string)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

void BufferPrint(int index, int x, int y, char *string)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[index], CursorPosition);
	WriteFile(g_hScreen[index], string, strlen(string), &dw, NULL);
}

// 1 ~ 15 ���� ���� ���� ����
void SetColor(unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

void CImageDraw(char* name, int x,int y){
	char Buffer[1000];
	FILE *image = NULL;
	char a;
	string temp;
	fopen_s(&image, name, "r");
	//feof()�� ������ ���϶� 0�� �ƴ� ��(=��)�� ��ȯ
	while(!feof(image)){
		gotoxy(x,y++);
		fscanf(image,"%[^\n]s", Buffer);
		fscanf(image,"%c",&a);
		//temp = Buffer;
		ScreenPrint(x,y,Buffer);
	}

	fclose(image);
}

void charCImageDraw(const char* name, int x,int y){

	//       BBBB BBB \n
	//  �������� �ѱ��ھ� �ް� x++
	// _���� \n �������� �ް� ���, y++
	char Buffer[100];
	for(int i=0;i<100;i++){
		Buffer[i] = '.';
	}
	char Temp[1000];
	char front;
	char frontLine[500];
	FILE *image = NULL;
	char eol;
	char start;
	int tempX = x;
	fopen_s(&image, name, "r");
	bool first = false;
	if(image==NULL)
		return;

	//feof()�� ������ ���϶� 0�� �ƴ� ��(=��)�� ��ȯ
	
	while(!feof(image)){
		fscanf(image,"%[^\n]s", Buffer);
		fscanf(image,"%c",&eol);
		for(int i=0;i<100;i++){
			if(Buffer[i]=='.'){
				break;
			}
			if(first==false && Buffer[i] !='B'){
				tempX++;
			}
			else if(first==false && Buffer[i]=='B'){
				first = true;
				//gotoxy(tempX++,y);
				ScreenPrint(tempX++,y," ");
				//gotoxy(tempX++,y);
				ScreenPrint(tempX++,y," ");
				//gotoxy(tempX++,y);
				ScreenPrint(tempX++,y,&Buffer[i]);
			}
			else if(first==true){
				//gotoxy(tempX++,y);
				ScreenPrint(tempX++,y,&Buffer[i]);
			}
		}
		tempX = x;
		y++;
		first = false;
		for(int i=0;i<100;i++){
		Buffer[i] = '.';
		}
	}
	fclose(image);
}