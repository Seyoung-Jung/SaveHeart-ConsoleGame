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

const int X=0; //위치  
const int Y=0; //위치  
const int WIDTH=50; //테두리 가로  
const int HEIGHT=30; //테두리 세로  
const int size=46; //블록 최대 높이  
char* blockArray[size]; //블록쌓기 배열  
char key; //블록 입력 키  
char userPick;//처음 게임 시작할 때  
int countBlock=0; //현재 쌓인 블럭의 갯수  
//블록 게임 

void mainPrint(void);
int game();
int introTeeth();
void gotoxy(int x,int y,char* s);
void removeLeft();
void removeRight();
void printBrush();
void leftBrush();
void rightBrush();
int teethBrushGame();
void drawMap(void);

int teethBrushGame(){
	mainPrint();
	int n =introTeeth();
	return n;
}
//게임 실행 

void drawMap(void){ //맵 테두리 그리는 함수 
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
 
int game(){
	system("cls");
	drawMap();
	gotoxy(20,1,"!! Teeth Brushing !!\n\n"); 
	gotoxy(13,3,"..스페이스 바를 누르면 바로 게임을 시작합니다..\n\n");
	gotoxy(2,7,"+-------- 5------- 10------- 15------- 20------- 25------- 30------- 35------- 40------- 45+\n"); 
	gotoxy(25,4," ");
	char key=getch();
    if(key==' '){
		gotoxy(13,3,"              ..게임을 시작합니다..                          \n\n");
		int i=0;
		time_t start, end;
    	double result;
    	gotoxy(2,7,"+-------- 5------- 10------- 15------- 20------- 25------- 30------- 35------- 40------- 45+\n");
    	printBrush();
    	int x=2; int y=8;
		gotoxy(2,8," ");
		start = time(NULL);
		
		while(countBlock<size-1){
				key=getch(); 
				if(key==' '){
				gotoxy(x++,y,"");
				blockArray[i]="■";
				cout<<blockArray[i];
				i++;
				countBlock++; 
				rightBrush();
				Sleep(100);
				removeRight();
		
		
				key=getch();
				gotoxy(x++,y,""); 
				blockArray[i]="■";
				cout<<blockArray[i];
				i++;
				countBlock++; 
				leftBrush(); 
				Sleep(100);
		 		removeLeft();	
				} 
				
		} 
		end = time(NULL);
		result = (double)(end - start);
		gotoxy(13,3,"            ..게임이 끝났습니니다..                          \n\n");
		gotoxy(15,12," ▦▦▦▦  ▦      ▦   ▦▦▦▦▦");
		gotoxy(15,13," ▦        ▦▦    ▦   ▦▦     ▦"); 
		gotoxy(15,14," ▦▦▦▦  ▦  ▦  ▦   ▦▦     ▦");
		gotoxy(15,15," ▦        ▦    ▦▦   ▦▦     ▦");
		gotoxy(15,16," ▦▦▦▦  ▦      ▦   ▦▦▦▦▦");
		gotoxy(34,14,"┏━━━━━━ 《게임결과》━━━━━━┓");
		gotoxy(34,15,"┃                         ┃");
		gotoxy(34,16,"┃                         ┃");
		gotoxy(35,16,"총 쌓인 블럭의 갯수: ");
		cout<<countBlock-1;
		gotoxy(34,17,"┃                         ┃");
		gotoxy(34,18,"┃                         ┃");
		gotoxy(35,18,"");
		printf("총 걸린시간: %f", result); //결과 출력
		gotoxy(34,19,"┃                         ┃");
		gotoxy(34,20,"┃                         ┃");
		int n;
		if(result>15.0){
			gotoxy(36,20,"아쉽습니다. 실패ㅠㅠ");
		    n=0;
		}
		else{
			gotoxy(36,20,"축하합니다. 성공! "); 
		    n=1;
		}
		gotoxy(34,21,"┃                         ┃");
		gotoxy(34,22,"┗━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		gotoxy(0,31,""); 
		Sleep(2000);
		Sleep(1000);
		return n;
       
}
	
}

//게임 설명  
int introTeeth(){   
	int i,j; 
    drawMap();    //맵 테두리를 그림
	for(i=1;i<HEIGHT-1;i++){ // 맵 테두리 안쪽을 빈칸으로 채움 
        for(j=X+1;j<X+WIDTH-1;j++) gotoxy(j,i,"  ");
    }
	gotoxy((WIDTH/2)-13,Y+8," 게임 설명: 15초 안에 45개의 블록을 쌓으면 됩니다.");
	gotoxy((WIDTH/2)-13,Y+10," 	    스페이스바를 누르면 블록이 쌓입니다");
	gotoxy((WIDTH/2)-13,Y+11," 	  ┕━━━━━━━━━━━━━┙");
	gotoxy((WIDTH/2)-12,Y+3,"-->게임을 시작하고 싶으시면 s를 눌러주세요<-- ");
	gotoxy((WIDTH/2)-2,Y+14,"+---+ ");
	gotoxy((WIDTH/2)-2,Y+15,"| s |");
	gotoxy((WIDTH/2)-2,Y+16,"+---+");
	gotoxy((WIDTH/2)-2,Y+17,"  ");
	
	userPick=getch(); 
	while(userPick!='s'){
		gotoxy(13,17," 잘못된 입력입니다. 다시 입력해주세요  ");
		userPick=getch(); 
		if(userPick=='s')
			break;
	}
	
	return game();
}



void mainPrint(void){
	int i,j;
    while (kbhit()) getch(); //버퍼에 있는 키값을 버림 
    drawMap();    //맵 테두리를 그림
	for(i=Y+1;i<Y+HEIGHT-1;i++){ // 맵 테두리 안쪽을 빈칸으로 채움 
        for(j=X+1;j<X+WIDTH-1;j++) gotoxy(j,i,"  ");
    }
	
	gotoxy(X+(WIDTH/2)-7,Y+5,"┏-----------------------------┓");
    gotoxy(X+(WIDTH/2)-7,Y+6,"┣        Teeth Brushing!      ┫");
    gotoxy(X+(WIDTH/2)-7,Y+7,"┗-----------------------------┛");
    
    gotoxy(X+(WIDTH/2)-7,Y+9," 《 PRESS ANY KEY TO START 》 ");
    while(1){

        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key=='e') exit(0); // ESC키면 종료 
            else break; //아니면 그냥 계속 진행 
        } 

        gotoxy(X+(WIDTH/2)-7,Y+9," 《 PRESS ANY KEY TO START 》 ");
        Sleep(400);
        gotoxy(X+(WIDTH/2)-7,Y+9,"                              ");
        Sleep(400);
    }
}
 
 void removeLeft(){
	gotoxy(18,12,"                         ");
	gotoxy(18,13,"                         ");
	gotoxy(18,14,"                         ");
	gotoxy(18,15,"                         ");
}

void removeRight(){
	gotoxy(25,12,"                         ");
	gotoxy(25,13,"                         ");
	gotoxy(25,14,"                         ");
	gotoxy(25,15,"                         ");
}
void leftBrush(){
	
	gotoxy(18,12," 〓〓〓〓〓〓〓〓〓〓〓〓");
	gotoxy(18,13," 〓〓〓〓〓〓〓〓〓〓〓〓");
	gotoxy(18,14," ∥ ∥∥ ∥              ");
	gotoxy(18,15," ∥ ∥∥ ∥            ");
}

void rightBrush(){
	gotoxy(25,12," 〓〓〓〓〓〓〓〓〓〓〓〓");
	gotoxy(25,13," 〓〓〓〓〓〓〓〓〓〓〓〓");
	gotoxy(25,14," ∥ ∥∥ ∥              ");
	gotoxy(25,15," ∥ ∥∥ ∥              ");

}

void printBrush(){
 
  gotoxy(15,18," *********");
 gotoxy(15,19,"*     *   *");
 gotoxy(15,20,"*         *");
 gotoxy(15,21,"*   **    *");
 gotoxy(15,22," * *  *  * ");
 gotoxy(15,23,"  **  *** ");
 gotoxy(21,18," *********");
 gotoxy(21,19,"*     *   *");
 gotoxy(21,20,"*         *");
 gotoxy(21,21,"*   **    *");
 gotoxy(21,22," * *  *  * ");
 gotoxy(21,23,"  **  *** ");
 gotoxy(27,18," *********");
 gotoxy(27,19,"*     *   *");
 gotoxy(27,20,"*         *");
 gotoxy(27,21,"*   **    *");
 gotoxy(27,22," * *  *  * ");
 gotoxy(27,23,"  **  *** ");
 
 gotoxy(5,12,"     @@@@@@@        ");
 gotoxy(5,13,"    @@@@@@@@@       ");
 gotoxy(5,14,"    @@@@@@@@@       ");
 gotoxy(5,15,"    @@@@@@@@@ @@ ");
 gotoxy(5,16,"      @@@@@   @@@ ");
 gotoxy(5,17,"   @@@@   @@@ @@@  ");
 gotoxy(5,18,"  @@@ @@@@@@@@@@@   ");
 gotoxy(5,19," @@@  @@@@@@        ");
 gotoxy(5,20," @@@ @@@@@@@        ");
 gotoxy(5,21,"      @@  @@  ");
 gotoxy(5,22,"      @    @  ");
 gotoxy(5,23,"      @@@  @@@  ");
}

