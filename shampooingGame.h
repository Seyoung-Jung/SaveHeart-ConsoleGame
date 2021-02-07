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

#ifndef __DRAW_H__
#define __DRAW_H__
#include "Draw.h"
#endif


using namespace std;

int water = 0;
const int shampooX=0; //위치  
const int shampooY=0; //위치  
const int shampooWIDTH=50; //테두리 가로  
const int shampooHEIGHT=30; //테두리 세로  



void BaseDraw();
void Sucdraw();
void faildraw();
int playShampoo(int season);
void layout();
void shampooMainPrint();
void choice();
int shampooIntro();
void shampooKeyControl();
int shampooResult(int season);
void temporate();
void shampooResultlayout();


int shampooingGame(int season) {
	
	Init();
	int n = playShampoo(season);
	Sleep(1500);
	system("cls");
	return n;

}

int playShampoo(int season){
	
	layout();
	shampooMainPrint();
	system("cls");
	shampooIntro();
	system("cls");
	choice();
	int n = shampooResult(season);
	Sleep(2000);
	gotoxy(0,30);
	return n;

}


void shampooMainPrint(void){
   int i;
   int j;
    while (kbhit()) getch(); //버퍼에 있는 키값을 버림 

   
    gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+5,"┏-----------------------------┓");
    gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+6,"┣          Shampooing!        ┫");
    gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+7,"┗-----------------------------┛");
    
    gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+9," 《 PRESS ANY KEY TO START 》 ");
    while(1){

        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key=='e') exit(0); // ESC키면 종료 
            else break; //아니면 그냥 계속 진행 
        } 

        gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+9," 《 PRESS ANY KEY TO START 》 ");
        Sleep(400);
        gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+9,"                              ");
        Sleep(400);
    }
}

int shampooIntro(void){   
   int i,j; 
   layout();    //맵 테두리를 그림
   
   gotoxy(8,shampooY+8," 게임 설명: 현재 계절에 맞는 온도의 물을 선택해서 머리를 감아야 합니다.");
   gotoxy((shampooWIDTH/2)-10,shampooY+10,"       ※ 계절은 알 수 없습니다 ※");
   gotoxy((shampooWIDTH/2)-10,shampooY+12,"    ♥♡ 당신의 직감을 믿어보세요 ♡♥");
   gotoxy((shampooWIDTH/2)-13,shampooY+14,"(여름 : 차가운 물, 겨울 : 따뜻한 물, 봄과 가을 : 무관)");
   gotoxy((shampooWIDTH/2)-12,shampooY+16,"  -->게임을 시작하고 싶으시면 s를 눌러주세요<-- ");
   gotoxy(24,shampooY+18,"+---+ ");
   gotoxy(24,shampooY+19,"| s |");
   gotoxy(24,shampooY+20,"+---+");
   gotoxy(24,shampooY+21,"  ");
   
   char user;
   user=getch(); 
   while(user!='s'){
      gotoxy(16,22," 잘못된 입력입니다. 다시 입력해주세요  ");
      gotoxy(36,22,"");
      user=getch(); 
      if(user=='s')
         break;
   }
   
   return 0;
}

void choice() {
	
	char a;
	//layout();
	BaseDraw();
	gotoxy(24,24); 
	shampooKeyControl();
    a=getch(); 
    
    while(a!='y')
	 {
      gotoxy(40,26);
      cout << "바른 문자를 입력해주세요";
      a=getch(); 
      if(a=='y')
         break;
    }

}

int shampooResult(int season)
{
	system("cls");
	srand(time(0));
	layout();
	shampooResultlayout();
	
	
	//봄      0   -> -2, 2     
    //여름    1   -> -1, 3    
    //가을    2   -> 0, 4     
    //겨울    3   -> 1, 5      

	//water
    //뜨거운 물  -2
    //차가운 물   2 

	// 봄,가을 -> 무조건 성공
	// 여름 -> 차가운 물 성공
	// 겨울 -> 따뜻한 물 성공
	
	
	int score =0;
	
	score = season + water;
	
	gotoxy(21, 3, "<게임 결과>");
	
	gotoxy(65,8);
	cout <<"현재 계절 :   ";
	switch(season){
      case 0 : cout << "봄" ; break;
      case 1 : cout << "여름" ; break;
      case 2 : cout << "가을" ; break;
      case 3 : cout << "겨울" ;
     }
	gotoxy(65,10);
	cout<<"선택한 물 : "; 
	gotoxy(64,12);
	cout<<"      매치 : ";
	gotoxy(66,14);
	cout<<"---------------------";
	
	temporate();

	//봄      0   -> -2, 2     
    //여름    1   -> -1, 3    
    //가을    2   -> 0, 4     
    //겨울    3   -> 1, 5  
	
	if (score==3 || score==1)
	{ //성공 
        gotoxy(70,16);
        cout << "게 임 성 공";
        
        gotoxy(68,18);
        cout << "congraturation!";
        
        gotoxy(77,12);
	    cout<<"일치"; 
	   
	    if (season == 3)
		{

	   	    gotoxy(70,25);
	   	cout << "겨울엔 따뜻한 물이 최고야!";
	    }
	   
	    else if (season == 1)
		{

	   	    gotoxy(63,25);
	   	cout << "역시 여름엔 시원하게 씻어야지!";
	    }
	    
	   
	    Sucdraw();
	    return 1; //성공 
	}
    
    else if(score == -1 || score == 5 )    
	{ //실패 
		faildraw();
    	gotoxy(70,16);

        cout << "게 임 실 패";
        
        gotoxy(68,18);
        cout << "sorry to hear....";
        
        gotoxy(77,12);
	    cout<<"불일치"; 
        
		if (season == 3)
		{

	   	    gotoxy(64,25);
	   	cout << "겨울에 찬물이라니! 감기 걸리겠어";
	    }
	    
		else if (season == 1)
		{

	   	    gotoxy(64,25);
	   	cout << "이 여름에 뜨거운 물이라니....";
	    }
	    
	    
	    return 0; //실패 
	}
	
	if (season == 0 )
	{	Sucdraw();
		gotoxy(70,16);
        cout << "게 임 성 공";
        
        gotoxy(68,18);
        cout << "congraturation!";
        
        gotoxy(77,12);
	    cout<<"일치"; 
	   	gotoxy(64,25);
	   	cout << "봄엔 무슨 물이든 머리감기 딱 좋아!";
        
        return 1; 
	}
	
	if (season == 2 )
	{	Sucdraw();
		gotoxy(70,16);
        cout << "게 임 성 공";
        
        gotoxy(68,18);
        cout << "congraturation!";
        
        gotoxy(77,12);
	    cout<<"일치"; 
	   	gotoxy(70,25);
	   	cout << "으음~ 가을엔 무슨 물이든!";
        
        return 1;
	}
	 
}

void shampooResultlayout()
{
	gotoxy(31,6, "┌─────────────────────────┐");
	gotoxy(31,7, "┃"); gotoxy(44,7, "┃");
	gotoxy(31,8, "┃"); gotoxy(44,8, "┃");
	gotoxy(31,9, "┃"); gotoxy(44,9, "┃");
	gotoxy(31,10, "┃"); gotoxy(44,10, "┃");
	gotoxy(31,11, "┃"); gotoxy(44,11, "┃");
	gotoxy(31,12, "┃"); gotoxy(44,12, "┃");
	gotoxy(31,13, "┃"); gotoxy(44,13, "┃");
	gotoxy(31,14, "┃"); gotoxy(44,14, "┃");
	gotoxy(31,15, "┃"); gotoxy(44,15, "┃");
	gotoxy(31,16, "┃"); gotoxy(44,16, "┃");
	gotoxy(31,17, "┃"); gotoxy(44,17, "┃");
	gotoxy(31,18, "┃"); gotoxy(44,18, "┃");
	gotoxy(31,19, "┃"); gotoxy(44,19, "┃");
	gotoxy(31,20, "└─────────────────────────┘");
	
}

void temporate() 
{
	if (water == 2)
	{
		gotoxy(77,10);
		cout<<"차가운 물"; 
	}
	
	if (water == -2)
	{
		gotoxy(77,10);
		cout<<"뜨거운 물"; 
	}
}



void Sucdraw()
{
gotoxy(5,4,"             jEZ9Z9999Z8ZEj             ");
gotoxy(5,5,"         WZZZw            WZZZw         ");
gotoxy(5,6,"       9Z9                    ZZ9       ");
gotoxy(5,7,"     DZy                        yZ5     ");
gotoxy(5,8,"    ZZ                            ZZ    ");
gotoxy(5,9,"   Z                               ,Z   ");
gotoxy(5,10,"  Z      ZZZZ ZZZ5    yZZZ ZZZZ      Z  ");
gotoxy(5,11," Zj     WZZZZZZZZZ    ZZZZZZZZZy     yZ ");
gotoxy(5,12," Z       ZZZZZZZZ      ZZZZZZZZ       Z ");
gotoxy(5,13,"8         5ZZZZZ        ZZZZZB        yz");
gotoxy(5,14,"Z           ZZ           ,ZZ           Z");
gotoxy(5,15,"Z                                      Z");
gotoxy(5,16,"Z                                      Z");
gotoxy(5,17,"8W     BZ                      ZB     j8");
gotoxy(5,18," Z     BZZ                    ZZB     Z ");
gotoxy(5,19," Zj      ZZW                jZZ      WZ ");
gotoxy(5,20,"  Z       ZZZz            zZZZ       Z  ");
gotoxy(5,21,"   Z        9ZZZZZzjjzZZZZZE        Z   ");
gotoxy(5,22,"    ZZ         ,ZZZZZZZZ          ZZ    ");
gotoxy(5,23,"     BZj                        jZD     ");
gotoxy(5,24,"       EZ9                    EZE       ");
gotoxy(5,25,"         WZZZw            wZZZj         ");
gotoxy(5,26,"             5EZZEZEEEEZZ95             ");
               
}

void faildraw(){
gotoxy(5,4,"            jEE9E898z9E9ZEEj            ");
gotoxy(5,5,"         ZZZj              jZZZ         ");
gotoxy(5,6,"       ZZ                      ZZ       ");
gotoxy(5,7,"     ZZ                          ZZ     ");
gotoxy(5,8,"   wZ                              ZW   ");
gotoxy(5,9,"  DZ          z            ,        Z5  ");
gotoxy(5,10," 5Z         yZZZj        ZZZZ        Zy ");
gotoxy(5,11," Z          ZZZZZ        ZZZZj        Z ");
gotoxy(5,12,"zj          ZZZZZ        ZZZZD        5z");
gotoxy(5,13,"Z           ZZZZ5        ZZZZ          Z");
gotoxy(5,14,"Z            9Z5          ZZj          Z");
gotoxy(5,15,"Z            9Z5          ZZj          Z");
gotoxy(5,16,"Z               zZZZZZ9w               Z");
gotoxy(5,17,"Z           ZZZZZZZEZZZZZZZ            Z");
gotoxy(5,18,"9W        ZZZ5            ZZZW        W9");
gotoxy(5,19," Z      8ZZ                 ZZZ       Z ");
gotoxy(5,20," BZ    ZZZ                    ZZ     ZB ");
gotoxy(5,21,"  9Z   ZE                      ZZ   Z8  ");
gotoxy(5,22,"   5Z                              Z5   ");
gotoxy(5,23,"     BZj                        jZD     ");
gotoxy(5,24,"       EZ9                    EZE       ");
gotoxy(5,25,"         WZZZw            wZZZj         ");
gotoxy(5,26,"             5EZZEZEEEEZZ95             ");

}

void shampooKeyControl()
{
	char temp;
	while (true){
		temp = getch();
	
		if (temp == '2'){
			water -= 2; 
			cout << "뜨거운 물을 선택했습니다. 결과를 확인하려면 Y를  누르세요. ";
			break;
		}
	
		else if (temp == '1'){
			water += 2;
			cout << "차가운 물을 선택했습니다. 결과를 확인하려면 Y를 누르세요. ";
			break;
		}
	}
}

void layout(){
	
	cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";//5
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";//10
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";//15
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";//20
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";//25
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";//30
}

void BaseDraw(){
	cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                         <머리감기 게임>                                        ■\n";
	cout<<"■                                                                                                ■\n";//5
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                     ┌                    ┐           ┌                    ┐                    ■\n";
	cout<<"■                     │                    │           │                    │                    ■\n";
	cout<<"■                     │                    │           │                    │                    ■\n";//10
	cout<<"■                     │∽∽∽∽∽∽∽∽∽∽│           │∽∽∽∽∽∽∽∽∽∽│                    ■\n";
	cout<<"■                     │                    │           │                    │                    ■\n";
	cout<<"■                     │                    │           │                    │                    ■\n";
	cout<<"■                     │      차가운 물     │     or    │       뜨거운 물    │                    ■\n";
	cout<<"■                     │                    │           │                    │                    ■\n";//15
	cout<<"■                     │   (1을 누르세요)   │           │    (2를 누르세요)  │                    ■\n";
	cout<<"■                     │                    │           │                    │                    ■\n";
	cout<<"■                     └────────────────────┘           └────────────────────┘                    ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";//20
	cout<<"■             * 어떤 물로 머리를 감을까요?                     (현재 계절:알수없음)              ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";//25
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■                                                                                                ■\n";
	cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";//30
}