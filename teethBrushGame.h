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

const int X=0; //��ġ  
const int Y=0; //��ġ  
const int WIDTH=50; //�׵θ� ����  
const int HEIGHT=30; //�׵θ� ����  
const int size=46; //��� �ִ� ����  
char* blockArray[size]; //��Ͻױ� �迭  
char key; //��� �Է� Ű  
char userPick;//ó�� ���� ������ ��  
int countBlock=0; //���� ���� ���� ����  
//��� ���� 

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
//���� ���� 

void drawMap(void){ //�� �׵θ� �׸��� �Լ� 
    int i,j;
    for(i=0;i<WIDTH;i++){
        gotoxy(X+i,Y,"��");
    }

    for(i=Y+1;i<Y+HEIGHT-1;i++){
        gotoxy(X,i,"��");
        gotoxy(X+WIDTH-1,i,"��");
    }

    for(i=0;i<WIDTH;i++){
        gotoxy(X+i,Y+HEIGHT-1,"��");
    }
}
 
int game(){
	system("cls");
	drawMap();
	gotoxy(20,1,"!! Teeth Brushing !!\n\n"); 
	gotoxy(13,3,"..�����̽� �ٸ� ������ �ٷ� ������ �����մϴ�..\n\n");
	gotoxy(2,7,"+-------- 5------- 10------- 15------- 20------- 25------- 30------- 35------- 40------- 45+\n"); 
	gotoxy(25,4," ");
	char key=getch();
    if(key==' '){
		gotoxy(13,3,"              ..������ �����մϴ�..                          \n\n");
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
				blockArray[i]="��";
				cout<<blockArray[i];
				i++;
				countBlock++; 
				rightBrush();
				Sleep(100);
				removeRight();
		
		
				key=getch();
				gotoxy(x++,y,""); 
				blockArray[i]="��";
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
		gotoxy(13,3,"            ..������ �������ϴϴ�..                          \n\n");
		gotoxy(15,12," �ˢˢˢ�  ��      ��   �ˢˢˢˢ�");
		gotoxy(15,13," ��        �ˢ�    ��   �ˢ�     ��"); 
		gotoxy(15,14," �ˢˢˢ�  ��  ��  ��   �ˢ�     ��");
		gotoxy(15,15," ��        ��    �ˢ�   �ˢ�     ��");
		gotoxy(15,16," �ˢˢˢ�  ��      ��   �ˢˢˢˢ�");
		gotoxy(34,14,"�������������� �����Ӱ������������������");
		gotoxy(34,15,"��                         ��");
		gotoxy(34,16,"��                         ��");
		gotoxy(35,16,"�� ���� ���� ����: ");
		cout<<countBlock-1;
		gotoxy(34,17,"��                         ��");
		gotoxy(34,18,"��                         ��");
		gotoxy(35,18,"");
		printf("�� �ɸ��ð�: %f", result); //��� ���
		gotoxy(34,19,"��                         ��");
		gotoxy(34,20,"��                         ��");
		int n;
		if(result>15.0){
			gotoxy(36,20,"�ƽ����ϴ�. ���ФФ�");
		    n=0;
		}
		else{
			gotoxy(36,20,"�����մϴ�. ����! "); 
		    n=1;
		}
		gotoxy(34,21,"��                         ��");
		gotoxy(34,22,"������������������������������������������������������");
		gotoxy(0,31,""); 
		Sleep(2000);
		Sleep(1000);
		return n;
       
}
	
}

//���� ����  
int introTeeth(){   
	int i,j; 
    drawMap();    //�� �׵θ��� �׸�
	for(i=1;i<HEIGHT-1;i++){ // �� �׵θ� ������ ��ĭ���� ä�� 
        for(j=X+1;j<X+WIDTH-1;j++) gotoxy(j,i,"  ");
    }
	gotoxy((WIDTH/2)-13,Y+8," ���� ����: 15�� �ȿ� 45���� ����� ������ �˴ϴ�.");
	gotoxy((WIDTH/2)-13,Y+10," 	    �����̽��ٸ� ������ ����� ���Դϴ�");
	gotoxy((WIDTH/2)-13,Y+11," 	  �Ʀ���������������������������");
	gotoxy((WIDTH/2)-12,Y+3,"-->������ �����ϰ� �����ø� s�� �����ּ���<-- ");
	gotoxy((WIDTH/2)-2,Y+14,"+---+ ");
	gotoxy((WIDTH/2)-2,Y+15,"| s |");
	gotoxy((WIDTH/2)-2,Y+16,"+---+");
	gotoxy((WIDTH/2)-2,Y+17,"  ");
	
	userPick=getch(); 
	while(userPick!='s'){
		gotoxy(13,17," �߸��� �Է��Դϴ�. �ٽ� �Է����ּ���  ");
		userPick=getch(); 
		if(userPick=='s')
			break;
	}
	
	return game();
}



void mainPrint(void){
	int i,j;
    while (kbhit()) getch(); //���ۿ� �ִ� Ű���� ���� 
    drawMap();    //�� �׵θ��� �׸�
	for(i=Y+1;i<Y+HEIGHT-1;i++){ // �� �׵θ� ������ ��ĭ���� ä�� 
        for(j=X+1;j<X+WIDTH-1;j++) gotoxy(j,i,"  ");
    }
	
	gotoxy(X+(WIDTH/2)-7,Y+5,"��-----------------------------��");
    gotoxy(X+(WIDTH/2)-7,Y+6,"��        Teeth Brushing!      ��");
    gotoxy(X+(WIDTH/2)-7,Y+7,"��-----------------------------��");
    
    gotoxy(X+(WIDTH/2)-7,Y+9," �� PRESS ANY KEY TO START �� ");
    while(1){

        if(kbhit()){ //Ű�Է¹��� 
            char key=getch();
            if(key=='e') exit(0); // ESCŰ�� ���� 
            else break; //�ƴϸ� �׳� ��� ���� 
        } 

        gotoxy(X+(WIDTH/2)-7,Y+9," �� PRESS ANY KEY TO START �� ");
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
	
	gotoxy(18,12," �������������");
	gotoxy(18,13," �������������");
	gotoxy(18,14," �� ���� ��              ");
	gotoxy(18,15," �� ���� ��            ");
}

void rightBrush(){
	gotoxy(25,12," �������������");
	gotoxy(25,13," �������������");
	gotoxy(25,14," �� ���� ��              ");
	gotoxy(25,15," �� ���� ��              ");

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

