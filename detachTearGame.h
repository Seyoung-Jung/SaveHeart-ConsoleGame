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

const int MAP_X=0; //위치  
const int MAP_Y=0; //위치  
const int MAP_WIDTH=50; //테두리 가로  
const int MAP_HEIGHT=30;
char user;
int sumSuccess = 0;
int sumFail = 0;
int x = 30;
int y = 9;
int count=3;
int move();
void mainDetachPrint(void);
int intro();
void eyesGameFail(void);
void eyesGameSuccess(void);
int result();
void drawDetachMap(void);
int detachTearGame();

int detachTearGame(){
	Init();
    mainDetachPrint();
    return intro();
}

void drawDetachMap(void){ //맵 테두리 그리는 함수 
    int i,j;
    for(i=0;i<WIDTH;i++){
        gotoxy(X+i,Y,"■");
    }

    for(i=Y+1;i<Y+HEIGHT-1;i++){
        gotoxy(X,i,"■");
        gotoxy(X+WIDTH-1,i,"■");
    }

    for(i=0;i<WIDTH;i++){
        gotoxy(X+i,Y+HEIGHT-1,"■");
    }
}

void mainDetachPrint(){
	system("cls");
	int i,j;
    while (kbhit()) getch(); //버퍼에 있는 키값을 버림 
    drawDetachMap();    //맵 테두리를 그림
	for(i=MAP_Y+1;i<MAP_Y+MAP_HEIGHT-1;i++){ // 맵 테두리 안쪽을 빈칸으로 채움 
        for(j=MAP_X+1;j<MAP_X+MAP_WIDTH-1;j++) gotoxy(j,i,"  ");
    }
	
	gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+5,"┏-----------------------------┓");
    gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+6,"┣       A Tear In The Eye!    ┫");
    gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+7,"┗-----------------------------┛");
    
    gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+9," 《 PRESS ANY KEY TO START 》 ");
    while(1){

        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key=='e') exit(0); // ESC키면 종료 
            else break; //아니면 그냥 계속 진행 
        } 

        gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+9," 《 PRESS ANY KEY TO START 》 ");
        Sleep(400);
        gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+9,"                              ");
        Sleep(400);
    }
} 

int intro(){   
	int i,j; 
    drawDetachMap();    //맵 테두리를 그림
	for(i=MAP_Y+1;i<MAP_Y+MAP_HEIGHT-1;i++){ // 맵 테두리 안쪽을 빈칸으로 채움 
        for(j=MAP_X+1;j<MAP_X+MAP_WIDTH-1;j++) gotoxy(j,i,"  ");
    }
	gotoxy(MAP_X+5,MAP_Y+8," 게임 설명: 스페이스바를 이용하여 움직이는 막대가 눈의 위치에 있을때, ");
	gotoxy(MAP_X+10,MAP_Y+10,"   정확하게 스페이스바를 눌러 눈곱을 제거하는 게임입니다. ");
	gotoxy(MAP_X+10,MAP_Y+12,"     ♥♡도전 횟수 3번중 1번 이상 성공해야 합니다♡♥ ");
	gotoxy(MAP_X+10,MAP_Y+13,"                        〓〓 ");
	gotoxy(MAP_X+7,MAP_Y+14,"※막대가 정확히 눈을 가르켜야 하며 만약 코,입을 가르키며 실패하게 됩니다.※");
	gotoxy(MAP_X+(MAP_WIDTH/2)-13,MAP_Y+16," 	STOP키 :    스페이스바"); 
	gotoxy(MAP_X+(MAP_WIDTH/2)-13,MAP_Y+17," 	          ┕━━━━━━━━━━━┙");
	gotoxy(MAP_X+(MAP_WIDTH/2)-12,MAP_Y+19,"-->게임을 시작하고 싶으시면 s를 눌러주세요<-- ");
	gotoxy(MAP_X+(MAP_WIDTH/2)-2,MAP_Y+21,"+---+ ");
	gotoxy(MAP_X+(MAP_WIDTH/2)-2,MAP_Y+22,"| s |");
	gotoxy(MAP_X+(MAP_WIDTH/2)-2,MAP_Y+23,"+---+");
	gotoxy(MAP_X+(MAP_WIDTH/2)-2,MAP_Y+24,"  ");
	
	user=getch(); 
	while(user!='s'){
		gotoxy(MAP_X+13,MAP_Y+24," 잘못된 입력입니다. 다시 입력해주세요s  ");
		user=getch(); 
		if(user=='s')
			break;
	}
	int n = move();
	Sleep(2000);
	return n;
}
void eyesGameFail(void){
					 gotoxy(36,6,"남은횟수: /3");
		 			 gotoxy(40,6," ");
					 cout<<count; 
					 gotoxy(27,y,"실패");
					 Sleep(1000);
					 gotoxy(27,y,"   ");
					 //gotoxy(x,y," ");
}

void eyesGameSuccess(void){
					 gotoxy(36,6,"남은횟수: /3");
		 			 gotoxy(40,6," ");
					 cout<<count;
					 gotoxy(27,y,"성공");
					 Sleep(1000);
					 gotoxy(27,y,"   ");
					 //gotoxy(x,y," ");	
	
}
int result(){
					gotoxy(32,9,"┏━━━━━━  게임결과 ━━━━━━┓ ");
					gotoxy(32,10,"┃                       ┃");
					gotoxy(32,11,"┃     성공횟수:         ┃");
					gotoxy(32,12,"┃                       ┃");
					gotoxy(32,13,"┃     실패횟수:         ┃");
					gotoxy(32,14,"┃                       ┃");
					gotoxy(32,15,"┃                       ┃");
					//gotoxy(32,16,"┃   !!성공하셨습니다!!  ┃");
					gotoxy(32,17,"┃                       ┃");
					gotoxy(32,18,"┗━━━━━━━━━━━━━━━━━━━━━━━┛   ");
					gotoxy(40,11," ");
					cout<<sumSuccess;
					gotoxy(40,13," "); 
					cout<<sumFail;
					if(sumSuccess>=1){
						gotoxy(32,16,"┃   !!성공하셨습니다!!  ┃");
					}
					else{
						gotoxy(32,16,"┃   ㅠ실패하셨습니다ㅠ  ┃");
					}
		 			gotoxy(2,30," "); 

					if(sumSuccess>=1) //성공
						return 1;
					else //실패 
						return 0;
}


int move(){
    system("cls");
	x = 30;
	y = 9;
	drawMap();
	gotoxy(MAP_X+19,MAP_Y+2,"!!  A Tear In The Eye !!\n\n"); 
	gotoxy(MAP_X+17,MAP_Y+4," 	STOP키 :    스페이스바"); 
	gotoxy(MAP_X+17,MAP_Y+5," 	          ┕━━━━━━━━━━━┙");
	
	gotoxy(2,9,"               @@@@@@@@@@ ");                    
	gotoxy(2,10,"           @@@@@@@@@@@@@@@@");                  
	gotoxy(2,11,"        @@@@@@@@@@@@@@@@@@@@@");                 
	gotoxy(2,12,"      @@@@@@@@@@@@@@@@@@@@@@@@");              
	gotoxy(2,13,"    @@@@@@@@@@@@@@@@@@@@@@@@@@@@");           
	gotoxy(2,14,"    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@");            
	gotoxy(2,15,"   @@@@@@@@@@@@@@@@@@@  @@@@@@@@@");           
	gotoxy(2,16,"   @@@@@@@@@@@@@@@       @@@@@@@@");             
	gotoxy(2,17,"   @@@@@@@@               @@@@@@@");             
	gotoxy(2,18,"   @@@@@                   @@@@@@");           
	gotoxy(2,19,"  00  00      ●      ●    0  0");           
	gotoxy(2,20,"   0                          00");           
	gotoxy(2,21,"    00     ///    ⊂    ///   00");            
	gotoxy(2,22,"     00                      0");              
	gotoxy(2,23,"      00          ⌒       00");              
	gotoxy(2,24,"       000               00");              
	gotoxy(2,25,"        00000          000");                 
	gotoxy(2,26,"         000000000000000");
   
    gotoxy(MAP_X+25,MAP_Y+9,"┰");
    gotoxy(MAP_X+25,MAP_Y+10,"┃");
    gotoxy(MAP_X+25,MAP_Y+11,"┃");
    gotoxy(MAP_X+25,MAP_Y+12,"┃");
    gotoxy(MAP_X+25,MAP_Y+13,"┃");
    gotoxy(MAP_X+25,MAP_Y+14,"┃");
    gotoxy(MAP_X+25,MAP_Y+15,"┃");
    gotoxy(MAP_X+25,MAP_Y+16,"┃");
    gotoxy(MAP_X+25,MAP_Y+17,"┃");
    gotoxy(MAP_X+25,MAP_Y+18,"┃");
    gotoxy(MAP_X+25,MAP_Y+19,"★");
    gotoxy(MAP_X+25,MAP_Y+20,"┃");
    gotoxy(MAP_X+25,MAP_Y+21,"┃");
    gotoxy(MAP_X+25,MAP_Y+22,"┃");
    gotoxy(MAP_X+25,MAP_Y+23,"┃");
    gotoxy(MAP_X+25,MAP_Y+24,"┃");
    gotoxy(MAP_X+25,MAP_Y+25,"┃");
    gotoxy(MAP_X+25,MAP_Y+26,"┸");
	
	
	 
    
	while(1){
		   
       gotoxy(x,y,"☜"); //9
       Sleep(50);
       if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
			{
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
					 
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	}	 
        
		gotoxy(x,y++," "); //10
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{
					sumFail++; 
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n; 
					break;
				}
         	} 
    	} 
        
		gotoxy(x,y++," "); //11
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n; 
					break;
				}
         	} 
    	} 
    	
	    gotoxy(x,y++," "); //12
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
	  
	    gotoxy(x,y++," "); //13
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
        
	    gotoxy(x,y++," "); //14
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
     
        gotoxy(x,y++," "); //15
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
        gotoxy(x,y++," "); //16
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
        
		gotoxy(x,y++," "); //17
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y++," "); //18
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y++," "); //19
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameSuccess();
					 sumSuccess++;
				 }
				else{ 
					sumSuccess++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y++," "); //20
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y++," ");
        gotoxy(x,y,"☜ "); //21
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y++," "); //22
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n; 
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y++," "); //23
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y++," "); //24
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n; 
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y++," "); //25
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y++," "); //26
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
		 		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
        
		gotoxy(x,y--," "); //25
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
        gotoxy(x,y--," "); //24
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
        gotoxy(x,y--," "); //23
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
		
		gotoxy(x,y--," "); //22
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
        
		gotoxy(x,y--," "); //21
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
     
        gotoxy(x,y--," "); //20
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << " (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
			else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         } 
    	} 
        
	    gotoxy(x,y--," "); //19
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameSuccess();
					 sumSuccess++;
				 }
				else{ 
					sumSuccess++; 
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n; 
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //18
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //17
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n; 
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //16
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n; 
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //15
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //14
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //13
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //12
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n; 
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //11
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //10
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		//cout << "  (" << x << "," << y << ")";
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	} 
    	} 
    	
    	gotoxy(x,y--," "); //9
        gotoxy(x,y,"☜ ");
        Sleep(50);
        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
         		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n;
					break;
				}
         	}
    	} 
    	
    	gotoxy(x,y,"☜ "); 
        Sleep(50);
      	if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ')
         	{
           		if(count>1){
		 			 count--;
					 eyesGameFail();
					 sumFail++;
				 }
				else{ 
					sumFail++;
					gotoxy(40,6," ");
					count--;
					cout<<count;
					int n = result();
				    return n; 
					break;
				}
         	} 
    	} 
   }
}


	

