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



#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif

#ifndef __UTIL_H__
#define __UTIL_H__
#include "util.h"
#endif

#ifndef __DRAW_H__
#define __DRAW_H__
#include "Draw.h"
#endif

using namespace std;


void isItem(int x, int y){
	
	imageDraw("세로문.txt",66+63*10-10,27+22+50);
	imageDraw("세로발판.txt",66+63*10-50,27+22+52);
	imageDraw("가로문.txt",66+63*3+10,27+22+75*2-5);
	imageDraw("가로발판.txt",66+63*3+25,27+22+75+45);
	imageDraw("화분.txt",66+63*3+150,27+22+75+28);

	imageDraw("액자.txt",240,30);
	imageDraw("창문.txt",390,27);
	imageDraw("옷장.txt",440,27);
	imageDraw("시계.txt",5,25);
	imageDraw("서랍장2.txt",50,27+11);
	imageDraw("서랍장1.txt",50+50,27+10);
	imageDraw("침대.txt",3,27+22+75);
	imageDraw("소화분.txt",520,27+5);
	imageDraw("의자.txt",570,27+10);
	
	//소지품 고르기
	if(x>=66 && x<=166 && y<=70 ){
		imageDraw("소지품안내멘트9.txt",9,205);
	}
	//옷 고르기
	else if(x>=406&&x<=466&& y==70 ){
		imageDraw("옷입기안내멘트9.txt",9,205);
	}
	//화장실 가기
	else if(x>=600 && x<=645 && y>=88 && y<=124 ){		
		imageDraw("화장실9.txt",9,205);
	}
	//외출 하기
	else if(x>=246 && x<=346 && y>=160 && y<=166 ){	
		imageDraw("외출9.txt",9,205);
	}
	else{
		imageDraw("안내멘트9.txt",9,205);
		imageDraw("안내멘트9.txt",9,215);
	}
}

int isMiniGame(int x, int y){

	//꿈깨기 게임 1, 세수 눈곱 양치 게임 2, 머리감기게임 3 거실 가기 4
	//화장실 가기 5, 옷고르기 6, 소지품 고르기 7, 외출하기 8
	//-1은 아무 일도 일어나지 않는다.

	//소지품 고르기
	if(x>=66 && x<=166 && y>=60 && y<=70 ){
		return 7;
	}
	//옷 고르기
	else if(x>=406&&x<=466&& y>=60 && y<=70 ){
		return 6;
	}
	//화장실 가기
	else if(x>=600 && x<=645 && y>=88 && y<=124 ){		
		return 5;
	}
	//외출 하기
	else if(x>=246 && x<=346 && y>=160 && y<=166 ){	
		return 8;
	}
	else{
		return -1;
	}
	
}

void roomBasicOutlineDraw() {
	system("cls");
	changeInit();
	imageDraw("가로100.txt", 0, 0);
	imageDraw("세로.txt", 0, 2);
	imageDraw("세로.txt", 709, 2);
	imageDraw("가로100.txt", 0, 277);
	imageDraw("wasd100.txt", 800, 100);
	imageDraw("space100.txt", 950, 100);
	imageDraw("방향키9.txt", 825, 150);
	imageDraw("선택키9.txt", 975, 150);
}

void tileDraw(int x, int y){
	int a = (x-66)/63;

	imageDraw("장판5_중간2.txt",66+63*a,27+22+18);
	if(a!=9){
		imageDraw("장판5_중간2.txt",66+63*(a+1),27+22+18);
	}
	if(y>124+6){
		imageDraw("장판5_밑.txt",66+63*(a),27+22+18+96);
		if(a!=9){
			imageDraw("장판5_밑.txt",66+63*(a+1),27+22+18+96);
		}
	}
}

int livingRoom(int x, int y, bool first){

	changeInit();
	selectClothesOutlineDraw();
	selectLivingOutLineDraw();

	imageDraw("장판7_2.txt",3,27);
	imageDraw("장판7_2.txt",66,27);
	imageDraw("장판7_2.txt",66+63,27);
	imageDraw("장판7_2.txt",66+63*2,27);
	imageDraw("장판7_2.txt",66+63*3,27);
	imageDraw("장판7_2.txt",66+63*4,27);
	imageDraw("장판7_2.txt",66+63*5,27);
	imageDraw("장판7_2.txt",66+63*6,27);
	imageDraw("장판7_2.txt",66+63*7,27);
	imageDraw("장판7_2.txt",66+63*8,27);
	imageDraw("장판7_2.txt",66+63*9,27);


	
	imageDraw("장판5_위.txt",3,27+22);
	imageDraw("장판5_위.txt",66,27+22);
	imageDraw("장판5_위.txt",66+63,27+22);
	imageDraw("장판5_위.txt",66+63*2,27+22);
	imageDraw("장판5_위.txt",66+63*3,27+22);
	imageDraw("장판5_위.txt",66+63*4,27+22);
	imageDraw("장판5_위.txt",66+63*5,27+22);
	imageDraw("장판5_위.txt",66+63*6,27+22);
	imageDraw("장판5_위.txt",66+63*7,27+22);
	imageDraw("장판5_위.txt",66+63*8,27+22);
	imageDraw("장판5_위.txt",66+63*9,27+22);

	imageDraw("장판5_중간.txt",3,27+22+18);
	imageDraw("장판5_중간2.txt",66,27+22+18);
	imageDraw("장판5_중간2.txt",66+63,27+22+18);
	imageDraw("장판5_중간2.txt",66+63*2,27+22+18);
	imageDraw("장판5_중간2.txt",66+63*3,27+22+18);
	imageDraw("장판5_중간2.txt",66+63*4,27+22+18);
	imageDraw("장판5_중간2.txt",66+63*5,27+22+18);
	imageDraw("장판5_중간2.txt",66+63*6,27+22+18);
	imageDraw("장판5_중간2.txt",66+63*7,27+22+18);
	imageDraw("장판5_중간2.txt",66+63*8,27+22+18);
	imageDraw("장판5_중간.txt",66+63*9,27+22+18);

	imageDraw("장판5_밑.txt",66,27+22+18+96);
	imageDraw("장판5_밑.txt",66+63,27+22+18+96);
	imageDraw("장판5_밑.txt",66+63*2,27+22+18+96);
	imageDraw("장판5_밑.txt",66+63*3,27+22+18+96);
	imageDraw("장판5_밑.txt",66+63*4,27+22+18+96);
	imageDraw("장판5_밑.txt",66+63*5,27+22+18+96);
	imageDraw("장판5_밑.txt",66+63*6,27+22+18+96);
	imageDraw("장판5_밑.txt",66+63*7,27+22+18+96);
	imageDraw("장판5_밑.txt",66+63*8,27+22+18+96);

	imageDraw("세로문.txt",66+63*10-10,27+22+50);
	imageDraw("세로발판.txt",66+63*10-50,27+22+52);
	imageDraw("가로문.txt",66+63*3+10,27+22+75*2-5);
	imageDraw("가로발판.txt",66+63*3+25,27+22+75+45);
	imageDraw("화분.txt",66+63*3+150,27+22+75+28);

	imageDraw("액자.txt",240,30);
	imageDraw("창문.txt",390,27);
	imageDraw("옷장.txt",440,27);
	imageDraw("시계.txt",5,25);
	imageDraw("서랍장2.txt",50,27+11);
	imageDraw("서랍장1.txt",50+50,27+10);
	imageDraw("침대.txt",3,27+22+75);
	imageDraw("소화분.txt",520,27+5);
	imageDraw("의자.txt",570,27+10);

	int ch;

//	imageDraw("캐릭터2.txt",x,y);
	charImageDraw("앞1.txt",x,y);
	if(first == true){
		imageDraw("침대9.txt",9,205);
	}
	bool up = true;
	bool down = true;
	bool left = true;
	bool right = true;
	bool help = true;
	while(true){
      ch = keyControl();

	  if(help==false){
		  if(ch == HELP){
			imageDraw("가로100.txt",0,25);
			imageDraw("장판7_2.txt",3,27);
			imageDraw("장판7_2.txt",66,27);
			imageDraw("장판7_2.txt",66+63,27);
			imageDraw("장판7_2.txt",66+63*2,27);
			imageDraw("장판7_2.txt",66+63*3,27);
			imageDraw("장판7_2.txt",66+63*4,27);
			imageDraw("장판7_2.txt",66+63*5,27);
			imageDraw("장판7_2.txt",66+63*6,27);
			imageDraw("장판7_2.txt",66+63*7,27);
			imageDraw("장판7_2.txt",66+63*8,27);
			imageDraw("장판7_2.txt",66+63*9,27);


	
			imageDraw("장판5_위.txt",3,27+22);
			imageDraw("장판5_위.txt",66,27+22);
			imageDraw("장판5_위.txt",66+63,27+22);
			imageDraw("장판5_위.txt",66+63*2,27+22);
			imageDraw("장판5_위.txt",66+63*3,27+22);
			imageDraw("장판5_위.txt",66+63*4,27+22);
			imageDraw("장판5_위.txt",66+63*5,27+22);
			imageDraw("장판5_위.txt",66+63*6,27+22);
			imageDraw("장판5_위.txt",66+63*7,27+22);
			imageDraw("장판5_위.txt",66+63*8,27+22);
			imageDraw("장판5_위.txt",66+63*9,27+22);

			imageDraw("장판5_중간.txt",3,27+22+18);
			imageDraw("장판5_중간2.txt",66,27+22+18);
			imageDraw("장판5_중간2.txt",66+63,27+22+18);
			imageDraw("장판5_중간2.txt",66+63*2,27+22+18);
			imageDraw("장판5_중간2.txt",66+63*3,27+22+18);
			imageDraw("장판5_중간2.txt",66+63*4,27+22+18);
			imageDraw("장판5_중간2.txt",66+63*5,27+22+18);
			imageDraw("장판5_중간2.txt",66+63*6,27+22+18);
			imageDraw("장판5_중간2.txt",66+63*7,27+22+18);
			imageDraw("장판5_중간2.txt",66+63*8,27+22+18);
			imageDraw("장판5_중간.txt",66+63*9,27+22+18);

			imageDraw("장판5_밑.txt",66,27+22+18+96);
			imageDraw("장판5_밑.txt",66+63,27+22+18+96);
			imageDraw("장판5_밑.txt",66+63*2,27+22+18+96);
			imageDraw("장판5_밑.txt",66+63*3,27+22+18+96);
			imageDraw("장판5_밑.txt",66+63*4,27+22+18+96);
			imageDraw("장판5_밑.txt",66+63*5,27+22+18+96);
			imageDraw("장판5_밑.txt",66+63*6,27+22+18+96);
			imageDraw("장판5_밑.txt",66+63*7,27+22+18+96);
			imageDraw("장판5_밑.txt",66+63*8,27+22+18+96);

			imageDraw("세로문.txt",66+63*10-10,27+22+50);
			imageDraw("세로발판.txt",66+63*10-50,27+22+52);
			imageDraw("가로문.txt",66+63*3+10,27+22+75*2-5);
			imageDraw("가로발판.txt",66+63*3+25,27+22+75+45);
			imageDraw("화분.txt",66+63*3+150,27+22+75+28);

			imageDraw("액자.txt",240,30);
			imageDraw("창문.txt",390,27);
			imageDraw("옷장.txt",440,27);
			imageDraw("시계.txt",5,25);
			imageDraw("서랍장2.txt",50,27+11);
			imageDraw("서랍장1.txt",50+50,27+10);
			imageDraw("침대.txt",3,27+22+75);
			imageDraw("소화분.txt",520,27+5);
			imageDraw("의자.txt",570,27+10);
			charImageDraw("앞1.txt",x,y);
			imageDraw("thirdBlank.txt",3,205);imageDraw("thirdBlank.txt",200,210);
			help = true;
		  }
		continue;
	  }

      if(ch == UP && (y>=70) && (help == true)){
        if(y==70){
         isItem(x,y);
         charImageDraw("뒤1.txt",x,y);
        }
         else if(up==true && (help == true)){
            tileDraw(x,y);
         isItem(x,y);
         charImageDraw("뒤2.txt",x,y-6);
            y -= 6;
            up = false;
         }
         else if (help == true){
            tileDraw(x,y);
         isItem(x,y);
         charImageDraw("뒤1.txt",x,y-6);
            y -= 6;
            up = true;
         }
       
      }
      if(ch == DOWN && y<=166 && (help == true)){
       if(y==166){
          isItem(x,y);
         charImageDraw("앞1.txt",x,y);
       }
         else if(down==true && (help == true)){
           tileDraw(x,y);
         isItem(x,y);
        charImageDraw("앞2.txt",x,y+6);
            y += 6;
            down = false;
         }
         else if (help == true){
           tileDraw(x,y);
         isItem(x,y);
         charImageDraw("앞1.txt",x,y+6);
            y += 6;
            down = true;
         }
      }
      if(ch == LEFT && x>=66 && (help == true)){
        if (x==66){
           isItem(x,y);
          charImageDraw("좌1.txt",x,y);
        }
      else if(left==true && (help == true)){
          tileDraw(x,y);
         isItem(x,y);
         charImageDraw("좌2.txt",x-20,y);
            x -= 20;
            left = false;
         }
         else if (help == true){
          tileDraw(x,y);
          isItem(x,y);
           charImageDraw("좌1.txt",x-20,y);
         x -= 20;
            left = true;
         }
      }
      if(ch == RIGHT && x <= 625 && (help == true)){
        if(x==625){
           isItem(x,y);
           charImageDraw("우1.txt",x,y);
        }
         else if(right==true && (help == true)){
           tileDraw(x,y);
         isItem(x,y);
         charImageDraw("우2.txt",x+20,y);
            x += 20;
            right = false;
         }
         else if (help == true){
            tileDraw(x,y);
         isItem(x,y);
         charImageDraw("우1.txt",x+20,y);
            x += 20;
            right = true;
         }
      }
	  if(ch==SUBMIT){
		int miniGame = isMiniGame(x,y);
		//꿈깨기 게임 1, 세수 게임,눈곱 게임,양치 게임 2, 머리감기게임 3, 거실 가기 4
		//화장실 가기 5, 옷고르기 6, 소지품 고르기 7, 외출하기 8
		//-1은 아무 일도 일어나지 않는다.
		if(miniGame != -1)
			return miniGame;
	  }
	  if(ch==QUIT)
		  return -100;

	   if(ch == HELP) {
		  if(help == true) {
			  help = false;
			  imageDraw("도움말이미지580.txt",30,25);
			  imageDraw("blank.txt",7,205);
			  imageDraw("땡땡9.txt",7,205);
		      imageDraw("도움말9.txt",25,205);
	          imageDraw("도움말설명9.txt",7,220);
		  }
	   }
   }

	gotoxy(500,500);
	
}