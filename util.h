#ifndef __IOSTREAM_H__
#define __IOSTREAM_H__
#include <iostream>
#endif

#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif

#ifndef __CSTRING_H__
#define __CSTRING_H__
#include <cstring>
#endif

#ifndef __CSTDIO_H__
#define __CSTDIO_H__
#include <cstdio>
#endif

#ifndef __WINDOWS_H__
#define __WINDOWS_H__
#include <windows.h>
#endif

#ifndef __CONIO_H__
#define __CONIO_H__
#include <conio.h>
#endif

#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif

#ifndef __CSTDLIB_H__
#define __CSTDLIB_H__
#include<cstdlib>
#endif

#ifndef __CTIME_H__
#define __CTIME_H__
#include <ctime>
#endif

#ifndef __CLOTHES_H__
#define __CLOTHES_H__
#include "Clothes.h"
#endif


#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SUBMIT 5
#define QUIT 6
#define HELP 7
using namespace std;

void init(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO ConsoleCursor;
   ConsoleCursor.bVisible = 0;
   ConsoleCursor.dwSize = 1;
   SetConsoleCursorInfo(consoleHandle , &ConsoleCursor);
}

void gotoxy(int x,int y,char* s) { //x값을 2x로 변경, 좌표값에 바로 문자열을 입력할 수 있도록 printf 함수 삽입  
    COORD pos={2*x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    printf("%s",s);
}


void gotoxy(int x, int y){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
   COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
} 
void gotoxy(int x,int y,string s) { //x값을 2x로 변경, 좌표값에 바로 문자열을 입력할 수 있도록 printf 함수 삽입  
    COORD pos={2*x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<s;
}
void visibleCursor(){
	//커서 숨기기 기능
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	//false 또는 0 = 숨기기
	ConsoleCursor.bVisible = true; 
	ConsoleCursor.dwSize=1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

int keyControl(){
	// w
	//asd는 방향키, space 는 선택키로 설정

	//getch() = 엔터 입력하지 않아도 키 눌리면 바로 반환해주는 입력 함수
	//화면에 보여주지 않고 바로 반환
	//conio.h
	char temp = getch();

	if(temp == 'w' || temp == 'W'){
		return UP;
	}
	else if(temp == 'a' || temp == 'A'){
		return LEFT;
	}
	else if(temp == 's' || temp == 'S'){
		return DOWN;
	}
	else if(temp == 'd' || temp == 'D'){
		return RIGHT;
	}
	else if(temp == ' '){
		return SUBMIT;
	}
	else if(temp=='q' || temp == 'Q'){
		return QUIT;
	}
	else if(temp == 'h' || temp == 'H'){
		return HELP;
	}
	else
		return -1;
	
}

void fontSize(int size) {
	//콘솔 글씨 크기 변경 함수
	LOGFONT logfont; 
	GetObject(CreateFontW(size, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"FONT"), sizeof(logfont), &logfont);
	CONSOLE_FONT_INFOEX font_info = { sizeof(font_info), 0, logfont.lfWidth, logfont.lfHeight, 0, logfont.lfWeight, L"FONT" };
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &font_info);
}
void changeInit(){
	fontSize(1);
	system("mode con cols=1200 lines=300 | title 호감도를지켜라");

	//커서 숨기기 기능
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	//false 또는 0 = 숨기기
	ConsoleCursor.bVisible = 0; 
	ConsoleCursor.dwSize=1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void Init(){
	fontSize(16);
	system("mode con cols=120 lines=30 | title 호감도를지켜라");

	//커서 숨기기 기능
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	//false 또는 0 = 숨기기
	ConsoleCursor.bVisible = 0; 
	ConsoleCursor.dwSize=1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void introInit(){
   fontSize(5);
   system("mode con cols=1200 lines=300 | title 호감도를지켜라");

   //커서 숨기기 기능
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO ConsoleCursor;
   //false 또는 0 = 숨기기
   ConsoleCursor.bVisible = 0; 
   ConsoleCursor.dwSize=1;
   SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

