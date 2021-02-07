#ifndef __UTIL_H__
#define __UTIL_H__
#include "util.h"
#endif

#ifndef __WAKEUPGAME_H__
#define __WAKEUPGAME_H__
#include "wakeUpGame.h"
#endif

#ifndef __ITEM_H__
#define __ITEM_H__
#include "Item.h"
#endif

#ifndef __SELECTCLOTHESGAME_H__
#define __SELECTCLOTHESGAME_H__
#include "selectClothesGame.h"
#endif

#ifndef __SELECTITEMSGAME_H__
#define __SELECTCITEMGAME_H__
#include "selectItemGame.h"
#endif

#ifndef __CAFE_H__
#define __CAFE_H__
#include "Cafe.h"
#endif

#ifndef __LIVINGROOM_H__
#define __LIVINGROOM_H__
#include "LivingRoom.h"
#endif

#ifndef __DRAW_H__
#define __DRAW_H__
#include "Draw.h"
#endif

#ifndef __TOILET_H__
#define __TOILET_H__
#include "toilet.h"
#endif

#ifndef __INTROMAIN_H__
#define __INTROMAIN_H__
#include "introMain.h"
#endif

#ifndef __PERSON_H__
#define __PERSON_H__
#include "Person.h"
#endif

#ifndef __CLOTHES_H__
#define __CLOTHES_H__
#include "Clothes.h"
#endif

#ifndef __MUSIC_H__
#define __MUSIC_H__
#include "music.h"
#endif
using namespace std;



class Game{

   string level;
   string season;
   Player player;
   Person computer;
   int miniGameResult[5]; //�ޱ��� ����, ���� ����, ���� ����, ��ġ ����, �Ӹ�������� ��� (0=����, 1=����)
   int thirdStageBaseGame[3]; //�̸� ���߱� ����, ��� ����, ���ἱ��(Ŀ��/�ֽ�/��ȭ��) ��� (0=����, 1=����)
   int randGame[3]; //����, ��, ����, -1 ������� 0 ���� 1 ����
   int secondStageScore;
   int seasonNumber;

public:
   string miniGameName[5];
   string thirdStageBaseGameName[3];
   string randGameName[3];

   Game(){

      //��� ĳ���� ����
      srand(time(NULL));
      int computerName = rand()%4; //0,1,2,3
      int computerGender = rand()%2; //0,1

      if(computerName==0 && computerGender==0)
         computer = Person("������ �����", "����");
      else if(computerName==1 && computerGender==0)
         computer = Person("�����ο� �ŵ���", "����");
      else if(computerName==2 && computerGender==0)
         computer = Person("������ ��翬", "����");
      else if(computerName==3 && computerGender==0)
         computer = Person("�������� ������", "����");
      else if(computerName==0 && computerGender==1)
         computer = Person("������ �����", "����");
      else if(computerName==1 && computerGender==1)
         computer = Person("�����ο� �ŵ���", "����");
      else if(computerName==2 && computerGender==1)
         computer = Person("������ ��翬", "����");
      else if(computerName==3 && computerGender==1)
         computer = Person("�������� ������", "����");

      //���� ����
      int gameSeason= rand()%(4); //0,1,2,3
	  seasonNumber = gameSeason;
      switch(gameSeason){
      case 0 : season = "��" ; break;
      case 1 : season = "����" ; break;
      case 2 : season = "����" ; break;
      case 3 : season = "�ܿ�" ;
      }

	  

      //�迭 �ʱ�ȭ
      for(int i=0;i<5;i++){
         miniGameResult[i] = 0;
      }
      for(int i=0;i<3;i++){
         thirdStageBaseGame[i] = 0;
      }
      for(int i=0;i<3;i++){
         randGame[i] = -1;
      }
      miniGameName[0] = "�� ���� ����";
      miniGameName[1] = "�����ϱ� ����";
      miniGameName[2] = "���� ���� ����";
      miniGameName[3] = "��ġ ����";
      miniGameName[4] = "�Ӹ� ���� ����";
      thirdStageBaseGameName[0]="�̸� ���߱� ����";
      thirdStageBaseGameName[1]="��� ����";
      thirdStageBaseGameName[2]="����� ���� ���� ����";
      randGameName[0] = "���� ����";
      randGameName[1] = "�̺�Ʈ(��)";
      randGameName[2] = "�̺�Ʈ(��)";
      secondStageScore = 100;
   }

	string getSeason(){
		return season;
	}

	Player getPlayer(){
		return player;
	}

	Person getComputer(){
		return computer;
	}

	int *getMiniGameResult(){
		return miniGameResult;
	}

	int *getThirdStageBaseGame(){
		return thirdStageBaseGame;
	}

	int namePick(){ //�̸� ���߱�  ---��ȭ�� ���������� �����ϴ� �ǰ�..?
   
   gotoxy(3,210);
   imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);


   gotoxy(5,210);
   // "??? : �ȳ��ϼ���~ ���� �����̳׿� ����" == �̸����߱��λ�
   imageDraw("�̸����߱��λ�.txt",5,210);
   Sleep(1500);
   gotoxy(5,230);
   // ���� �̸��� ������? �� �����غ���.
   imageDraw("�̸����߱��λ�2.txt",5,230);
   Sleep(2000);

   gotoxy(3,210);
   // ĭ �ʱ�ȭ
   imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);

   

   gotoxy(5,210);
   // "1. �ȳ��ϼ���! ������ ����ߴ� ��������~?" == �̸����߱� 1
   imageDraw("�̸����߱�1.txt",5,210);
   gotoxy(5,225);
   // "2. �ȳ��ϼ���! �����ο� �ŵ����� ��������~?" == �̸����߱� 2
   imageDraw("�̸����߱�2.txt",5,225);
   gotoxy(5,237);
   // "3. �ȳ��ϼ���! ������ ��翬�� ��������~?" == �̸����߱� 3
   imageDraw("�̸����߱�3.txt",5,240);
   gotoxy(5,251);
   // "4. �ȳ��ϼ���! �������� �������� ��������~?" == �̸����߱� 4
   imageDraw("�̸����߱�4.txt",5,255);
      
   char temp;

   while(true){
      temp = getch();
      if(temp=='1' || temp=='2' || temp=='3' || temp =='4')
         break;
   }
   


   gotoxy(3,210);
   imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);
   // ĭ �ʱ�ȭ

   char temp2 = '0'; 
   int pick = temp - temp2;

   string pcName[4];
   pcName[0]="������ �����";
   pcName[1]="�����ο� �ŵ���";
   pcName[2]="������ ��翬";
   pcName[3]="�������� ������";

   string computerName = getComputer().getName();
   string selectName = pcName[pick-1];
      
   string npc = computerName + ".txt";
   string npcName = computerName + "2.txt";
   const char* Npc = npc.c_str();
   const char* NpcName = npcName.c_str();

   if(computerName == selectName){
      gotoxy(5,210);
      // ��ǻ�� �̸� : 
      imageDraw(Npc,3,210);
      gotoxy(100,210); //x�� ���� ����
      // �� �¾ƿ� ���������� == �̸����߱�5
      imageDraw("�̸����߱�5.txt",150,210);
      Sleep(1500);
      gotoxy(5,230);
      imageDraw("��������.txt",5,230);
      Sleep(1500);
      imageDraw("ȣ�������.txt",5,245);
      // �������� ������ �̸��� ���� �� ����. ȣ���� ���.
      getPlayer().setHeart(5); 
      Sleep(2000);
      imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);
      return 1;
   }
   else{
      gotoxy(3,210);
      // ��ǻ�� �̸� : 
      imageDraw(Npc,5,210);
      gotoxy(100,210); //x�� ���� ����
      // �ƴѵ�... �� �̸��� == �̸����߱�6
      imageDraw("�̸����߱�6.txt",150,210);
      gotoxy(40,210); //x�� ���� ����
      // ��ǻ�� �̸�
      imageDraw(NpcName,330,210);
      gotoxy(50,210); //x�� ���� ����
      // �Դϴ�. == �̸����߱�7
      imageDraw("�̸����߱�7.txt",480,210);
      Sleep(1500);
      gotoxy(5,230);
      imageDraw("ù������.txt",5,230);
      Sleep(1500);
      imageDraw("ȣ�����϶�.txt",5,245);
      // ��, ù������ �̷� �Ǽ���! ȣ���� �϶�.
      imageDraw(".txt",5,230);
      getPlayer().setHeart(-5);
      Sleep(2000);
      imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);
      return 0;
   }

   }

    int danceTime(){
		imageDraw("thirdBlank.txt",3,210);
		imageDraw("thirdBlank.txt",200,210);
		imageDraw("���߻�Ȳ�߻�.txt",5,210);
		Sleep(1000);
		imageDraw("ī�信�귯������.txt",5,230);
		imageDraw("�����Ǵ���.txt",5,242);
		Sleep(1500);
		imageDraw("thirdBlank.txt",3,210);
        imageDraw("thirdBlank.txt",200,210);
        imageDraw("thirdBlank.txt",260,210);

		// �̸� :
		string npc = getComputer().getName() + ".txt";
		string npcName = getComputer().getName() + "2.txt";
		const char* Npc = npc.c_str();
		const char* NpcName = npcName.c_str();
		imageDraw(Npc,5,210);
		imageDraw("�̳뷡.txt",200,210);
		imageDraw("�������.txt",5,230);
		Sleep(1500);
		imageDraw("thirdBlank.txt",3,210);
        imageDraw("thirdBlank.txt",200,210);
        imageDraw("thirdBlank.txt",260,210);

		if(player.stringItems()=="����ũ"){
			imageDraw("����ũ����.txt",5,210);
			imageDraw("��������.txt",5,225);
			Sleep(1500);
			imageDraw(NpcName,5,240);
			imageDraw("����ũ���غ��ؿ�.txt",200,240);
			imageDraw("ȣ�������.txt",5,255);
			Sleep(2000);
			imageDraw("thirdBlank.txt",3,210);
			imageDraw("thirdBlank.txt",200,210);
			imageDraw("thirdBlank.txt",260,210);
			player.setHeart(5);
			return 1;
		}
		else{
			imageDraw("����ũ����.txt",5,210);
			imageDraw("����������.txt",5,225);
			imageDraw("����ũ������.txt",5,240);
			Sleep(1500);
			imageDraw("�����ߴ�.txt",5,255);
			Sleep(2000);
			imageDraw("thirdBlank.txt",3,210);
			imageDraw("thirdBlank.txt",200,210);
			imageDraw("thirdBlank.txt",260,210);
			return 0;
		}

   }
   
   int quiz(){ // ��� ���� 


      imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);

       if(player.stringItems()=="�Ź�"){
         //����ǰ ����å�� ������ ���� ���� ����
         imageDraw("����ǰ�Ź�.txt",5,210);
         imageDraw("�����ұ��.txt",23,222);
         imageDraw("����.txt",5,240);

         char yes;
         while(true){
            yes = getch();
            if(yes=='y'||yes=='Y'){
               imageDraw("thirdBlank.txt",3,210);
               imageDraw("thirdBlank.txt",200,210);
               imageDraw("thirdBlank.txt",255,210);
				 getPlayer().setHeart(5);
               return 1;
            }
            if(yes=='N'||yes=='n')
               break;
         }

         imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);
      }

      srand((unsigned int)time(NULL));
      
      string computerName = getComputer().getName() ;
      string npc = computerName + ".txt";
      const char* Npc = npc.c_str();

      imageDraw(Npc,5,210);
      imageDraw("Ȥ�ýŹ�.txt",150,210); //x�� ���� ����
      // "Ȥ�� �Ź� ���� ���ó���? �Ź��� ������ ������ε� �ѹ� ���纸�Ƿ���?" == �������1
      Sleep(1300);

      /*
      quizSets[0]="Ȥ�� �ҷ������ �޲ٱ� ����, �߱� ����Ȳ�� ������� ���Ѽ� ã�� �ߴ�, �ڿ� ������ ���ϴ� �� ������ �̸��� �ƽó���?";//�������2
      quizSets[1]="Ȥ�� '�� �޸��翡���� �ȵȴ�'��� �̱������� �ǹ̷� ���Ǵ� �� �ƽó���? "; //�������3
      quizSets[2]="Ȥ�� �� ���� �� ������ ������ �ƴϾ��� ���� �ƽó���?";//�������4
      quizSets[3]="Ȥ�� ���� �� �ƽþư� �ƴ� ���� ����� �ƽó���?"; //�������5 
      */
        imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",255,210);

      int n = rand()%4;
      

      if(n==0){
         imageDraw(Npc,5,210);
         imageDraw("�ҷ����.txt",150, 210);
         imageDraw("�ڿ�����.txt",150,222);

         imageDraw("�������6.txt",5,232);
         // 1. �ҷ��� == �������6
         imageDraw("�������7.txt",5,247);
         // 2. ������ == �������7
         imageDraw("�������8.txt",5,262);
         // 3. �����Ϲ��� == �������8
         imageDraw("�������9.txt",150,262);
         // "(��Ʈ: ������ ���� �ֽ��ϴ�)") == �������9

         char temp;
         while(true){
            temp = getch();
            if(temp=='1' || temp=='2' || temp=='3' )
               break;
         }

         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",260,210);

         char temp2 = '0'; int pick = temp - temp2;
   
         if(pick==1){
            imageDraw(Npc,5,210);
            imageDraw("�ƽô±���.txt",150,210); //x�� ���� ����
            Sleep(1000);
            imageDraw("ȣ�������.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210);
            imageDraw("����1��.txt",150,210); 
            Sleep(1000);
            imageDraw("ȣ�����϶�.txt",5,230);
            // "��..�𸣽ñ���..���� 1�� '�ҷ���' �����..! ȣ������ -5 �϶��Ͽ����ϴ�." == �������11
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 0;
         }   

      }
      else if(n==1){
         imageDraw(Npc,5,210);
         imageDraw("���޸���.txt",150, 210);
         imageDraw("���Ǵ�.txt",150,222);

         imageDraw("�������12.txt",5,232);
         imageDraw("�������13.txt",5,247);
         imageDraw("�������14.txt",5,262);

         char temp;
         while(true){
            temp = getch();
            if(temp=='1' || temp=='2' || temp=='3' )
               break;
         }

         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",250,210);

         char temp2 = '0'; int pick = temp - temp2;
   
         if(pick==3){
            imageDraw(Npc,5,210);
            imageDraw("�ƽô±���.txt",150,210); //x�� ���� ����
            Sleep(1000);
            imageDraw("ȣ�������.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210);
            imageDraw("�����Ժ�.txt",150,210); 
            Sleep(1000);
            imageDraw("ȣ�����϶�.txt",5,230);
            // "��..�𸣽ñ���..���� 3�� '�Ժ�����' �̿����..! ȣ������ -5 �϶��Ͽ����ϴ�." == �������15
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 0;
         }   
      }
      else if(n==2){
         imageDraw("�������4.txt",5, 210);
         imageDraw("�������16.txt",5,230);
         // 1. �ҷ��� == �������6
         imageDraw("�������17.txt",5,245);
         // 2. ������ == �������7
         imageDraw("�������18.txt",5,260);

         char temp;
         while(true){
            temp = getch();
            if(temp=='1' || temp=='2' || temp=='3')
               break;
         }

         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);

         char temp2 = '0'; int pick = temp - temp2;
   
         if(pick==2){
            imageDraw(Npc,5,210);
            imageDraw("�ƽô±���.txt",150,210); //x�� ���� ����
            Sleep(1000);
            imageDraw("ȣ�������.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210);
            imageDraw("�������.txt",150,210); 
            Sleep(1000);
            imageDraw("ȣ�����϶�.txt",5,230);
            //"��..�𸣽ñ���..���� 2�� '���' �̿����..! ȣ������ -5 �϶��Ͽ����ϴ�." == �������19
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 0;
         }   
      }
      else if(n==3){
         imageDraw("�������5.txt",5, 210);
         imageDraw("�������20.txt",5,230);
         // 1. �ҷ��� == �������6
         imageDraw("�������21.txt",5,245);
         // 2. ������ == �������7
         imageDraw("�������22.txt",5,260);

         char temp;
         while(true){
            temp = getch();
            if(temp=='1' || temp=='2' || temp=='3' )
               break;
         }

         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);

         char temp2 = '0'; int pick = temp - temp2;
   
         if(pick==1){
            imageDraw(Npc,5,210);
            imageDraw("�ƽô±���.txt",150,210); //x�� ���� ����
            Sleep(1000);
            imageDraw("ȣ�������.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210);
            imageDraw("��������.txt",150,210); 
            Sleep(1000);
            imageDraw("ȣ�����϶�.txt",5,230);
            //"��..�𸣽ñ���..���� 1�� '���þ�' �̿����..! ȣ������ -5 �϶��Ͽ����ϴ�." == �������23
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 0;
         }   
      }

   }

   int drinkPick(){ //���ἱ�ð��� 
         
      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);

      srand((unsigned int)time(NULL));

      string drink[3]={"Ŀ��","�ֽ�","��ȭ��"};
      int n = rand()%3;

      string computerName = getComputer().getName() ;
      string npc = computerName + ".txt";
      const char* Npc = npc.c_str();


      // ��ǻ�� �̸� : 
      imageDraw(Npc,5,210);
      imageDraw("������.txt",150,210);
      imageDraw("����1.txt",150,222);

      Sleep(1500);

      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",230,210);

      imageDraw("������Ȱ���.txt",5,210);
      // ����� �Ȱ��� ���Ḧ ����!

      imageDraw("����2.txt",5,230);
      //"1.�� ���� Ŀ�ǿ�^^!" == ����2
      imageDraw("����3.txt",5,242);
      // 2.�� ���� �ֽ���^^!" == ����3
      imageDraw("����4.txt",5,254);
      // "3.�� ���� ��ȭ���̿�^^!" == ����4


      char temp;
      while(true){
         temp = getch();
         if(temp=='1' || temp=='2' || temp=='3')
            break;
      }

      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",230,210);

      char temp2 = '0'; int pick = temp - temp2;

       if(drink[pick-1]==drink[n]){
         imageDraw(Npc,5,210);
         imageDraw("����5.txt",150,210);
         //"��~! ���� ������ �Ȱ����ó׿䤾��" == ����5
         Sleep(1000);
         imageDraw("ȣ�������.txt",5,230);
         getPlayer().setHeart(5);
         Sleep(2000);
         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);
         return 1;
      }
      else{
         imageDraw(Npc,5,210);
         imageDraw("�����̵�Ư��.txt",150,210);
         Sleep(1000);
         imageDraw("ȣ�����϶�.txt",5,230);
         getPlayer().setHeart(-5);
         Sleep(2000);
         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);
         return 0;
      }
      }
   
   int gagPick(){ //���簳�� 
      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",230,210);


      if(player.stringItems()=="����å"){
         //����ǰ ����å�� ������ ���� ���� ����
         imageDraw("����ǰ����å.txt",5,210);
         imageDraw("�����ұ��.txt",23,222);
         imageDraw("����.txt",5,240);

         char yes;
         while(true){
            yes = getch();
            if(yes=='y'||yes=='Y'){
               imageDraw("thirdBlank.txt",3,210);
               imageDraw("thirdBlank.txt",200,210);
               imageDraw("thirdBlank.txt",255,210);
            getPlayer().setHeart(5);
               return 1;
            }
            if(yes=='N'||yes=='n')
               break;
         }

         imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);
      }

      srand((unsigned int)time(NULL));
      
      string quizSets[4];
      string computerName = getComputer().getName() ;
      string npc = computerName + ".txt";
      const char* Npc = npc.c_str();

      imageDraw("�����.txt",5,210);

      Sleep(1200);

      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",230,210);

      imageDraw(Npc,5,210);
      imageDraw("������.txt",150,210);
      imageDraw("�ѹ���.txt",150,222);

      Sleep(1200);

      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",230,210);

      /*
      quizSets[0]="Į�� �����ϸ�?!"; //����2
      quizSets[1]="�ٳ����� ������?! "; //����3
      quizSets[2]="3���� ���л��� ���� ������ �ƽó���?!";//����4
      quizSets[3]="�⸧�� ����Ǵµ� �󸶳� �ɸ����� �ƽó���?!";//����5
      */
      
      int n = rand()%4;

      if(n==0){
         imageDraw(Npc,5,210);
         imageDraw("����2.txt",150, 210);

         imageDraw("����6.txt",5,232);
         imageDraw("����7.txt",5,247);
         imageDraw("����8.txt",5,262);

         char temp;
         while(true){
            temp = getch();
            if(temp=='1' || temp=='2' || temp=='3' )
               break;
         }

         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);

         char temp2 = '0'; int pick = temp - temp2;
   
         if(pick==2){
            imageDraw(Npc,5,210); 
            imageDraw("����9.txt",150, 210);
            Sleep(1000);
            imageDraw("ȣ�������.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210); 
            imageDraw("����11.txt",150, 210);
            Sleep(1000);
            imageDraw("������.txt",5,230);
            Sleep(500);
            imageDraw("ȣ�����϶�.txt",5,242);
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 0;
         }   

      }

      else if(n==1){
         imageDraw(Npc,5,210);
         imageDraw("����3.txt",150, 210);

         imageDraw("����12.txt",5,232);
         imageDraw("����13.txt",5,247);
         imageDraw("����14.txt",5,262);

         char temp;
         while(true){
            temp = getch();
            if(temp=='1' || temp=='2' || temp=='3' )
               break;
         }

         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);

         char temp2 = '0'; int pick = temp - temp2;
   
         if(pick==1){
            imageDraw(Npc,5,210); 
            imageDraw("����9.txt",150, 210);
            Sleep(1000);
            imageDraw("ȣ�������.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210); 
            imageDraw("����15.txt",150, 210);
            Sleep(1000);
            imageDraw("������.txt",5,230);
            Sleep(500);
            imageDraw("ȣ�����϶�.txt",5,242);
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 0;
         }   
      }
      else if(n==2){
         imageDraw(Npc,5,210);
         imageDraw("����4.txt",150, 210);

         imageDraw("����16.txt",5,232);
         imageDraw("����17.txt",5,247);
         imageDraw("����18.txt",5,262);

         char temp;
         while(true){
            temp = getch();
            if(temp=='1' || temp=='2' || temp=='3' )
               break;
         }

         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);

         char temp2 = '0'; int pick = temp - temp2;
   
         if(pick==3){
            imageDraw(Npc,5,210); 
            imageDraw("����9.txt",150, 210);
            Sleep(1000);
            imageDraw("ȣ�������.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210); 
            imageDraw("����19.txt",150, 210);
            Sleep(1000);
            imageDraw("������.txt",5,230);
            Sleep(500);
            imageDraw("ȣ�����϶�.txt",5,242);
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 0;
         }   
      }
      else if(n==3){ 
         imageDraw(Npc,5,210);
         imageDraw("����5.txt",150, 210);

         imageDraw("����20.txt",5,232);
         imageDraw("����21.txt",5,247);
         imageDraw("����22.txt",5,262);

         char temp;
         while(true){
            temp = getch();
            if(temp=='1' || temp=='2' || temp=='3' )
               break;
         }

         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);

         char temp2 = '0'; int pick = temp - temp2;
   
         if(pick==2){
            imageDraw(Npc,5,210); 
            imageDraw("����9.txt",150, 210);
            Sleep(1000);
            imageDraw("ȣ�������.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210); 
            imageDraw("����23.txt",150, 210);
            Sleep(1000);
            imageDraw("������.txt",5,230);
            Sleep(500);
            imageDraw("ȣ�����϶�.txt",5,242);
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 0;
         }   
      }
    }
 
   void ConversationListDraw(int* rand, int* complete){

       imageDraw("������ȭ��������������.txt",5,210);

        if(rand[1] == 1){
         if(complete[1]==-1){
            gotoxy(3,222); 
            //,"2.  ��� ���� "); //�޴�2
            imageDraw("1.�������.txt",5,230);
         }
         if(complete[2]==-1){
            gotoxy(3,234); 
            //"3.  ����� ���� ���� ����"); //�޴�3
            imageDraw("2.��������ἱ�ð���.txt",200,230);
         }
         if(complete[3]==-1){
            gotoxy(3,246);
            //"4.  ���簳��"); //�޴�4
            imageDraw("3.���簳��.txt",5,245);
         }
         if(complete[4]==-1){
            gotoxy(3,258);
            //"5.  ��ȭ�� ��ģ��."); //�޴�5
            imageDraw("4.��ȭ����ģ��.txt",200,245);
         }
        }
        else{
         if(complete[1]==-1){
            gotoxy(3,222); 
            //,"2.  ��� ���� "); //�޴�2
            imageDraw("1.�������.txt",5,230);
         }
         if(complete[2]==-1){
            gotoxy(3,234); 
            //"3.  ����� ���� ���� ����"); //�޴�3
            imageDraw("2.��������ἱ�ð���.txt",5,245);
         }
         if(complete[4]==-1){
            gotoxy(3,258);
            //"5.  ��ȭ�� ��ģ��."); //�޴�5
            imageDraw("3.��ȭ����ģ��.txt",5,260);
         }
        }


      }

   void conversation(){// ������ ����

      srand((unsigned int)time(NULL)); 
      //int randGame[3]; //����, ��, ����

      //�̸� ���߱� ����, ��� ����, ����� ���� ���� ����, ���� ����, ��ȭ�� ��ģ��.
      int complete[5] = {-1,-1,-1,-1,-1};

      //�����̺�Ʈ �߻� ����, ���簳�� �߻� ����, �� Ÿ�� �߻� ����
      int a = rand()%2;
      int b = rand()%2;
      int c = rand()%2;
      int rand[3] = {a,b,c};
   
      //thirdStageBaseGame[3]; //�̸� ���߱� ����, ��� ����, ���ἱ��(Ŀ��/�ֽ�/��ȭ��) ��� (0=����, 1=����)  

      imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);

      // ī�信 �����ߴ�.
      imageDraw("ī�信�����ߴ�.txt",5,210);
      Sleep(1300);
      // �� �ָ� ��밡 ���δ�.
      imageDraw("���ָ���밡���δ�.txt",5,230);
      Sleep(1300);
      //�̸� ���߱� ����
      thirdStageBaseGame[0] = namePick();
      complete[0] = thirdStageBaseGame[0];
      
      char temp;
      char temp2 = '0';
      int pick;
      
      if(rand[1]==1){ //���� ���� �߻�
         while(1){
            ConversationListDraw(rand,complete);
            temp = getch();
            pick = (int)(temp - temp2);
         
            if(complete[1]==-1&&pick==1){//��� ����
               thirdStageBaseGame[1] = quiz();
               complete[1] = thirdStageBaseGame[1];
			   if(rand[2]==1)
				 randGame[1] = danceTime();
            }
            else if(complete[2]==-1&&pick==2){//���ἱ�ð���
               thirdStageBaseGame[2] = drinkPick();
               complete[2] = thirdStageBaseGame[2];
            }
            else if(complete[3]==-1&&pick==3){//���簳��
               // randGame[3]; //����, ��, ����
               randGame[0] = gagPick();
               complete[3] = randGame[0];
            }
            else if(pick==4){//��ȭ��ġ�� 
               if(rand[0]==1){
                  if(player.stringItems()=="���"){
                     imageDraw("�������.txt",30,25);
                     getPlayer().setHeart(5);
                     randGame[2] = 1;
                  }
                  else{
                     imageDraw("������.txt",30,25);
                     getPlayer().setHeart(-5);
                     randGame[2] = 0;
                  }
                  Sleep(3000);
               }
               break;
            }
         }
      }
      else{ //���� ���� �߻����� ����.
         while(1){
            ConversationListDraw(rand,complete);
            temp = getch();
            pick = (int)(temp - temp2);
         
            if(complete[1]==-1&&pick==1){//��� ���� 
               thirdStageBaseGame[1] = quiz();
               complete[1] = thirdStageBaseGame[1];
			   if(rand[2]==1)
				 randGame[1] = danceTime();
            }
            else if(complete[2]==-1&&pick==2){//���� ���� ����
               thirdStageBaseGame[2] = drinkPick();
               complete[2] = thirdStageBaseGame[2];
            }
            else if(pick==3){//��ȭ��ġ��
               if(rand[0]==1){
                  if(player.stringItems()=="���"){
                     imageDraw("�������.txt",30,25);
                     getPlayer().setHeart(5);
                     randGame[2] = 1;
                  }
                  else{
                     imageDraw("������.txt",30,25);
                     getPlayer().setHeart(-5);
                     randGame[2] = 0;
                  }
                  Sleep(3000);
               }
               break;
            }      
         }
      }
    }
      

   void cafeMap(){

      ThreeBasicOutlineDraw();

      // thirdStageBaseGame[3] �̸� ���߱� ����, ��� ����, ���ἱ��(Ŀ��/�ֽ�/��ȭ��) ��� (0=����, 1=����)
	  selectCafeOutLineDraw(); //ī���̸���� 
	  
      imageDraw("ground100(2).txt",5,195);
      imageDraw("ground100(2).txt",104,195);
      imageDraw("ground100(2).txt",203,195);
      imageDraw("ground100(2).txt",302,195);
      imageDraw("ground100(2).txt",401,195);
      imageDraw("ground100(2).txt",500,195);
      imageDraw("ground100(2).txt",599,195);
	  imageDraw("ī��100.txt",590,150); 
      imageDraw("ceil200.txt",5,30);
      imageDraw("ceil200.txt",204,30);
      imageDraw("ceil200.txt",403,30);


      imageDraw("back600(2).txt",4,60);
      
      imageDraw("chair180.txt",10,160);
      imageDraw("chair180.txt",360,160);

   
      int x=50;
      int y =200;
      imageDraw("��1.txt",210,168);
      imageDraw("ASCIIART_(2).txt",280,165);
   
      conversation();

   
      gotoxy(500,500);


   }

	
	void intro(){
		//font size 5 ����
		introInit();
		//intro ���
        introMain();
		//ȭ�� ����
		system("cls");

	}
	void story(){
		//font size 5 ����
		introInit();
		//intro ���
		storyMain();
		//ȭ�� ����
		system("cls");

	}

	void motorcycle(){
		//font size 5 ����
		introInit();
		//intro ���
		motorMain();
		//ȭ�� ����
		system("cls");

	}

	void success(){
		//font size 5 ����
		introInit();
		//intro ���
		successMain();
		imageDraw("���������200.txt",153,40);

	}

	void failure(){
		//font size 5 ����
		introInit();
		//intro ���
		failureMain();
		imageDraw("���������200.txt",153,40);
		

	}

	void selectLevel(){
		//level menu draw
		keyDraw();
		init();
		int x = 34;
		int y = 14;
		int pick;
		bool whileTrue = true;
   		gotoxy(16,8,"�����̵� ���á�");
		gotoxy(7,10,"EASY:ȣ���� 50��| NORMAL:ȣ���� 60��| HARD:ȣ���� 70��");
		gotoxy(x-2,y); //14
		printf("��  EASY");
		gotoxy(x,y+1); //15
		printf("  NORMAL");
		gotoxy(x,y+2);  //16
		printf("  HARD");
   
		while(whileTrue){
			int select = keyControl();
      
			switch(select){
				case UP: {
					if(y>14){ //y�� 14-16������ �̵�  
						gotoxy(x-2,y);
						printf("   ");
						gotoxy(x-2,--y);
						printf("��");
					}
						break;
				 }   
				case DOWN: {
					if(y<16){ //�ִ� 16������ �̵� ����  
						gotoxy(x-2,y);
						printf("   ");
						gotoxy(x-2,++y);
						printf("��");
					}
					break;
				}
				case SUBMIT: {
					pick = y-14;
					whileTrue = false;
					}
				}
		}

		// setting level
		if(pick == 0){
			gotoxy(x-10,14);
			cout<<"�� ���̵� easy�� �����ϼ̽��ϴ�.";
			level="easy";
		}
		else if(pick == 1){
			gotoxy(x-10,15);
			cout<<"�� ���̵� normal�� �����ϼ̽��ϴ�.";
			level="normal";
		}
		else if(pick == 2){
			gotoxy(x-10,16);
			cout<<"�� ���̵� hard�� �����ϼ̽��ϴ�.";
			level="hard";
		}

	}

	void selectName(){
		//���α׷� ����ø��� ������ �߻�
		//stdlib, time ��� ����
		keyDraw();
		srand((unsigned int)time(NULL));

		gotoxy(16,8,"������� �̸� ���á�");
		int name=rand()%(4);
		gotoxy(17,13,"");
		cout<<nameArray[name];
    
   
		gotoxy(14,10,"���ΰ�ħ�� 4���� �����ּ���");
    
		int key;
		while(1){
			key = getch();
    
			if(key == ' '){
				gotoxy(8,16,"�����Ͻ� �̸���'");
				gotoxy(18,16,"");
				cout<<nameArray[name]<<"      ' �Դϴ�.";
				player.setName(nameArray[name]); 
				break;
			}
			else if(key == 52){// ���ΰ�ħ  
				name=rand()%(4);
				gotoxy(17,13,"");
				cout<<nameArray[name]<<"   ";
			}
		}
	}

	void selectGender(){
		//gender select menu
		int x = 34;
		int y = 13;
		int pick;
		bool whileTrue = true;
        keyDraw();      
		gotoxy(16,8,"���������á� ");
		gotoxy(x-2,y); //13
		printf("��  WOMAN");
		gotoxy(x,y+1); //14
		printf("  MAN");
		gotoxy(x,y+2);  //15
		printf("  SECRET");
   
		while(whileTrue){
			int select = keyControl();
      
			switch(select){
				case UP: {
					if(y>13){ //y�� 13-15������ �̵�  
						gotoxy(x-2,y);
						printf("   ");
						gotoxy(x-2,--y);
						printf("��");
					}
					break;
				}   
				case DOWN: {
					if(y<15){ //�ִ� 15������ �̵� ����  
						gotoxy(x-2,y);
						printf("   ");
						gotoxy(x-2,++y);
						printf("��");
					}
					break;
				}
				case SUBMIT: {
					pick = y-13;
					whileTrue = false;
				}
			}
		} 
		
		//setting gender
		if(pick == 0){
			gotoxy(x-12,13);
			cout<<"��  ����  woman�� �����ϼ̽��ϴ�.";
			string gender="woman";
			player.setGender(gender);
		}
		else if(pick == 1){
			gotoxy(x-12,14);
			cout<<"��  ����  man��  �����ϼ̽��ϴ�.";
			string gender="man";
			player.setGender(gender);
		}
   
		else if(pick == 2){
			gotoxy(x-12,15);
			cout<<"��  ����  secret�� �����ϼ̽��ϴ�.";
			string gender="secret";
			player.setGender(gender);
		}
   
		gotoxy(20,20," ");

	}

	void personINFO(){
		draw1();
		gotoxy(17,7,"������ ������ ");
		gotoxy(14,9,"���� �̸�: ");
		cout<<computer.getName();
		gotoxy(14,11,"���� �̸�: ");
		cout<<player.getName();
		gotoxy(14,13,"����: ");
		cout<<player.getGender();
		gotoxy(14,15,"���̵�: ");
		cout<<level<<endl;
		gotoxy(8,17,"�����̽��ٸ� ������ �ޱ��� ������ �ٷ� ����˴ϴ�.");
		gotoxy(11,19,"�޿��� ������ ���������� ����ҰԿ䢾");
		gotoxy(17,21,"��SPACEBAR��");
		
		while(1){

        if(kbhit()){ //Ű�Է¹��� 
            char key=getch();
            if(key==' ') return; // ESCŰ�� ���� 
            else break; //�ƴϸ� �׳� ��� ���� 
        } 

        gotoxy(17,21," ��SPACEBAR�� ");
        Sleep(400);
        gotoxy(17,21,"               ");
        Sleep(400);
    }
		
		

		
		Sleep(100000);


	}


	void firstStage(){

		//fontSIze 16 ����
		Init();

		//���̵� ����, �̸�, ���� ����
		draw1();
		selectLevel();
		Sleep(500);
		system("cls");
		draw1();
		selectName();
 		Sleep(500);
		system("cls");
		draw1();
		selectGender();

		//ȭ�� ����
		system("cls");

	}
	
	void secondStage(){
		// �ʰ� ���� �̴ϰ���
		miniGameResult[0] = wakeUpGame();
		Sleep(1500);
		system("cls");
		//font size 1 ����
		changeInit();
		//�Ž�
		int miniGame;
		int mapX = 66;
		int mapY = 124;
		bool first = true;
		while(true){
			miniGame = livingRoom(mapX,mapY, first);
			//ȭ��� ���� 5, �ʰ��� 6, ����ǰ ���� 7, �����ϱ� 8
			if(miniGame==5){
				//ȭ��� ��
				toiletGame(miniGameResult, seasonNumber);
				mapX=625;
				mapY=100;
				first = false;
				//x y ��ǥ ����
			}
			if(miniGame==6){
				//�ʰ��� ����
				selectClothesGame(player);
				//x y ��ǥ ����
				mapX = 425;
				mapY = 70;
				first = false;
			}
			if(miniGame==7){
				//����ǰ ���� ����
				selectItemsGame(player);
				//x y ��ǥ ����
				mapX = 100;
				mapY = 70;
				first = false;
			}
			if(miniGame==8){
				//2�ܰ� ����
				break;
			}
			if(miniGame==-100){
				// QUIT
				break;
			}
		}

		//ȭ�� ����
		system("cls");

	}

	void thirdStage(){
		// ������ ����

		//fontsize 1
		changeInit();

		// thirdStageBaseGame[3] �̸� ���߱� ����, ��� ����, ���ἱ��(Ŀ��/�ֽ�/��ȭ��) ��� (0=����, 1=����)
		cafeMap();


		//ȭ�� ����
		system("cls");
	}

	void secondResult(){
      //fonstSize 16 ����
      Init();

      //�� �� �̴ϰ��ӿ� ���� ��� ��� �Լ�
      //temp : �� �̴ϰ��� ����� ���� ȣ���� ������ �ӽ� �����
      draw2();
      keyDraw();
      int temp = 0;
      //����� ��ǥ
      int x = 20; int y = 10;
      gotoxy(13,4,"��2�ܰ� ���� �����");
      gotoxy(x,y++);
      gotoxy(5,9,"ó�� ȣ���� ��");
      gotoxy(16,9," 100");
      for(int i=0;i<5;i++){
         if(miniGameResult[i]==0) {
            //���� ����� �����̸� ȣ���� -30 or -10
            if(i==0){
               //�ޱ��� �����̸�
               temp = -30;
               player.setHeart(temp);
               gotoxy(10,y,"   -         ");
               gotoxy(30,y);
               cout <<"    "<<"30";
               gotoxy(30,y,"����!");
               gotoxy(x+20, y++);
               cout <<"  "<<miniGameName[i];
               gotoxy(x+20, y++);
            }
            else {
               //�ޱ��� ������ �ƴϸ� 
               temp = -10;
               player.setHeart(temp);
               gotoxy(10,y,"   -         ");
               gotoxy(30,y);
               cout <<"    "<<"10";
               gotoxy(30,y,"����!");
               gotoxy(x+20, y++);
               cout <<"  "<<miniGameName[i];
               gotoxy(x+20, y++);
            }
         }
         else {
            //���� ����� �����̸� ȣ���� ���� ����.
            gotoxy(x+2,y);
            gotoxy(10,y,"   -         ");
            gotoxy(30,y);
            cout <<"     0";
            gotoxy(30,y,"����!");
            gotoxy(x+20, y++);
            cout <<"  "<<miniGameName[i];// << " ����!";
            gotoxy(x+20, y++);
         }
      }
      gotoxy(10,y,"��������������������������������������");
      gotoxy(3,y+2,"���� ���� ȣ����  ��");
      gotoxy(17,23,""); 
      cout << player.getHeart();
      gotoxy(0,31,""); 
      
      //ȣ���� ��� 1�� ����
      Sleep(2500);

      //ȭ�� �ʱ�ȭ
      system("cls");

      secondStageScore = player.getHeart();


   }
	
	void thirdResult(){  

      //fonstSize 16 ����
      Init();
	  draw3();
	  gotoxy(13,4,"��3�ܰ� ���� �����");
      gotoxy(5,9,"ó�� ȣ���� ��");
      gotoxy(15,9,"");
	  

      // ������ �����, �����ο� �ŵ���, ������ ��翬, �������� ������
       string Tops[4] = {"����","����","����","�е�"};
       string Pants[4] = {"�߸���","�ݹ���","�����","������"};
       string Shoes[4] = {"������","����","�ȭ","����"};

      // �� ������ ���ӿ� ���� ȣ���� ����
      int hateCount = 0; //��� ���� computer�� ���� �ʴ°�?
      int badCount = 0; //��� ���� ������ ���� �ʴ°�?
      string top = player.getClothes().getTop();
      string pants = player.getClothes().getPants();
      string shoes = player.getClothes().getShoes();

      if(computer.getName()=="������ �����"){ 
         //������ <-> �߸���, ������
         if (pants == Pants[0]){
            hateCount++;
         }
         if (shoes == Shoes[0]){
            hateCount++;
         }   
      }
      else if(computer.getName()=="�����ο� �ŵ���"){ 
         //�����ο� <-> ����,���� 
         if(top==Tops[2]){
            hateCount++;
         }
         if (pants == Pants[3]){
            hateCount++;
         }
         if (shoes == Shoes[3]){
            hateCount++;
         }
      }
      else if(computer.getName()=="������ ��翬"){
         //������ <-> ����, �����, �ȭ
         if(top==Tops[1]){
            hateCount++;
         }
         if(pants == Pants[2]){
            hateCount++;
         }
         if(shoes == Shoes[2]){
            hateCount++;
         }
      }
      else if(computer.getName()=="�������� ������"){
         //�������� <-> �μҸ�, �ݹ���, ����
         if(top==Tops[0]){
            hateCount++;
         }
         if (pants == Pants[1]){
            hateCount++;
         }
         if (shoes == Shoes[1]){
            hateCount++;
         }
      }

      if(season=="����"){
         if(top==Tops[3]){
            badCount++;
         }
      }
      else if(season=="�ܿ�"){
         if(top==Tops[0]){
            badCount++;
         }
         if(pants==Pants[1]){
            badCount++;
         }
         if(shoes==Shoes[0]){
            badCount++;
         }
      }

      //����� ��ǥ
      int x = 20; int y = 10;
      if(secondStageScore<100)
      //gotoxy(x+1,y++);
      cout <<" "<<secondStageScore;
	  gotoxy(x+1,y++);

      if(hateCount>0){
         if(hateCount==1)
            gotoxy(x+1,y);
         else
            gotoxy(x,y);
         
		 if(hateCount>1){
			gotoxy(10,y,"  -        ");
			cout << hateCount*(5);
		 }
		 else{
			 gotoxy(10,y,"  -         ");
			cout << hateCount*(5);
		 }
         player.setHeart(hateCount*(-5));
         gotoxy(37,y++);
         cout<<"'" << computer.getName() << "' �� ��ȣ���� �ʴ� ���� ����";
		 gotoxy(x+10,y++);
      }
      if(badCount>0){
         if(badCount==1)
            gotoxy(x+1,y);
         else
            gotoxy(x,y);

		 if(badCount>1){
			 gotoxy(10,y,"  -        ");
			 cout << badCount*(5);
		 }
		 else{
			 gotoxy(10,y,"  -         ");
             cout << badCount*(5);
		 }
		 
         player.setHeart(hateCount*(-5));
         gotoxy(37,y++);
         cout <<"'"<< season << "' �� ���� �ʴ� ���� ����";
		 gotoxy(x+10,y++);
      }
      if(player.stringItems()=="�񵵸�"||player.stringItems()=="�ճ���"){
         if(season=="�ܿ�"){
            player.setHeart(5);
            gotoxy(x,y);
            cout << "  +        5";
            gotoxy(x+10,y++);
            cout <<"      '" << season << "' �� �´� ����ǰ�� ����";
			gotoxy(x+10,y++);
         }
      }
      if(player.stringItems()=="�޴�� ��ǳ��"){
         if(season=="����"){
            player.setHeart(5);
            gotoxy(x,y);
            cout << "  +        5";
            gotoxy(x+10,y++);
            cout <<"      '" << season << "' �� �´� ����ǰ�� ����";
			gotoxy(x+10,y++);
         }
      }
      if(player.stringItems()=="�ռ���"){
         if(computer.getName()=="������ �����" || computer.getName()=="�������� ������" ){
            player.setHeart(5);
            gotoxy(x,y);
            cout << "  +        5";
            gotoxy(x+10,y++);
            cout <<"'"<< computer.getName() << "' �� ��ȣ���� �ʴ� ����ǰ�� ����";
			gotoxy(x+10,y++);
         }
      }
      if(player.stringItems()=="���"||player.stringItems()=="�ſ�"||player.stringItems()=="�ɴٹ�"||player.stringItems()=="�������͸�"){
         gotoxy(x,y);
         cout << "  +        5";
         gotoxy(x+10,y++);
         cout <<"      '" << "���⿡ ������ ����ǰ�� ����";
		 gotoxy(x+10,y++);
      }

      // �̸� ���߱� ����, ��� ����, ���ἱ��(Ŀ��/�ֽ�/��ȭ��) 
	  for(int i=0;i<3;i++){
         if(thirdStageBaseGame[i]==0){
            // ���� ���� -> ȣ���� 10 ����
            gotoxy(x,y);
			player.setHeart(-5);
			gotoxy(10,y,"  -         5");
            gotoxy(x+15,y++);
            cout <<"  "<< thirdStageBaseGameName[i];
			gotoxy(x+10,y-1,"����!");
			gotoxy(x+15,y++);
			
         }
         else{
            // ���� ���� -> ȣ���� 10 ����
            gotoxy(x,y);
			player.setHeart(+5);
            gotoxy(10,y,"  +         5");
            gotoxy(x+15,y++);
            cout <<"  "<< thirdStageBaseGameName[i];
			gotoxy(x+10,y-1,"����!");
			gotoxy(x+15,y++);

         }
      }

      // randGame[3]; //����, ��, ����, -1 ������� 0 ���� 1 ����
      if(randGame[0]==0){
         gotoxy(x,y);
         gotoxy(10,y,"  -         5");
         gotoxy(x+10,y++);
         cout <<"  "<< randGameName[0];// << " ����";
		 gotoxy(x+10,y-1,"����!");
		 gotoxy(x+15,y++);
      }
      if(randGame[0]==1){
         gotoxy(x,y);
         gotoxy(10,y,"  +         5");
         gotoxy(x+15,y++);
         cout <<"  "<< randGameName[0];// << " ����";
		 gotoxy(x+10,y-1,"����!");
		 gotoxy(x+15,y++);
      }
      if(randGame[1]==1){
         gotoxy(x,y);
         gotoxy(10,y,"  -         5");
         gotoxy(x+10,y++);
         cout <<"  "<< randGameName[1];// << " ����";
		 gotoxy(x+10,y-1,"����!");
		 gotoxy(x+15,y++);
      }
      if(randGame[2]==1){
         gotoxy(x,y);
         gotoxy(10,y,"  +         5");
         gotoxy(x+15,y++);
         cout <<"  "<< randGameName[2] ;//<< " ����";
		 gotoxy(x+10,y-1,"����!");
		 gotoxy(x+15,y++);
      } 
	  if(randGame[2]==0){
         gotoxy(x,y);
         gotoxy(10,y,"  -         5");
         gotoxy(x+15,y++);
         cout <<"  "<< randGameName[2] ;//<< " ����";
		 gotoxy(x+10,y-1,"����!");
		 gotoxy(x+15,y++);
      }     

      gotoxy(20-10,y);
      //cout << "=" ;
      if(player.getHeart()==100 || player.getHeart()<0)
         gotoxy(x,y);
      else if(player.getHeart()>=10)
         gotoxy(x+1,y); 
      else
         gotoxy(x+2,y);
      
	  gotoxy(10,y,"��������������������������������");
      gotoxy(2,y+2,"���� ���� ȣ����  ��");
      //gotoxy(17,18,""); 
	  cout <<"       " <<player.getHeart();
      gotoxy(0,31,""); 
      //��� ȭ�� ����
      Sleep(2500);

      //ȭ�� ����
      system("cls");
		
	  if(level=="easy"){
			if(player.getHeart()>=50)
				success();
			else
				failure();
		}
	  else if(level=="normal"){
			if(player.getHeart()>=60)
				success();
			else
				failure();

	  }
	  else if(level=="hard"){
			if(player.getHeart()>=70)
				success();
			else
				failure();

	 }

	}

	void gameStart(){

	    PlaySound(TEXT(First_Run), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
	
		intro();
		story();
		firstStage();
		personINFO();

		PlaySound(NULL, 0, 0);
		
		PlaySound(TEXT(Second_Run), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
		secondStage();
		
		secondResult();
		PlaySound(NULL, 0, 0);

		PlaySound(TEXT(Third_Run), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
		motorcycle();
		thirdStage();
		
		thirdResult();
		
		char replay;
		while(true){
			replay = getch();
			if(replay=='y' || replay == 'Y' || replay=='n' || replay == 'N')
				break;
		}

		PlaySound(NULL, 0, 0);

		if(replay=='y' || replay == 'Y')
			gameStart();
		else
			system("exit");


		gotoxy(50,15);
	}

};


