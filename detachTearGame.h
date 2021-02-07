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

const int MAP_X=0; //��ġ  
const int MAP_Y=0; //��ġ  
const int MAP_WIDTH=50; //�׵θ� ����  
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

void drawDetachMap(void){ //�� �׵θ� �׸��� �Լ� 
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

void mainDetachPrint(){
	system("cls");
	int i,j;
    while (kbhit()) getch(); //���ۿ� �ִ� Ű���� ���� 
    drawDetachMap();    //�� �׵θ��� �׸�
	for(i=MAP_Y+1;i<MAP_Y+MAP_HEIGHT-1;i++){ // �� �׵θ� ������ ��ĭ���� ä�� 
        for(j=MAP_X+1;j<MAP_X+MAP_WIDTH-1;j++) gotoxy(j,i,"  ");
    }
	
	gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+5,"��-----------------------------��");
    gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+6,"��       A Tear In The Eye!    ��");
    gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+7,"��-----------------------------��");
    
    gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+9," �� PRESS ANY KEY TO START �� ");
    while(1){

        if(kbhit()){ //Ű�Է¹��� 
            char key=getch();
            if(key=='e') exit(0); // ESCŰ�� ���� 
            else break; //�ƴϸ� �׳� ��� ���� 
        } 

        gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+9," �� PRESS ANY KEY TO START �� ");
        Sleep(400);
        gotoxy(MAP_X+(MAP_WIDTH/2)-7,MAP_Y+9,"                              ");
        Sleep(400);
    }
} 

int intro(){   
	int i,j; 
    drawDetachMap();    //�� �׵θ��� �׸�
	for(i=MAP_Y+1;i<MAP_Y+MAP_HEIGHT-1;i++){ // �� �׵θ� ������ ��ĭ���� ä�� 
        for(j=MAP_X+1;j<MAP_X+MAP_WIDTH-1;j++) gotoxy(j,i,"  ");
    }
	gotoxy(MAP_X+5,MAP_Y+8," ���� ����: �����̽��ٸ� �̿��Ͽ� �����̴� ���밡 ���� ��ġ�� ������, ");
	gotoxy(MAP_X+10,MAP_Y+10,"   ��Ȯ�ϰ� �����̽��ٸ� ���� ������ �����ϴ� �����Դϴ�. ");
	gotoxy(MAP_X+10,MAP_Y+12,"     �������� Ƚ�� 3���� 1�� �̻� �����ؾ� �մϴ٢��� ");
	gotoxy(MAP_X+10,MAP_Y+13,"                        ��� ");
	gotoxy(MAP_X+7,MAP_Y+14,"�ظ��밡 ��Ȯ�� ���� �����Ѿ� �ϸ� ���� ��,���� ����Ű�� �����ϰ� �˴ϴ�.��");
	gotoxy(MAP_X+(MAP_WIDTH/2)-13,MAP_Y+16," 	STOPŰ :    �����̽���"); 
	gotoxy(MAP_X+(MAP_WIDTH/2)-13,MAP_Y+17," 	          �Ʀ�����������������������");
	gotoxy(MAP_X+(MAP_WIDTH/2)-12,MAP_Y+19,"-->������ �����ϰ� �����ø� s�� �����ּ���<-- ");
	gotoxy(MAP_X+(MAP_WIDTH/2)-2,MAP_Y+21,"+---+ ");
	gotoxy(MAP_X+(MAP_WIDTH/2)-2,MAP_Y+22,"| s |");
	gotoxy(MAP_X+(MAP_WIDTH/2)-2,MAP_Y+23,"+---+");
	gotoxy(MAP_X+(MAP_WIDTH/2)-2,MAP_Y+24,"  ");
	
	user=getch(); 
	while(user!='s'){
		gotoxy(MAP_X+13,MAP_Y+24," �߸��� �Է��Դϴ�. �ٽ� �Է����ּ���s  ");
		user=getch(); 
		if(user=='s')
			break;
	}
	int n = move();
	Sleep(2000);
	return n;
}
void eyesGameFail(void){
					 gotoxy(36,6,"����Ƚ��: /3");
		 			 gotoxy(40,6," ");
					 cout<<count; 
					 gotoxy(27,y,"����");
					 Sleep(1000);
					 gotoxy(27,y,"   ");
					 //gotoxy(x,y," ");
}

void eyesGameSuccess(void){
					 gotoxy(36,6,"����Ƚ��: /3");
		 			 gotoxy(40,6," ");
					 cout<<count;
					 gotoxy(27,y,"����");
					 Sleep(1000);
					 gotoxy(27,y,"   ");
					 //gotoxy(x,y," ");	
	
}
int result(){
					gotoxy(32,9,"��������������  ���Ӱ�� �������������� ");
					gotoxy(32,10,"��                       ��");
					gotoxy(32,11,"��     ����Ƚ��:         ��");
					gotoxy(32,12,"��                       ��");
					gotoxy(32,13,"��     ����Ƚ��:         ��");
					gotoxy(32,14,"��                       ��");
					gotoxy(32,15,"��                       ��");
					//gotoxy(32,16,"��   !!�����ϼ̽��ϴ�!!  ��");
					gotoxy(32,17,"��                       ��");
					gotoxy(32,18,"��������������������������������������������������   ");
					gotoxy(40,11," ");
					cout<<sumSuccess;
					gotoxy(40,13," "); 
					cout<<sumFail;
					if(sumSuccess>=1){
						gotoxy(32,16,"��   !!�����ϼ̽��ϴ�!!  ��");
					}
					else{
						gotoxy(32,16,"��   �н����ϼ̽��ϴ٤�  ��");
					}
		 			gotoxy(2,30," "); 

					if(sumSuccess>=1) //����
						return 1;
					else //���� 
						return 0;
}


int move(){
    system("cls");
	x = 30;
	y = 9;
	drawMap();
	gotoxy(MAP_X+19,MAP_Y+2,"!!  A Tear In The Eye !!\n\n"); 
	gotoxy(MAP_X+17,MAP_Y+4," 	STOPŰ :    �����̽���"); 
	gotoxy(MAP_X+17,MAP_Y+5," 	          �Ʀ�����������������������");
	
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
	gotoxy(2,19,"  00  00      ��      ��    0  0");           
	gotoxy(2,20,"   0                          00");           
	gotoxy(2,21,"    00     ///    ��    ///   00");            
	gotoxy(2,22,"     00                      0");              
	gotoxy(2,23,"      00          ��       00");              
	gotoxy(2,24,"       000               00");              
	gotoxy(2,25,"        00000          000");                 
	gotoxy(2,26,"         000000000000000");
   
    gotoxy(MAP_X+25,MAP_Y+9,"��");
    gotoxy(MAP_X+25,MAP_Y+10,"��");
    gotoxy(MAP_X+25,MAP_Y+11,"��");
    gotoxy(MAP_X+25,MAP_Y+12,"��");
    gotoxy(MAP_X+25,MAP_Y+13,"��");
    gotoxy(MAP_X+25,MAP_Y+14,"��");
    gotoxy(MAP_X+25,MAP_Y+15,"��");
    gotoxy(MAP_X+25,MAP_Y+16,"��");
    gotoxy(MAP_X+25,MAP_Y+17,"��");
    gotoxy(MAP_X+25,MAP_Y+18,"��");
    gotoxy(MAP_X+25,MAP_Y+19,"��");
    gotoxy(MAP_X+25,MAP_Y+20,"��");
    gotoxy(MAP_X+25,MAP_Y+21,"��");
    gotoxy(MAP_X+25,MAP_Y+22,"��");
    gotoxy(MAP_X+25,MAP_Y+23,"��");
    gotoxy(MAP_X+25,MAP_Y+24,"��");
    gotoxy(MAP_X+25,MAP_Y+25,"��");
    gotoxy(MAP_X+25,MAP_Y+26,"��");
	
	
	 
    
	while(1){
		   
       gotoxy(x,y,"��"); //9
       Sleep(50);
       if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� "); //21
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
        gotoxy(x,y,"�� ");
        Sleep(50);
        if(kbhit()){ //Ű�Է¹��� 
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
    	
    	gotoxy(x,y,"�� "); 
        Sleep(50);
      	if(kbhit()){ //Ű�Է¹��� 
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


	

