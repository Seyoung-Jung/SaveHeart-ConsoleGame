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
	
	imageDraw("���ι�.txt",66+63*10-10,27+22+50);
	imageDraw("���ι���.txt",66+63*10-50,27+22+52);
	imageDraw("���ι�.txt",66+63*3+10,27+22+75*2-5);
	imageDraw("���ι���.txt",66+63*3+25,27+22+75+45);
	imageDraw("ȭ��.txt",66+63*3+150,27+22+75+28);

	imageDraw("����.txt",240,30);
	imageDraw("â��.txt",390,27);
	imageDraw("����.txt",440,27);
	imageDraw("�ð�.txt",5,25);
	imageDraw("������2.txt",50,27+11);
	imageDraw("������1.txt",50+50,27+10);
	imageDraw("ħ��.txt",3,27+22+75);
	imageDraw("��ȭ��.txt",520,27+5);
	imageDraw("����.txt",570,27+10);
	
	//����ǰ ����
	if(x>=66 && x<=166 && y<=70 ){
		imageDraw("����ǰ�ȳ���Ʈ9.txt",9,205);
	}
	//�� ����
	else if(x>=406&&x<=466&& y==70 ){
		imageDraw("���Ա�ȳ���Ʈ9.txt",9,205);
	}
	//ȭ��� ����
	else if(x>=600 && x<=645 && y>=88 && y<=124 ){		
		imageDraw("ȭ���9.txt",9,205);
	}
	//���� �ϱ�
	else if(x>=246 && x<=346 && y>=160 && y<=166 ){	
		imageDraw("����9.txt",9,205);
	}
	else{
		imageDraw("�ȳ���Ʈ9.txt",9,205);
		imageDraw("�ȳ���Ʈ9.txt",9,215);
	}
}

int isMiniGame(int x, int y){

	//�ޱ��� ���� 1, ���� ���� ��ġ ���� 2, �Ӹ�������� 3 �Ž� ���� 4
	//ȭ��� ���� 5, �ʰ��� 6, ����ǰ ���� 7, �����ϱ� 8
	//-1�� �ƹ� �ϵ� �Ͼ�� �ʴ´�.

	//����ǰ ����
	if(x>=66 && x<=166 && y>=60 && y<=70 ){
		return 7;
	}
	//�� ����
	else if(x>=406&&x<=466&& y>=60 && y<=70 ){
		return 6;
	}
	//ȭ��� ����
	else if(x>=600 && x<=645 && y>=88 && y<=124 ){		
		return 5;
	}
	//���� �ϱ�
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
	imageDraw("����100.txt", 0, 0);
	imageDraw("����.txt", 0, 2);
	imageDraw("����.txt", 709, 2);
	imageDraw("����100.txt", 0, 277);
	imageDraw("wasd100.txt", 800, 100);
	imageDraw("space100.txt", 950, 100);
	imageDraw("����Ű9.txt", 825, 150);
	imageDraw("����Ű9.txt", 975, 150);
}

void tileDraw(int x, int y){
	int a = (x-66)/63;

	imageDraw("����5_�߰�2.txt",66+63*a,27+22+18);
	if(a!=9){
		imageDraw("����5_�߰�2.txt",66+63*(a+1),27+22+18);
	}
	if(y>124+6){
		imageDraw("����5_��.txt",66+63*(a),27+22+18+96);
		if(a!=9){
			imageDraw("����5_��.txt",66+63*(a+1),27+22+18+96);
		}
	}
}

int livingRoom(int x, int y, bool first){

	changeInit();
	selectClothesOutlineDraw();
	selectLivingOutLineDraw();

	imageDraw("����7_2.txt",3,27);
	imageDraw("����7_2.txt",66,27);
	imageDraw("����7_2.txt",66+63,27);
	imageDraw("����7_2.txt",66+63*2,27);
	imageDraw("����7_2.txt",66+63*3,27);
	imageDraw("����7_2.txt",66+63*4,27);
	imageDraw("����7_2.txt",66+63*5,27);
	imageDraw("����7_2.txt",66+63*6,27);
	imageDraw("����7_2.txt",66+63*7,27);
	imageDraw("����7_2.txt",66+63*8,27);
	imageDraw("����7_2.txt",66+63*9,27);


	
	imageDraw("����5_��.txt",3,27+22);
	imageDraw("����5_��.txt",66,27+22);
	imageDraw("����5_��.txt",66+63,27+22);
	imageDraw("����5_��.txt",66+63*2,27+22);
	imageDraw("����5_��.txt",66+63*3,27+22);
	imageDraw("����5_��.txt",66+63*4,27+22);
	imageDraw("����5_��.txt",66+63*5,27+22);
	imageDraw("����5_��.txt",66+63*6,27+22);
	imageDraw("����5_��.txt",66+63*7,27+22);
	imageDraw("����5_��.txt",66+63*8,27+22);
	imageDraw("����5_��.txt",66+63*9,27+22);

	imageDraw("����5_�߰�.txt",3,27+22+18);
	imageDraw("����5_�߰�2.txt",66,27+22+18);
	imageDraw("����5_�߰�2.txt",66+63,27+22+18);
	imageDraw("����5_�߰�2.txt",66+63*2,27+22+18);
	imageDraw("����5_�߰�2.txt",66+63*3,27+22+18);
	imageDraw("����5_�߰�2.txt",66+63*4,27+22+18);
	imageDraw("����5_�߰�2.txt",66+63*5,27+22+18);
	imageDraw("����5_�߰�2.txt",66+63*6,27+22+18);
	imageDraw("����5_�߰�2.txt",66+63*7,27+22+18);
	imageDraw("����5_�߰�2.txt",66+63*8,27+22+18);
	imageDraw("����5_�߰�.txt",66+63*9,27+22+18);

	imageDraw("����5_��.txt",66,27+22+18+96);
	imageDraw("����5_��.txt",66+63,27+22+18+96);
	imageDraw("����5_��.txt",66+63*2,27+22+18+96);
	imageDraw("����5_��.txt",66+63*3,27+22+18+96);
	imageDraw("����5_��.txt",66+63*4,27+22+18+96);
	imageDraw("����5_��.txt",66+63*5,27+22+18+96);
	imageDraw("����5_��.txt",66+63*6,27+22+18+96);
	imageDraw("����5_��.txt",66+63*7,27+22+18+96);
	imageDraw("����5_��.txt",66+63*8,27+22+18+96);

	imageDraw("���ι�.txt",66+63*10-10,27+22+50);
	imageDraw("���ι���.txt",66+63*10-50,27+22+52);
	imageDraw("���ι�.txt",66+63*3+10,27+22+75*2-5);
	imageDraw("���ι���.txt",66+63*3+25,27+22+75+45);
	imageDraw("ȭ��.txt",66+63*3+150,27+22+75+28);

	imageDraw("����.txt",240,30);
	imageDraw("â��.txt",390,27);
	imageDraw("����.txt",440,27);
	imageDraw("�ð�.txt",5,25);
	imageDraw("������2.txt",50,27+11);
	imageDraw("������1.txt",50+50,27+10);
	imageDraw("ħ��.txt",3,27+22+75);
	imageDraw("��ȭ��.txt",520,27+5);
	imageDraw("����.txt",570,27+10);

	int ch;

//	imageDraw("ĳ����2.txt",x,y);
	charImageDraw("��1.txt",x,y);
	if(first == true){
		imageDraw("ħ��9.txt",9,205);
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
			imageDraw("����100.txt",0,25);
			imageDraw("����7_2.txt",3,27);
			imageDraw("����7_2.txt",66,27);
			imageDraw("����7_2.txt",66+63,27);
			imageDraw("����7_2.txt",66+63*2,27);
			imageDraw("����7_2.txt",66+63*3,27);
			imageDraw("����7_2.txt",66+63*4,27);
			imageDraw("����7_2.txt",66+63*5,27);
			imageDraw("����7_2.txt",66+63*6,27);
			imageDraw("����7_2.txt",66+63*7,27);
			imageDraw("����7_2.txt",66+63*8,27);
			imageDraw("����7_2.txt",66+63*9,27);


	
			imageDraw("����5_��.txt",3,27+22);
			imageDraw("����5_��.txt",66,27+22);
			imageDraw("����5_��.txt",66+63,27+22);
			imageDraw("����5_��.txt",66+63*2,27+22);
			imageDraw("����5_��.txt",66+63*3,27+22);
			imageDraw("����5_��.txt",66+63*4,27+22);
			imageDraw("����5_��.txt",66+63*5,27+22);
			imageDraw("����5_��.txt",66+63*6,27+22);
			imageDraw("����5_��.txt",66+63*7,27+22);
			imageDraw("����5_��.txt",66+63*8,27+22);
			imageDraw("����5_��.txt",66+63*9,27+22);

			imageDraw("����5_�߰�.txt",3,27+22+18);
			imageDraw("����5_�߰�2.txt",66,27+22+18);
			imageDraw("����5_�߰�2.txt",66+63,27+22+18);
			imageDraw("����5_�߰�2.txt",66+63*2,27+22+18);
			imageDraw("����5_�߰�2.txt",66+63*3,27+22+18);
			imageDraw("����5_�߰�2.txt",66+63*4,27+22+18);
			imageDraw("����5_�߰�2.txt",66+63*5,27+22+18);
			imageDraw("����5_�߰�2.txt",66+63*6,27+22+18);
			imageDraw("����5_�߰�2.txt",66+63*7,27+22+18);
			imageDraw("����5_�߰�2.txt",66+63*8,27+22+18);
			imageDraw("����5_�߰�.txt",66+63*9,27+22+18);

			imageDraw("����5_��.txt",66,27+22+18+96);
			imageDraw("����5_��.txt",66+63,27+22+18+96);
			imageDraw("����5_��.txt",66+63*2,27+22+18+96);
			imageDraw("����5_��.txt",66+63*3,27+22+18+96);
			imageDraw("����5_��.txt",66+63*4,27+22+18+96);
			imageDraw("����5_��.txt",66+63*5,27+22+18+96);
			imageDraw("����5_��.txt",66+63*6,27+22+18+96);
			imageDraw("����5_��.txt",66+63*7,27+22+18+96);
			imageDraw("����5_��.txt",66+63*8,27+22+18+96);

			imageDraw("���ι�.txt",66+63*10-10,27+22+50);
			imageDraw("���ι���.txt",66+63*10-50,27+22+52);
			imageDraw("���ι�.txt",66+63*3+10,27+22+75*2-5);
			imageDraw("���ι���.txt",66+63*3+25,27+22+75+45);
			imageDraw("ȭ��.txt",66+63*3+150,27+22+75+28);

			imageDraw("����.txt",240,30);
			imageDraw("â��.txt",390,27);
			imageDraw("����.txt",440,27);
			imageDraw("�ð�.txt",5,25);
			imageDraw("������2.txt",50,27+11);
			imageDraw("������1.txt",50+50,27+10);
			imageDraw("ħ��.txt",3,27+22+75);
			imageDraw("��ȭ��.txt",520,27+5);
			imageDraw("����.txt",570,27+10);
			charImageDraw("��1.txt",x,y);
			imageDraw("thirdBlank.txt",3,205);imageDraw("thirdBlank.txt",200,210);
			help = true;
		  }
		continue;
	  }

      if(ch == UP && (y>=70) && (help == true)){
        if(y==70){
         isItem(x,y);
         charImageDraw("��1.txt",x,y);
        }
         else if(up==true && (help == true)){
            tileDraw(x,y);
         isItem(x,y);
         charImageDraw("��2.txt",x,y-6);
            y -= 6;
            up = false;
         }
         else if (help == true){
            tileDraw(x,y);
         isItem(x,y);
         charImageDraw("��1.txt",x,y-6);
            y -= 6;
            up = true;
         }
       
      }
      if(ch == DOWN && y<=166 && (help == true)){
       if(y==166){
          isItem(x,y);
         charImageDraw("��1.txt",x,y);
       }
         else if(down==true && (help == true)){
           tileDraw(x,y);
         isItem(x,y);
        charImageDraw("��2.txt",x,y+6);
            y += 6;
            down = false;
         }
         else if (help == true){
           tileDraw(x,y);
         isItem(x,y);
         charImageDraw("��1.txt",x,y+6);
            y += 6;
            down = true;
         }
      }
      if(ch == LEFT && x>=66 && (help == true)){
        if (x==66){
           isItem(x,y);
          charImageDraw("��1.txt",x,y);
        }
      else if(left==true && (help == true)){
          tileDraw(x,y);
         isItem(x,y);
         charImageDraw("��2.txt",x-20,y);
            x -= 20;
            left = false;
         }
         else if (help == true){
          tileDraw(x,y);
          isItem(x,y);
           charImageDraw("��1.txt",x-20,y);
         x -= 20;
            left = true;
         }
      }
      if(ch == RIGHT && x <= 625 && (help == true)){
        if(x==625){
           isItem(x,y);
           charImageDraw("��1.txt",x,y);
        }
         else if(right==true && (help == true)){
           tileDraw(x,y);
         isItem(x,y);
         charImageDraw("��2.txt",x+20,y);
            x += 20;
            right = false;
         }
         else if (help == true){
            tileDraw(x,y);
         isItem(x,y);
         charImageDraw("��1.txt",x+20,y);
            x += 20;
            right = true;
         }
      }
	  if(ch==SUBMIT){
		int miniGame = isMiniGame(x,y);
		//�ޱ��� ���� 1, ���� ����,���� ����,��ġ ���� 2, �Ӹ�������� 3, �Ž� ���� 4
		//ȭ��� ���� 5, �ʰ��� 6, ����ǰ ���� 7, �����ϱ� 8
		//-1�� �ƹ� �ϵ� �Ͼ�� �ʴ´�.
		if(miniGame != -1)
			return miniGame;
	  }
	  if(ch==QUIT)
		  return -100;

	   if(ch == HELP) {
		  if(help == true) {
			  help = false;
			  imageDraw("�����̹���580.txt",30,25);
			  imageDraw("blank.txt",7,205);
			  imageDraw("����9.txt",7,205);
		      imageDraw("����9.txt",25,205);
	          imageDraw("���򸻼���9.txt",7,220);
		  }
	   }
   }

	gotoxy(500,500);
	
}