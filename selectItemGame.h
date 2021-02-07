#ifndef __UTIL_H__
#define __UTIL_H__
#include "util.h"
#endif

#ifndef __DRAW_H__
#define __DRAW_H__
#include "Draw.h"
#endif

#ifndef __CSTDIO_H__
#define __CSTIO_H__
#include <cstdio>
#endif
#ifndef __FSTREAM_H__
#define __FSTREAM_H__
#include <fstream>
#endif

#ifndef __WINDOWS_H__
#define __WINDOWS_H__
#include <windows.h>
#endif

#ifndef __CONIO_H__
#define __CONIO_H__
#include <conio.h>
#endif

#ifndef __PERSON_H__
#define __PERSON_H__
#include "Person.h"
#endif

#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif

#ifndef __ITEM_H__
#define __ITEM_H__
#include <Item.h>
#endif
using namespace std;

using namespace std;



int itemMenuSelect(){
	
//	>의 x,y 좌표
//	imageDraw("왼쪽화살표9.txt",50,150);
//	imageDraw("왼쪽화살표9.txt",270,150);
//	imageDraw("왼쪽화살표9.txt",500,150);
	int x=50;
	int y=150;

	while(true){
		//사용자가 입력한 값을 n으로(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//기존 '>' 지워주기
				//'>' 출력(270->50, 500->270)
				if(x==270){
					imageDraw("smallBlank.txt",270,150);
					imageDraw("왼쪽화살표9.txt",50,150);
					x=50;
				}
				else if(x==500){
					imageDraw("smallBlank.txt",500,150);
					imageDraw("왼쪽화살표9.txt",270,150);
					x=270;
				}
			
				break;
			}
			case RIGHT : {
				//기존 '>' 지워주기
				//'>' 출력(50->270, 270->500)
				if(x==50){
					imageDraw("smallBlank.txt",50,150);
					imageDraw("왼쪽화살표9.txt",270,150);
					x=270;
				}
				else if(x==270){
					imageDraw("smallBlank.txt",270,150);
					imageDraw("왼쪽화살표9.txt",500,150);
					x=500;
				}
			
				break;
			}
			case UP : {
				return -1; //뒤로 가기
			}
			case SUBMIT : {
				if(x==50) return 0;
				else if(x==270) return 1;
				else if(x==500) return 2;
			}
		}

	}
}

void selectItemsGame(Player& user){
	int index = 0;
	int weather = user.getItems().intWeather();
	int sense = user.getItems().intSense();
	int mood = user.getItems().intMood();

	while(1){
	selectItemsOutlineDraw();
	selectItemsMainMenuDraw();
	int n = itemMenuSelect();
	switch(n){
		case 0: weather = itemDraw1();index = 1;break;
		case 1: sense = itemDraw2(); index = 2; break;
		case 2: mood = itemDraw3(); index = 3;break;
		case -1: user.setitems(weather, sense, mood);
		}
		if(n==-1)
			break;
	}
	imageDraw("clothesBlank.txt",7,205);

	string tt = user.getItems().getWeather() + "9.txt";
	string pp = user.getItems().getSense() + "9.txt";
	string ss = user.getItems().getMood() + "9.txt";
	
	//밑 3줄 변경, 그리고 위 세줄 변수이름 수정
	const char* t = tt.c_str();
	const char* p = pp.c_str();
	const char* s = ss.c_str();
	
	imageDraw("당신은9.txt",7,205);

	imageDraw("소지품9.txt",7,220);
	
	if (index == 1){
	imageDraw(t,80,220);
	user.setitems(weather,-1,-1);
	}
	else if (index == 2){
    imageDraw(p,80,220);
	user.setitems(-1, sense, -1);
	}
	else if (index == 3){
    imageDraw(s,80,220);
	user.setitems(-1, -1, mood);
	}

	imageDraw("을10.txt",7,235);
    imageDraw("골랐다10.txt",70,235);
	Sleep(1000);
	system("cls");
}