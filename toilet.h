#ifndef __IOSTREAM_H__
#define __IOSTREAM_H__
#include <iostream>
#endif

#ifndef __WASHFACEGAME_H__
#define __WASHFACEGAME_H__
#include "washFaceGame.h"
#endif

#ifndef __TEETHBRUSHGAME_H__
#define __TEETHBRUSHGAME_H__
#include "teethBrushGame.h"
#endif

#ifndef __DETACHTEARGAME_H__
#define __DETACHTEARGAME_H__
#include "detachTearGame.h"
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

#ifndef __SHAMPOOINGGAME_H__
#define __SHAMPOOINGGAME_H__
#include "shampooingGame.h"
#endif

using namespace std;


#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SUBMIT 5
#define HELP 7


void toiletBasicOutlineDraw(){
   system("cls");
   changeInit();
   imageDraw("ȭ��ǰ���.txt",0,0);
   imageDraw("ȭ��Ǽ���.txt",0,2);
   imageDraw("ȭ��Ǽ���.txt",470,2);
   imageDraw("ȭ��ǰ���.txt",0,277); 
   imageDraw("wasd100.txt",590,100);
   imageDraw("space100.txt",725,100);
   imageDraw("����Ű9.txt",615,150);
   imageDraw("����Ű9.txt",750,150);
}
void selectToiletOutlineDraw(){
   toiletBasicOutlineDraw();
   imageDraw("ȭ��ǰ���.txt",0,25);
   imageDraw("ȭ���10.txt",180,7);
   imageDraw("ȭ��ǰ���.txt",0,188);
}

void isItem2(int x, int y){
   
   imageDraw("ȭ��ǹ�.txt", 3, 100);
   //�Žǰ���
   if(5<=x && x<=10 && y>=118 && y<=154 ){
      imageDraw("�Ž��̵���Ʈ.txt",9,205);
   }
   //����, ����, ��ġ
   else if(130<=x && x<=270 && y<=94 && 88<=y ){
      imageDraw("����ȳ�1.txt",9,205);
      imageDraw("�Ӹ���������.txt",9,215);
     imageDraw("����˴ϴ�.txt",9,225);

   }
   //�Ӹ�����
   /*else if( 425<=x && x<=445 && y>=94 && y<=136){
      imageDraw("�Ӹ����Ӹ�Ʈ.txt",9,205);
   }*/
   //��ȭ ����
   else{
      imageDraw("�ȳ���Ʈ9.txt",9,205);
      imageDraw("�ȳ���Ʈ9.txt",40,215);
      imageDraw("�ȳ���Ʈ9.txt",9,215);
	  imageDraw("�ȳ���Ʈ9.txt",40,215);
	  imageDraw("�ȳ���Ʈ9.txt",9,225);
	  imageDraw("�ȳ���Ʈ9.txt",40,225);
   }
}
int isMiniGame2(int x, int y){

   //�ޱ��� ���� 1, ���� ����,���� ����,��ġ ���� 2, �Ӹ�������� 3, �Ž� ���� 4
   //ȭ��� ���� 5, �ʰ��� 6, ����ǰ ���� 7, �����ϱ� 8
   //-1�� �ƹ� �ϵ� �Ͼ�� �ʴ´�.

   //����, ����, ��ġ
   if(130<=x && x<=270 && y<=94 && 88<=y ){
      return 2;
   }
   //�Ӹ�����
   else if( 425<=x && x<=445 && y>=94 && y<=136){
      return 3;
   }
   //�Žǰ���
   else if(5<=x && x<=10 && y>=118 && y<=154 ){
      return 4;
   }
   //��ȭ ����
   else{
      return -1;
   }
   
}

void toiletDrawTile(int x, int y){

   int a = x/50;

   imageDraw("Ÿ��11.txt", a*50, 90);
   if(a != 6)
       imageDraw("Ÿ��11.txt", (a+1)*50, 90);

}

int toilet(int x, int y){

   system("cls");
   changeInit();
   selectToiletOutlineDraw();
 

   //�⺻ ��� ���
   /* for (int i = 0; i < 7; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         imageDraw("Ÿ��11.txt", (3 + i * 65), (28 + j * 32));
      }
   }*/
   imageDraw("Ÿ��12.txt", 0, 30);
   imageDraw("Ÿ��12.txt", 50, 30);
   imageDraw("Ÿ��12.txt", 100, 30);
   imageDraw("Ÿ��12.txt", 150, 30);
   imageDraw("Ÿ��12.txt", 200, 30);
   imageDraw("Ÿ��12.txt", 250, 30);
   imageDraw("Ÿ��12.txt", 300, 30);
   imageDraw("Ÿ��12.txt", 350, 30);
   imageDraw("Ÿ��12.txt", 400, 30);
   imageDraw("Ÿ��12.txt", 134, 60);
   imageDraw("Ÿ��12.txt", 200, 60);
   imageDraw("Ÿ��12.txt", 250, 60);
   imageDraw("Ÿ��12.txt", 300, 60);
   imageDraw("Ÿ��12.txt", 350, 60);
   imageDraw("Ÿ��12.txt", 400, 60);



   imageDraw("Ÿ��11.txt", 0, 90);
   imageDraw("Ÿ��11.txt", 50, 90);
   imageDraw("Ÿ��11.txt", 100, 90);
   imageDraw("Ÿ��11.txt", 150, 90);
   imageDraw("Ÿ��11.txt", 200, 90);
   imageDraw("Ÿ��11.txt", 250, 90);
   imageDraw("Ÿ��11.txt", 300, 90); //������� �̵� ���� 
   imageDraw("Ÿ��11.txt", 350, 90);
   imageDraw("Ÿ��11.txt", 400, 90);
   
   imageDraw("����5.txt", 3, 28);
   imageDraw("�����2.txt", 130, 28);
   imageDraw("����2.txt", 370, 28);
   imageDraw("ȭ��ǹ�.txt", 3, 100);


   //ĳ���� ���
    charImageDraw("��1.txt",x,y);

   int ch;
   bool up = true;
   bool down = true;
   bool left = true;
   bool right = true;
   bool help = true;
   while(true){
        ch = keyControl();
        if(ch == UP && (y>=94) && (help == true)){
           if(y==94){
         toiletDrawTile(x,y);
            isItem2(x,y);
             charImageDraw("��1.txt",x,y);
           }
          else if(up==true){
         toiletDrawTile(x,y);
            isItem2(x,y);
            charImageDraw("��2.txt",x,y-6);
            y -= 6;
            up = false;
          }
          else{
              toiletDrawTile(x,y);
           isItem2(x,y);
             charImageDraw("��1.txt",x,y-6);
            y -= 6;
            up = true;
          }
        }
        if(ch == DOWN && y<=154 && (help == true)){
          if(y==154){
              toiletDrawTile(x,y);
           isItem2(x,y);
             charImageDraw("��1.txt",x,y);
          }
          else if(down==true){
             toiletDrawTile(x,y);
          isItem2(x,y);
             charImageDraw("��2.txt",x,y+6);
            y += 6;
            down = false;
          }
          else{
              toiletDrawTile(x,y);
           isItem2(x,y);
             charImageDraw("��1.txt",x,y+6);
            y += 6;
            down = true;
          }
        }
        if(ch == LEFT && x>=5 && (help == true)){
           if (x==5){
             toiletDrawTile(x,y);
          isItem2(x,y);
             charImageDraw("��1.txt",x,y);
           }
         else if(left==true){
             toiletDrawTile(x,y);
          isItem2(x,y);
             charImageDraw("��2.txt",x-20,y);
            x -= 20;
            left = false;
          }
          else{
              toiletDrawTile(x,y);
           isItem2(x,y);
             charImageDraw("��1.txt",x-20,y);
            x -= 20;
            left = true;
          }
        }
        if(ch == RIGHT && x<=290 && (help == true)){
           if(x==290){
               toiletDrawTile(x,y);
            isItem2(x,y);
              charImageDraw("��1.txt",x,y);
           }
          else if(right==true){
              toiletDrawTile(x,y);
           isItem2(x,y);
             charImageDraw("��2.txt",x+20,y);
            x += 20;
            right = false;
          }
          else{
              toiletDrawTile(x,y);
           isItem2(x,y);
             charImageDraw("��1.txt",x+20,y);
            x += 20;
            right = true;
          }
        }
        if(ch==SUBMIT){
         int miniGame = isMiniGame2(x,y);
         //�ޱ��� ���� 1, ���� ����,���� ����,��ġ ���� 2, �Ӹ�������� 3, �Ž� ���� 4
         //ȭ��� ���� 5, �ʰ��� 6, ����ǰ ���� 7, �����ϱ� 8
         //-1�� �ƹ� �ϵ� �Ͼ�� �ʴ´�.
         if(miniGame != -1)
            return miniGame;
        }

    
   }
   
   
   gotoxy(500,500);


}


int toiletGame(int miniGameResult[], int season){
   
   //game[0]~[4]
   //�ޱ��� ����, ���� ����, ���� ����, ��ġ ����, �Ӹ�������� ��� (0=����, 1=����)

   changeInit();

   int miniGame;
   int mapX=5;
   int mapY = 130;

   while(true){
      //���� ����,���� ����,��ġ ���� 2, �Ӹ�������� 3, �Ž� ���� 4
      miniGame = toilet(mapX, mapY);
      if(miniGame==2){
         //����, ����, ��ġ
         miniGameResult[1] = washFaceGame();
         miniGameResult[2] = detachTearGame();
         miniGameResult[3] = teethBrushGame();
        miniGameResult[4] = shampooingGame(season);
         mapX=205;
         mapY=94;
      }
      else if(miniGame==4){
         //�Žǰ���
         system("cls");
         break;
      }
   }
   return 0;
}