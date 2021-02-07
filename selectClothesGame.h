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
using namespace std;

using namespace std;


int clothesMenuSelect(){
	
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

void selectClothesGame(Player& user){

	system("cls");

	int top = user.getClothes().intTop();
	int pants = user.getClothes().intPants();
	int shoes = user.getClothes().intShoes();

	while(1){
	selectClothesOutlineDraw();
	selectClothesMainMenuDraw();
	int n = clothesMenuSelect();
	switch(n){
		case 0: top = topDraw(); break;
		case 1: pants = pantsDraw(); break;
		case 2: shoes = shoesDraw(); break;
		case -1: user.setclothes(top,pants,shoes); 
		}
		if(n==-1)
			break;
	}
	imageDraw("clothesBlank.txt",7,205);

	string tt = user.getClothes().getTop() + "9.txt";
	string pp = user.getClothes().getPants() + "9.txt";
	string ss = user.getClothes().getShoes() + "9.txt";
	
	//밑 3줄 변경, 그리고 위 세줄 변수이름 수정
	const char* t = tt.c_str();
	const char* p = pp.c_str();
	const char* s = ss.c_str();
	
	imageDraw("당신은9.txt",7,205);

	imageDraw("상의9.txt",7,220);
	imageDraw("땡땡9.txt",50,220);
	imageDraw(t,80,220);

	imageDraw("하의9.txt",7,230);
	imageDraw("땡땡9.txt",50,230);
	imageDraw(p,80,230);

	imageDraw("신발9.txt",7,240);
	imageDraw("땡땡9.txt",50,240);
	imageDraw(s,80,240);

	imageDraw("입었다11.txt",7,255);

	Sleep(1000);
	system("cls");

}
