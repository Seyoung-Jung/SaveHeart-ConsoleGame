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
const int shampooX=0; //��ġ  
const int shampooY=0; //��ġ  
const int shampooWIDTH=50; //�׵θ� ����  
const int shampooHEIGHT=30; //�׵θ� ����  



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
    while (kbhit()) getch(); //���ۿ� �ִ� Ű���� ���� 

   
    gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+5,"��-----------------------------��");
    gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+6,"��          Shampooing!        ��");
    gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+7,"��-----------------------------��");
    
    gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+9," �� PRESS ANY KEY TO START �� ");
    while(1){

        if(kbhit()){ //Ű�Է¹��� 
            char key=getch();
            if(key=='e') exit(0); // ESCŰ�� ���� 
            else break; //�ƴϸ� �׳� ��� ���� 
        } 

        gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+9," �� PRESS ANY KEY TO START �� ");
        Sleep(400);
        gotoxy(shampooX+(shampooWIDTH/2)-7,shampooY+9,"                              ");
        Sleep(400);
    }
}

int shampooIntro(void){   
   int i,j; 
   layout();    //�� �׵θ��� �׸�
   
   gotoxy(8,shampooY+8," ���� ����: ���� ������ �´� �µ��� ���� �����ؼ� �Ӹ��� ���ƾ� �մϴ�.");
   gotoxy((shampooWIDTH/2)-10,shampooY+10,"       �� ������ �� �� �����ϴ� ��");
   gotoxy((shampooWIDTH/2)-10,shampooY+12,"    ���� ����� ������ �Ͼ���� ����");
   gotoxy((shampooWIDTH/2)-13,shampooY+14,"(���� : ������ ��, �ܿ� : ������ ��, ���� ���� : ����)");
   gotoxy((shampooWIDTH/2)-12,shampooY+16,"  -->������ �����ϰ� �����ø� s�� �����ּ���<-- ");
   gotoxy(24,shampooY+18,"+---+ ");
   gotoxy(24,shampooY+19,"| s |");
   gotoxy(24,shampooY+20,"+---+");
   gotoxy(24,shampooY+21,"  ");
   
   char user;
   user=getch(); 
   while(user!='s'){
      gotoxy(16,22," �߸��� �Է��Դϴ�. �ٽ� �Է����ּ���  ");
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
      cout << "�ٸ� ���ڸ� �Է����ּ���";
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
	
	
	//��      0   -> -2, 2     
    //����    1   -> -1, 3    
    //����    2   -> 0, 4     
    //�ܿ�    3   -> 1, 5      

	//water
    //�߰ſ� ��  -2
    //������ ��   2 

	// ��,���� -> ������ ����
	// ���� -> ������ �� ����
	// �ܿ� -> ������ �� ����
	
	
	int score =0;
	
	score = season + water;
	
	gotoxy(21, 3, "<���� ���>");
	
	gotoxy(65,8);
	cout <<"���� ���� :   ";
	switch(season){
      case 0 : cout << "��" ; break;
      case 1 : cout << "����" ; break;
      case 2 : cout << "����" ; break;
      case 3 : cout << "�ܿ�" ;
     }
	gotoxy(65,10);
	cout<<"������ �� : "; 
	gotoxy(64,12);
	cout<<"      ��ġ : ";
	gotoxy(66,14);
	cout<<"---------------------";
	
	temporate();

	//��      0   -> -2, 2     
    //����    1   -> -1, 3    
    //����    2   -> 0, 4     
    //�ܿ�    3   -> 1, 5  
	
	if (score==3 || score==1)
	{ //���� 
        gotoxy(70,16);
        cout << "�� �� �� ��";
        
        gotoxy(68,18);
        cout << "congraturation!";
        
        gotoxy(77,12);
	    cout<<"��ġ"; 
	   
	    if (season == 3)
		{

	   	    gotoxy(70,25);
	   	cout << "�ܿ￣ ������ ���� �ְ��!";
	    }
	   
	    else if (season == 1)
		{

	   	    gotoxy(63,25);
	   	cout << "���� ������ �ÿ��ϰ� �ľ����!";
	    }
	    
	   
	    Sucdraw();
	    return 1; //���� 
	}
    
    else if(score == -1 || score == 5 )    
	{ //���� 
		faildraw();
    	gotoxy(70,16);

        cout << "�� �� �� ��";
        
        gotoxy(68,18);
        cout << "sorry to hear....";
        
        gotoxy(77,12);
	    cout<<"����ġ"; 
        
		if (season == 3)
		{

	   	    gotoxy(64,25);
	   	cout << "�ܿ￡ �����̶��! ���� �ɸ��ھ�";
	    }
	    
		else if (season == 1)
		{

	   	    gotoxy(64,25);
	   	cout << "�� ������ �߰ſ� ���̶��....";
	    }
	    
	    
	    return 0; //���� 
	}
	
	if (season == 0 )
	{	Sucdraw();
		gotoxy(70,16);
        cout << "�� �� �� ��";
        
        gotoxy(68,18);
        cout << "congraturation!";
        
        gotoxy(77,12);
	    cout<<"��ġ"; 
	   	gotoxy(64,25);
	   	cout << "���� ���� ���̵� �Ӹ����� �� ����!";
        
        return 1; 
	}
	
	if (season == 2 )
	{	Sucdraw();
		gotoxy(70,16);
        cout << "�� �� �� ��";
        
        gotoxy(68,18);
        cout << "congraturation!";
        
        gotoxy(77,12);
	    cout<<"��ġ"; 
	   	gotoxy(70,25);
	   	cout << "����~ ������ ���� ���̵�!";
        
        return 1;
	}
	 
}

void shampooResultlayout()
{
	gotoxy(31,6, "������������������������������������������������������");
	gotoxy(31,7, "��"); gotoxy(44,7, "��");
	gotoxy(31,8, "��"); gotoxy(44,8, "��");
	gotoxy(31,9, "��"); gotoxy(44,9, "��");
	gotoxy(31,10, "��"); gotoxy(44,10, "��");
	gotoxy(31,11, "��"); gotoxy(44,11, "��");
	gotoxy(31,12, "��"); gotoxy(44,12, "��");
	gotoxy(31,13, "��"); gotoxy(44,13, "��");
	gotoxy(31,14, "��"); gotoxy(44,14, "��");
	gotoxy(31,15, "��"); gotoxy(44,15, "��");
	gotoxy(31,16, "��"); gotoxy(44,16, "��");
	gotoxy(31,17, "��"); gotoxy(44,17, "��");
	gotoxy(31,18, "��"); gotoxy(44,18, "��");
	gotoxy(31,19, "��"); gotoxy(44,19, "��");
	gotoxy(31,20, "������������������������������������������������������");
	
}

void temporate() 
{
	if (water == 2)
	{
		gotoxy(77,10);
		cout<<"������ ��"; 
	}
	
	if (water == -2)
	{
		gotoxy(77,10);
		cout<<"�߰ſ� ��"; 
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
			cout << "�߰ſ� ���� �����߽��ϴ�. ����� Ȯ���Ϸ��� Y��  ��������. ";
			break;
		}
	
		else if (temp == '1'){
			water += 2;
			cout << "������ ���� �����߽��ϴ�. ����� Ȯ���Ϸ��� Y�� ��������. ";
			break;
		}
	}
}

void layout(){
	
	cout<<"���������������������������������������������������\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";//5
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";//10
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";//15
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";//20
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";//25
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"���������������������������������������������������\n";//30
}

void BaseDraw(){
	cout<<"���������������������������������������������������\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                         <�Ӹ����� ����>                                        ��\n";
	cout<<"��                                                                                                ��\n";//5
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                     ��                    ��           ��                    ��                    ��\n";
	cout<<"��                     ��                    ��           ��                    ��                    ��\n";
	cout<<"��                     ��                    ��           ��                    ��                    ��\n";//10
	cout<<"��                     ������������廉           ������������廉                    ��\n";
	cout<<"��                     ��                    ��           ��                    ��                    ��\n";
	cout<<"��                     ��                    ��           ��                    ��                    ��\n";
	cout<<"��                     ��      ������ ��     ��     or    ��       �߰ſ� ��    ��                    ��\n";
	cout<<"��                     ��                    ��           ��                    ��                    ��\n";//15
	cout<<"��                     ��   (1�� ��������)   ��           ��    (2�� ��������)  ��                    ��\n";
	cout<<"��                     ��                    ��           ��                    ��                    ��\n";
	cout<<"��                     ��������������������������������������������           ��������������������������������������������                    ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";//20
	cout<<"��             * � ���� �Ӹ��� �������?                     (���� ����:�˼�����)              ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";//25
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"��                                                                                                ��\n";
	cout<<"���������������������������������������������������\n";//30
}