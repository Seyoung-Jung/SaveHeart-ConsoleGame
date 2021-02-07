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
   int miniGameResult[5]; //꿈깨기 게임, 세수 게임, 눈곱 게임, 양치 게임, 머리감기게임 결과 (0=실패, 1=성공)
   int thirdStageBaseGame[3]; //이름 맞추기 게임, 상식 퀴즈, 음료선택(커피/주스/쌍화탕) 결과 (0=실패, 1=성공)
   int randGame[3]; //아재, 댄스, 날씨, -1 실행안함 0 실패 1 성공
   int secondStageScore;
   int seasonNumber;

public:
   string miniGameName[5];
   string thirdStageBaseGameName[3];
   string randGameName[3];

   Game(){

      //상대 캐릭터 생성
      srand(time(NULL));
      int computerName = rand()%4; //0,1,2,3
      int computerGender = rand()%2; //0,1

      if(computerName==0 && computerGender==0)
         computer = Person("차분한 김상중", "여성");
      else if(computerName==1 && computerGender==0)
         computer = Person("자유로운 신동엽", "여성");
      else if(computerName==2 && computerGender==0)
         computer = Person("엉뚱한 노사연", "여성");
      else if(computerName==3 && computerGender==0)
         computer = Person("보수적인 양희은", "남성");
      else if(computerName==0 && computerGender==1)
         computer = Person("차분한 김상중", "남성");
      else if(computerName==1 && computerGender==1)
         computer = Person("자유로운 신동엽", "남성");
      else if(computerName==2 && computerGender==1)
         computer = Person("엉뚱한 노사연", "남성");
      else if(computerName==3 && computerGender==1)
         computer = Person("보수적인 양희은", "남성");

      //계절 설정
      int gameSeason= rand()%(4); //0,1,2,3
	  seasonNumber = gameSeason;
      switch(gameSeason){
      case 0 : season = "봄" ; break;
      case 1 : season = "여름" ; break;
      case 2 : season = "가을" ; break;
      case 3 : season = "겨울" ;
      }

	  

      //배열 초기화
      for(int i=0;i<5;i++){
         miniGameResult[i] = 0;
      }
      for(int i=0;i<3;i++){
         thirdStageBaseGame[i] = 0;
      }
      for(int i=0;i<3;i++){
         randGame[i] = -1;
      }
      miniGameName[0] = "꿈 깨기 게임";
      miniGameName[1] = "세수하기 게임";
      miniGameName[2] = "눈곱 떼기 게임";
      miniGameName[3] = "양치 게임";
      miniGameName[4] = "머리 감기 게임";
      thirdStageBaseGameName[0]="이름 맞추기 게임";
      thirdStageBaseGameName[1]="상식 퀴즈";
      thirdStageBaseGameName[2]="운명의 음료 선택 게임";
      randGameName[0] = "아재 개그";
      randGameName[1] = "이벤트(댄스)";
      randGameName[2] = "이벤트(비)";
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

	int namePick(){ //이름 맞추기  ---대화를 나눈다음에 선택하는 건가..?
   
   gotoxy(3,210);
   imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);


   gotoxy(5,210);
   // "??? : 안녕하세요~ 일찍 나오셨네요 ㅎㅎ" == 이름맞추기인사
   imageDraw("이름맞추기인사.txt",5,210);
   Sleep(1500);
   gotoxy(5,230);
   // 상대방 이름이 뭐였지? 잘 생각해보자.
   imageDraw("이름맞추기인사2.txt",5,230);
   Sleep(2000);

   gotoxy(3,210);
   // 칸 초기화
   imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);

   

   gotoxy(5,210);
   // "1. 안녕하세요! 차분한 김상중님 맞으시죠~?" == 이름맞추기 1
   imageDraw("이름맞추기1.txt",5,210);
   gotoxy(5,225);
   // "2. 안녕하세요! 자유로운 신동엽님 맞으시죠~?" == 이름맞추기 2
   imageDraw("이름맞추기2.txt",5,225);
   gotoxy(5,237);
   // "3. 안녕하세요! 엉뚱한 노사연님 맞으시죠~?" == 이름맞추기 3
   imageDraw("이름맞추기3.txt",5,240);
   gotoxy(5,251);
   // "4. 안녕하세요! 보수적인 양희은님 맞으시죠~?" == 이름맞추기 4
   imageDraw("이름맞추기4.txt",5,255);
      
   char temp;

   while(true){
      temp = getch();
      if(temp=='1' || temp=='2' || temp=='3' || temp =='4')
         break;
   }
   


   gotoxy(3,210);
   imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);
   // 칸 초기화

   char temp2 = '0'; 
   int pick = temp - temp2;

   string pcName[4];
   pcName[0]="차분한 김상중";
   pcName[1]="자유로운 신동엽";
   pcName[2]="엉뚱한 노사연";
   pcName[3]="보수적인 양희은";

   string computerName = getComputer().getName();
   string selectName = pcName[pick-1];
      
   string npc = computerName + ".txt";
   string npcName = computerName + "2.txt";
   const char* Npc = npc.c_str();
   const char* NpcName = npcName.c_str();

   if(computerName == selectName){
      gotoxy(5,210);
      // 컴퓨터 이름 : 
      imageDraw(Npc,3,210);
      gotoxy(100,210); //x값 변경 가능
      // 네 맞아요 ㅎㅎㅎㅎㅎ == 이름맞추기5
      imageDraw("이름맞추기5.txt",150,210);
      Sleep(1500);
      gotoxy(5,230);
      imageDraw("다행히도.txt",5,230);
      Sleep(1500);
      imageDraw("호감도상승.txt",5,245);
      // 다행히도 상대방의 이름을 맞춘 것 같다. 호감도 상승.
      getPlayer().setHeart(5); 
      Sleep(2000);
      imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);
      return 1;
   }
   else{
      gotoxy(3,210);
      // 컴퓨터 이름 : 
      imageDraw(Npc,5,210);
      gotoxy(100,210); //x값 변경 가능
      // 아닌데... 제 이름은 == 이름맞추기6
      imageDraw("이름맞추기6.txt",150,210);
      gotoxy(40,210); //x값 변경 가능
      // 컴퓨터 이름
      imageDraw(NpcName,330,210);
      gotoxy(50,210); //x값 변경 가능
      // 입니다. == 이름맞추기7
      imageDraw("이름맞추기7.txt",480,210);
      Sleep(1500);
      gotoxy(5,230);
      imageDraw("첫만남에.txt",5,230);
      Sleep(1500);
      imageDraw("호감도하락.txt",5,245);
      // 아, 첫만남에 이런 실수를! 호감도 하락.
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
		imageDraw("돌발상황발생.txt",5,210);
		Sleep(1000);
		imageDraw("카페에흘러나오는.txt",5,230);
		imageDraw("상대방의눈이.txt",5,242);
		Sleep(1500);
		imageDraw("thirdBlank.txt",3,210);
        imageDraw("thirdBlank.txt",200,210);
        imageDraw("thirdBlank.txt",260,210);

		// 이름 :
		string npc = getComputer().getName() + ".txt";
		string npcName = getComputer().getName() + "2.txt";
		const char* Npc = npc.c_str();
		const char* NpcName = npcName.c_str();
		imageDraw(Npc,5,210);
		imageDraw("이노래.txt",200,210);
		imageDraw("몸을들썩.txt",5,230);
		Sleep(1500);
		imageDraw("thirdBlank.txt",3,210);
        imageDraw("thirdBlank.txt",200,210);
        imageDraw("thirdBlank.txt",260,210);

		if(player.stringItems()=="마이크"){
			imageDraw("마이크있음.txt",5,210);
			imageDraw("상대방의흥.txt",5,225);
			Sleep(1500);
			imageDraw(NpcName,5,240);
			imageDraw("마이크를준비해온.txt",200,240);
			imageDraw("호감도상승.txt",5,255);
			Sleep(2000);
			imageDraw("thirdBlank.txt",3,210);
			imageDraw("thirdBlank.txt",200,210);
			imageDraw("thirdBlank.txt",260,210);
			player.setHeart(5);
			return 1;
		}
		else{
			imageDraw("마이크없음.txt",5,210);
			imageDraw("상대방을위해.txt",5,225);
			imageDraw("마이크가없네.txt",5,240);
			Sleep(1500);
			imageDraw("춤을추던.txt",5,255);
			Sleep(2000);
			imageDraw("thirdBlank.txt",3,210);
			imageDraw("thirdBlank.txt",200,210);
			imageDraw("thirdBlank.txt",260,210);
			return 0;
		}

   }
   
   int quiz(){ // 상식 퀴즈 


      imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);

       if(player.stringItems()=="신문"){
         //소지품 유머책이 있으면 생략 여부 묻기
         imageDraw("소지품신문.txt",5,210);
         imageDraw("생략할까요.txt",23,222);
         imageDraw("예스.txt",5,240);

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
      imageDraw("혹시신문.txt",150,210); //x값 변경 가능
      // "혹시 신문 많이 보시나요? 신문에 나오는 퀴즈들인데 한번 맞춰보실래요?" == 상식퀴즈1
      Sleep(1300);

      /*
      quizSets[0]="혹시 불로장생을 꿈꾸기 위해, 중국 진시황이 사람들을 시켜서 찾게 했던, 자연 버섯을 뜻하는 이 약초의 이름을 아시나요?";//상식퀴즈2
      quizSets[1]="혹시 '내 뒷마당에서는 안된다'라는 이기주의적 의미로 통용되는 용어를 아시나요? "; //상식퀴즈3
      quizSets[2]="혹시 이 보기 중 백제의 수도가 아니었던 곳을 아시나요?";//상식퀴즈4
      quizSets[3]="혹시 보기 중 아시아가 아닌 나라가 어딘지 아시나요?"; //상식퀴즈5 
      */
        imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",255,210);

      int n = rand()%4;
      

      if(n==0){
         imageDraw(Npc,5,210);
         imageDraw("불로장생.txt",150, 210);
         imageDraw("자연버섯.txt",150,222);

         imageDraw("상식퀴즈6.txt",5,232);
         // 1. 불로초 == 상식퀴즈6
         imageDraw("상식퀴즈7.txt",5,247);
         // 2. 진시초 == 상식퀴즈7
         imageDraw("상식퀴즈8.txt",5,262);
         // 3. 검은팥버섯 == 상식퀴즈8
         imageDraw("상식퀴즈9.txt",150,262);
         // "(힌트: 문제에 답이 있습니다)") == 상식퀴즈9

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
            imageDraw("아시는군요.txt",150,210); //x값 변경 가능
            Sleep(1000);
            imageDraw("호감도상승.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210);
            imageDraw("답은1번.txt",150,210); 
            Sleep(1000);
            imageDraw("호감도하락.txt",5,230);
            // "아..모르시군요..답은 1번 '불로초' 였어요..! 호감도가 -5 하락하였습니다." == 상식퀴즈11
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
         imageDraw("내뒷마당.txt",150, 210);
         imageDraw("통용되는.txt",150,222);

         imageDraw("상식퀴즈12.txt",5,232);
         imageDraw("상식퀴즈13.txt",5,247);
         imageDraw("상식퀴즈14.txt",5,262);

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
            imageDraw("아시는군요.txt",150,210); //x값 변경 가능
            Sleep(1000);
            imageDraw("호감도상승.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210);
            imageDraw("답은님비.txt",150,210); 
            Sleep(1000);
            imageDraw("호감도하락.txt",5,230);
            // "아..모르시군요..답은 3번 '님비현상' 이였어요..! 호감도가 -5 하락하였습니다." == 상식퀴즈15
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 0;
         }   
      }
      else if(n==2){
         imageDraw("상식퀴즈4.txt",5, 210);
         imageDraw("상식퀴즈16.txt",5,230);
         // 1. 불로초 == 상식퀴즈6
         imageDraw("상식퀴즈17.txt",5,245);
         // 2. 진시초 == 상식퀴즈7
         imageDraw("상식퀴즈18.txt",5,260);

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
            imageDraw("아시는군요.txt",150,210); //x값 변경 가능
            Sleep(1000);
            imageDraw("호감도상승.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210);
            imageDraw("답은고령.txt",150,210); 
            Sleep(1000);
            imageDraw("호감도하락.txt",5,230);
            //"아..모르시군요..답은 2번 '고령' 이였어요..! 호감도가 -5 하락하였습니다." == 상식퀴즈19
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 0;
         }   
      }
      else if(n==3){
         imageDraw("상식퀴즈5.txt",5, 210);
         imageDraw("상식퀴즈20.txt",5,230);
         // 1. 불로초 == 상식퀴즈6
         imageDraw("상식퀴즈21.txt",5,245);
         // 2. 진시초 == 상식퀴즈7
         imageDraw("상식퀴즈22.txt",5,260);

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
            imageDraw("아시는군요.txt",150,210); //x값 변경 가능
            Sleep(1000);
            imageDraw("호감도상승.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210);
            imageDraw("답은러시.txt",150,210); 
            Sleep(1000);
            imageDraw("호감도하락.txt",5,230);
            //"아..모르시군요..답은 1번 '러시아' 이였어요..! 호감도가 -5 하락하였습니다." == 상식퀴즈23
            getPlayer().setHeart(-5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",255,210);
            return 0;
         }   
      }

   }

   int drinkPick(){ //음료선택게임 
         
      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);

      srand((unsigned int)time(NULL));

      string drink[3]={"커피","주스","쌍화탕"};
      int n = rand()%3;

      string computerName = getComputer().getName() ;
      string npc = computerName + ".txt";
      const char* Npc = npc.c_str();


      // 컴퓨터 이름 : 
      imageDraw(Npc,5,210);
      imageDraw("전저랑.txt",150,210);
      imageDraw("음료1.txt",150,222);

      Sleep(1500);

      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",230,210);

      imageDraw("상대방과똑같은.txt",5,210);
      // 상대방과 똑같은 음료를 고르자!

      imageDraw("음료2.txt",5,230);
      //"1.네 저는 커피요^^!" == 음료2
      imageDraw("음료3.txt",5,242);
      // 2.네 저는 주스요^^!" == 음료3
      imageDraw("음료4.txt",5,254);
      // "3.네 저는 쌍화탕이요^^!" == 음료4


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
         imageDraw("음료5.txt",150,210);
         //"오~! 저랑 취향이 똑같으시네요ㅎㅎ" == 음료5
         Sleep(1000);
         imageDraw("호감도상승.txt",5,230);
         getPlayer().setHeart(5);
         Sleep(2000);
         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);
         return 1;
      }
      else{
         imageDraw(Npc,5,210);
         imageDraw("취향이독특한.txt",150,210);
         Sleep(1000);
         imageDraw("호감도하락.txt",5,230);
         getPlayer().setHeart(-5);
         Sleep(2000);
         imageDraw("thirdBlank.txt",3,210);
         imageDraw("thirdBlank.txt",200,210);
         imageDraw("thirdBlank.txt",230,210);
         return 0;
      }
      }
   
   int gagPick(){ //아재개그 
      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",230,210);


      if(player.stringItems()=="유머책"){
         //소지품 유머책이 있으면 생략 여부 묻기
         imageDraw("소지품유머책.txt",5,210);
         imageDraw("생략할까요.txt",23,222);
         imageDraw("예스.txt",5,240);

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

      imageDraw("어색한.txt",5,210);

      Sleep(1200);

      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",230,210);

      imageDraw(Npc,5,210);
      imageDraw("제가재.txt",150,210);
      imageDraw("한번맞.txt",150,222);

      Sleep(1200);

      imageDraw("thirdBlank.txt",3,210);
      imageDraw("thirdBlank.txt",200,210);
      imageDraw("thirdBlank.txt",230,210);

      /*
      quizSets[0]="칼이 정색하면?!"; //아재2
      quizSets[1]="바나나가 웃으면?! "; //아재3
      quizSets[2]="3월에 대학생이 강한 이유를 아시나요?!";//아재4
      quizSets[3]="기름이 수출되는데 얼마나 걸리는지 아시나요?!";//아재5
      */
      
      int n = rand()%4;

      if(n==0){
         imageDraw(Npc,5,210);
         imageDraw("아재2.txt",150, 210);

         imageDraw("아재6.txt",5,232);
         imageDraw("아재7.txt",5,247);
         imageDraw("아재8.txt",5,262);

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
            imageDraw("아재9.txt",150, 210);
            Sleep(1000);
            imageDraw("호감도상승.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210); 
            imageDraw("아재11.txt",150, 210);
            Sleep(1000);
            imageDraw("분위기.txt",5,230);
            Sleep(500);
            imageDraw("호감도하락.txt",5,242);
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
         imageDraw("아재3.txt",150, 210);

         imageDraw("아재12.txt",5,232);
         imageDraw("아재13.txt",5,247);
         imageDraw("아재14.txt",5,262);

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
            imageDraw("아재9.txt",150, 210);
            Sleep(1000);
            imageDraw("호감도상승.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210); 
            imageDraw("아재15.txt",150, 210);
            Sleep(1000);
            imageDraw("분위기.txt",5,230);
            Sleep(500);
            imageDraw("호감도하락.txt",5,242);
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
         imageDraw("아재4.txt",150, 210);

         imageDraw("아재16.txt",5,232);
         imageDraw("아재17.txt",5,247);
         imageDraw("아재18.txt",5,262);

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
            imageDraw("아재9.txt",150, 210);
            Sleep(1000);
            imageDraw("호감도상승.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210); 
            imageDraw("아재19.txt",150, 210);
            Sleep(1000);
            imageDraw("분위기.txt",5,230);
            Sleep(500);
            imageDraw("호감도하락.txt",5,242);
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
         imageDraw("아재5.txt",150, 210);

         imageDraw("아재20.txt",5,232);
         imageDraw("아재21.txt",5,247);
         imageDraw("아재22.txt",5,262);

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
            imageDraw("아재9.txt",150, 210);
            Sleep(1000);
            imageDraw("호감도상승.txt",5,230);
            getPlayer().setHeart(5);
            Sleep(2000);
            imageDraw("thirdBlank.txt",3,210);
            imageDraw("thirdBlank.txt",200,210);
            imageDraw("thirdBlank.txt",230,210);
            return 1;
         }
         else {
            imageDraw(Npc,5,210); 
            imageDraw("아재23.txt",150, 210);
            Sleep(1000);
            imageDraw("분위기.txt",5,230);
            Sleep(500);
            imageDraw("호감도하락.txt",5,242);
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

       imageDraw("다음대화주제를선택하자.txt",5,210);

        if(rand[1] == 1){
         if(complete[1]==-1){
            gotoxy(3,222); 
            //,"2.  상식 퀴즈 "); //메뉴2
            imageDraw("1.상식퀴즈.txt",5,230);
         }
         if(complete[2]==-1){
            gotoxy(3,234); 
            //"3.  운명의 음료 선택 게임"); //메뉴3
            imageDraw("2.운명의음료선택게임.txt",200,230);
         }
         if(complete[3]==-1){
            gotoxy(3,246);
            //"4.  아재개그"); //메뉴4
            imageDraw("3.아재개그.txt",5,245);
         }
         if(complete[4]==-1){
            gotoxy(3,258);
            //"5.  대화를 마친다."); //메뉴5
            imageDraw("4.대화를마친다.txt",200,245);
         }
        }
        else{
         if(complete[1]==-1){
            gotoxy(3,222); 
            //,"2.  상식 퀴즈 "); //메뉴2
            imageDraw("1.상식퀴즈.txt",5,230);
         }
         if(complete[2]==-1){
            gotoxy(3,234); 
            //"3.  운명의 음료 선택 게임"); //메뉴3
            imageDraw("2.운명의음료선택게임.txt",5,245);
         }
         if(complete[4]==-1){
            gotoxy(3,258);
            //"5.  대화를 마친다."); //메뉴5
            imageDraw("3.대화를마친다.txt",5,260);
         }
        }


      }

   void conversation(){// 만남의 게임

      srand((unsigned int)time(NULL)); 
      //int randGame[3]; //아재, 댄스, 날씨

      //이름 맞추기 게임, 상식 퀴즈, 운명의 음료 선택 게임, 아재 개그, 대화를 마친다.
      int complete[5] = {-1,-1,-1,-1,-1};

      //날씨이벤트 발생 여부, 아재개그 발생 여부, 댄스 타임 발생 여부
      int a = rand()%2;
      int b = rand()%2;
      int c = rand()%2;
      int rand[3] = {a,b,c};
   
      //thirdStageBaseGame[3]; //이름 맞추기 게임, 상식 퀴즈, 음료선택(커피/주스/쌍화탕) 결과 (0=실패, 1=성공)  

      imageDraw("thirdBlank.txt",3,210);imageDraw("thirdBlank.txt",200,210);

      // 카페에 도착했다.
      imageDraw("카페에도착했다.txt",5,210);
      Sleep(1300);
      // 저 멀리 상대가 보인다.
      imageDraw("저멀리상대가보인다.txt",5,230);
      Sleep(1300);
      //이름 맞추기 게임
      thirdStageBaseGame[0] = namePick();
      complete[0] = thirdStageBaseGame[0];
      
      char temp;
      char temp2 = '0';
      int pick;
      
      if(rand[1]==1){ //아재 개그 발생
         while(1){
            ConversationListDraw(rand,complete);
            temp = getch();
            pick = (int)(temp - temp2);
         
            if(complete[1]==-1&&pick==1){//상식 퀴즈
               thirdStageBaseGame[1] = quiz();
               complete[1] = thirdStageBaseGame[1];
			   if(rand[2]==1)
				 randGame[1] = danceTime();
            }
            else if(complete[2]==-1&&pick==2){//음료선택게임
               thirdStageBaseGame[2] = drinkPick();
               complete[2] = thirdStageBaseGame[2];
            }
            else if(complete[3]==-1&&pick==3){//아재개그
               // randGame[3]; //아재, 댄스, 날씨
               randGame[0] = gagPick();
               complete[3] = randGame[0];
            }
            else if(pick==4){//대화마치기 
               if(rand[0]==1){
                  if(player.stringItems()=="우산"){
                     imageDraw("우산있음.txt",30,25);
                     getPlayer().setHeart(5);
                     randGame[2] = 1;
                  }
                  else{
                     imageDraw("우산없음.txt",30,25);
                     getPlayer().setHeart(-5);
                     randGame[2] = 0;
                  }
                  Sleep(3000);
               }
               break;
            }
         }
      }
      else{ //아재 개그 발생하지 않음.
         while(1){
            ConversationListDraw(rand,complete);
            temp = getch();
            pick = (int)(temp - temp2);
         
            if(complete[1]==-1&&pick==1){//상식 퀴즈 
               thirdStageBaseGame[1] = quiz();
               complete[1] = thirdStageBaseGame[1];
			   if(rand[2]==1)
				 randGame[1] = danceTime();
            }
            else if(complete[2]==-1&&pick==2){//음료 선택 게임
               thirdStageBaseGame[2] = drinkPick();
               complete[2] = thirdStageBaseGame[2];
            }
            else if(pick==3){//대화마치기
               if(rand[0]==1){
                  if(player.stringItems()=="우산"){
                     imageDraw("우산있음.txt",30,25);
                     getPlayer().setHeart(5);
                     randGame[2] = 1;
                  }
                  else{
                     imageDraw("우산없음.txt",30,25);
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

      // thirdStageBaseGame[3] 이름 맞추기 게임, 상식 퀴즈, 음료선택(커피/주스/쌍화탕) 결과 (0=실패, 1=성공)
	  selectCafeOutLineDraw(); //카페이름출력 
	  
      imageDraw("ground100(2).txt",5,195);
      imageDraw("ground100(2).txt",104,195);
      imageDraw("ground100(2).txt",203,195);
      imageDraw("ground100(2).txt",302,195);
      imageDraw("ground100(2).txt",401,195);
      imageDraw("ground100(2).txt",500,195);
      imageDraw("ground100(2).txt",599,195);
	  imageDraw("카페100.txt",590,150); 
      imageDraw("ceil200.txt",5,30);
      imageDraw("ceil200.txt",204,30);
      imageDraw("ceil200.txt",403,30);


      imageDraw("back600(2).txt",4,60);
      
      imageDraw("chair180.txt",10,160);
      imageDraw("chair180.txt",360,160);

   
      int x=50;
      int y =200;
      imageDraw("앞1.txt",210,168);
      imageDraw("ASCIIART_(2).txt",280,165);
   
      conversation();

   
      gotoxy(500,500);


   }

	
	void intro(){
		//font size 5 설정
		introInit();
		//intro 출력
        introMain();
		//화면 비우기
		system("cls");

	}
	void story(){
		//font size 5 설정
		introInit();
		//intro 출력
		storyMain();
		//화면 비우기
		system("cls");

	}

	void motorcycle(){
		//font size 5 설정
		introInit();
		//intro 출력
		motorMain();
		//화면 비우기
		system("cls");

	}

	void success(){
		//font size 5 설정
		introInit();
		//intro 출력
		successMain();
		imageDraw("게임재시작200.txt",153,40);

	}

	void failure(){
		//font size 5 설정
		introInit();
		//intro 출력
		failureMain();
		imageDraw("게임재시작200.txt",153,40);
		

	}

	void selectLevel(){
		//level menu draw
		keyDraw();
		init();
		int x = 34;
		int y = 14;
		int pick;
		bool whileTrue = true;
   		gotoxy(16,8,"《난이도 선택》");
		gotoxy(7,10,"EASY:호감도 50↑| NORMAL:호감도 60↑| HARD:호감도 70↑");
		gotoxy(x-2,y); //14
		printf("◎  EASY");
		gotoxy(x,y+1); //15
		printf("  NORMAL");
		gotoxy(x,y+2);  //16
		printf("  HARD");
   
		while(whileTrue){
			int select = keyControl();
      
			switch(select){
				case UP: {
					if(y>14){ //y는 14-16까지만 이동  
						gotoxy(x-2,y);
						printf("   ");
						gotoxy(x-2,--y);
						printf("◎");
					}
						break;
				 }   
				case DOWN: {
					if(y<16){ //최대 16까지만 이동 가능  
						gotoxy(x-2,y);
						printf("   ");
						gotoxy(x-2,++y);
						printf("◎");
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
			cout<<"◎ 난이도 easy를 선택하셨습니다.";
			level="easy";
		}
		else if(pick == 1){
			gotoxy(x-10,15);
			cout<<"◎ 난이도 normal를 선택하셨습니다.";
			level="normal";
		}
		else if(pick == 2){
			gotoxy(x-10,16);
			cout<<"◎ 난이도 hard를 선택하셨습니다.";
			level="hard";
		}

	}

	void selectName(){
		//프로그램 실행시마다 랜덤값 발생
		//stdlib, time 헤더 포함
		keyDraw();
		srand((unsigned int)time(NULL));

		gotoxy(16,8,"《사용자 이름 선택》");
		int name=rand()%(4);
		gotoxy(17,13,"");
		cout<<nameArray[name];
    
   
		gotoxy(14,10,"새로고침은 4번을 눌러주세요");
    
		int key;
		while(1){
			key = getch();
    
			if(key == ' '){
				gotoxy(8,16,"선택하신 이름은'");
				gotoxy(18,16,"");
				cout<<nameArray[name]<<"      ' 입니다.";
				player.setName(nameArray[name]); 
				break;
			}
			else if(key == 52){// 새로고침  
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
		gotoxy(16,8,"《성별선택》 ");
		gotoxy(x-2,y); //13
		printf("◎  WOMAN");
		gotoxy(x,y+1); //14
		printf("  MAN");
		gotoxy(x,y+2);  //15
		printf("  SECRET");
   
		while(whileTrue){
			int select = keyControl();
      
			switch(select){
				case UP: {
					if(y>13){ //y는 13-15까지만 이동  
						gotoxy(x-2,y);
						printf("   ");
						gotoxy(x-2,--y);
						printf("◎");
					}
					break;
				}   
				case DOWN: {
					if(y<15){ //최대 15까지만 이동 가능  
						gotoxy(x-2,y);
						printf("   ");
						gotoxy(x-2,++y);
						printf("◎");
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
			cout<<"◎  성별  woman을 선택하셨습니다.";
			string gender="woman";
			player.setGender(gender);
		}
		else if(pick == 1){
			gotoxy(x-12,14);
			cout<<"◎  성별  man을  선택하셨습니다.";
			string gender="man";
			player.setGender(gender);
		}
   
		else if(pick == 2){
			gotoxy(x-12,15);
			cout<<"◎  성별  secret을 선택하셨습니다.";
			string gender="secret";
			player.setGender(gender);
		}
   
		gotoxy(20,20," ");

	}

	void personINFO(){
		draw1();
		gotoxy(17,7,"√사용자 정보√ ");
		gotoxy(14,9,"상대방 이름: ");
		cout<<computer.getName();
		gotoxy(14,11,"나의 이름: ");
		cout<<player.getName();
		gotoxy(14,13,"성별: ");
		cout<<player.getGender();
		gotoxy(14,15,"난이도: ");
		cout<<level<<endl;
		gotoxy(8,17,"스페이스바를 누르면 꿈깨기 게임이 바로 실행됩니다.");
		gotoxy(11,19,"꿈에서 무사히 빠져나가길 기대할게요♥");
		gotoxy(17,21,"〔SPACEBAR〕");
		
		while(1){

        if(kbhit()){ //키입력받음 
            char key=getch();
            if(key==' ') return; // ESC키면 종료 
            else break; //아니면 그냥 계속 진행 
        } 

        gotoxy(17,21," 〔SPACEBAR〕 ");
        Sleep(400);
        gotoxy(17,21,"               ");
        Sleep(400);
    }
		
		

		
		Sleep(100000);


	}


	void firstStage(){

		//fontSIze 16 설정
		Init();

		//난이도 선택, 이름, 성별 선택
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

		//화면 비우기
		system("cls");

	}
	
	void secondStage(){
		// 맵과 각종 미니게임
		miniGameResult[0] = wakeUpGame();
		Sleep(1500);
		system("cls");
		//font size 1 설정
		changeInit();
		//거실
		int miniGame;
		int mapX = 66;
		int mapY = 124;
		bool first = true;
		while(true){
			miniGame = livingRoom(mapX,mapY, first);
			//화장실 가기 5, 옷고르기 6, 소지품 고르기 7, 외출하기 8
			if(miniGame==5){
				//화장실 맵
				toiletGame(miniGameResult, seasonNumber);
				mapX=625;
				mapY=100;
				first = false;
				//x y 좌표 변경
			}
			if(miniGame==6){
				//옷고르기 게임
				selectClothesGame(player);
				//x y 좌표 변경
				mapX = 425;
				mapY = 70;
				first = false;
			}
			if(miniGame==7){
				//소지품 고르기 게임
				selectItemsGame(player);
				//x y 좌표 변경
				mapX = 100;
				mapY = 70;
				first = false;
			}
			if(miniGame==8){
				//2단계 종료
				break;
			}
			if(miniGame==-100){
				// QUIT
				break;
			}
		}

		//화면 비우기
		system("cls");

	}

	void thirdStage(){
		// 만남의 게임

		//fontsize 1
		changeInit();

		// thirdStageBaseGame[3] 이름 맞추기 게임, 상식 퀴즈, 음료선택(커피/주스/쌍화탕) 결과 (0=실패, 1=성공)
		cafeMap();


		//화면 비우기
		system("cls");
	}

	void secondResult(){
      //fonstSize 16 설정
      Init();

      //각 종 미니게임에 대한 결과 출력 함수
      //temp : 각 미니게임 결과에 따른 호감도 변동값 임시 저장소
      draw2();
      keyDraw();
      int temp = 0;
      //출력할 좌표
      int x = 20; int y = 10;
      gotoxy(13,4,"《2단계 게임 결과》");
      gotoxy(x,y++);
      gotoxy(5,9,"처음 호감도 ♥");
      gotoxy(16,9," 100");
      for(int i=0;i<5;i++){
         if(miniGameResult[i]==0) {
            //게임 결과가 실패이면 호감도 -30 or -10
            if(i==0){
               //꿈깨기 게임이면
               temp = -30;
               player.setHeart(temp);
               gotoxy(10,y,"   -         ");
               gotoxy(30,y);
               cout <<"    "<<"30";
               gotoxy(30,y,"실패!");
               gotoxy(x+20, y++);
               cout <<"  "<<miniGameName[i];
               gotoxy(x+20, y++);
            }
            else {
               //꿈깨기 게임이 아니면 
               temp = -10;
               player.setHeart(temp);
               gotoxy(10,y,"   -         ");
               gotoxy(30,y);
               cout <<"    "<<"10";
               gotoxy(30,y,"실패!");
               gotoxy(x+20, y++);
               cout <<"  "<<miniGameName[i];
               gotoxy(x+20, y++);
            }
         }
         else {
            //게임 결과가 성공이면 호감도 변동 없음.
            gotoxy(x+2,y);
            gotoxy(10,y,"   -         ");
            gotoxy(30,y);
            cout <<"     0";
            gotoxy(30,y,"성공!");
            gotoxy(x+20, y++);
            cout <<"  "<<miniGameName[i];// << " 성공!";
            gotoxy(x+20, y++);
         }
      }
      gotoxy(10,y,"━━━━━━━━━━━━━━━━━━━");
      gotoxy(3,y+2,"현재 남은 호감도  ♥");
      gotoxy(17,23,""); 
      cout << player.getHeart();
      gotoxy(0,31,""); 
      
      //호감도 출력 1초 유지
      Sleep(2500);

      //화면 초기화
      system("cls");

      secondStageScore = player.getHeart();


   }
	
	void thirdResult(){  

      //fonstSize 16 설정
      Init();
	  draw3();
	  gotoxy(13,4,"《3단계 게임 결과》");
      gotoxy(5,9,"처음 호감도 ♥");
      gotoxy(15,9,"");
	  

      // 차분한 김상중, 자유로운 신동엽, 엉뚱한 노사연, 보수적인 양희은
       string Tops[4] = {"나시","반팔","정장","패딩"};
       string Pants[4] = {"추리닝","반바지","긴바지","슬랙스"};
       string Shoes[4] = {"슬리퍼","샌들","운동화","구두"};

      // 옷 입히기 게임에 의한 호감도 변동
      int hateCount = 0; //몇개의 옷이 computer와 맞지 않는가?
      int badCount = 0; //몇개의 옷이 계절과 맞지 않는가?
      string top = player.getClothes().getTop();
      string pants = player.getClothes().getPants();
      string shoes = player.getClothes().getShoes();

      if(computer.getName()=="차분한 김상중"){ 
         //차분한 <-> 추리닝, 슬리퍼
         if (pants == Pants[0]){
            hateCount++;
         }
         if (shoes == Shoes[0]){
            hateCount++;
         }   
      }
      else if(computer.getName()=="자유로운 신동엽"){ 
         //자유로운 <-> 정장,구두 
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
      else if(computer.getName()=="엉뚱한 노사연"){
         //엉뚱한 <-> 반팔, 긴바지, 운동화
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
      else if(computer.getName()=="보수적인 양희은"){
         //보수적인 <-> 민소매, 반바지, 샌들
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

      if(season=="여름"){
         if(top==Tops[3]){
            badCount++;
         }
      }
      else if(season=="겨울"){
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

      //출력할 좌표
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
         cout<<"'" << computer.getName() << "' 이 선호하지 않는 옷을 입음";
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
         cout <<"'"<< season << "' 에 맞지 않는 옷을 입음";
		 gotoxy(x+10,y++);
      }
      if(player.stringItems()=="목도리"||player.stringItems()=="손난로"){
         if(season=="겨울"){
            player.setHeart(5);
            gotoxy(x,y);
            cout << "  +        5";
            gotoxy(x+10,y++);
            cout <<"      '" << season << "' 에 맞는 소지품을 들음";
			gotoxy(x+10,y++);
         }
      }
      if(player.stringItems()=="휴대용 선풍기"){
         if(season=="여름"){
            player.setHeart(5);
            gotoxy(x,y);
            cout << "  +        5";
            gotoxy(x+10,y++);
            cout <<"      '" << season << "' 에 맞는 소지품을 들음";
			gotoxy(x+10,y++);
         }
      }
      if(player.stringItems()=="손수건"){
         if(computer.getName()=="차분한 김상중" || computer.getName()=="보수적인 양희은" ){
            player.setHeart(5);
            gotoxy(x,y);
            cout << "  +        5";
            gotoxy(x+10,y++);
            cout <<"'"<< computer.getName() << "' 이 선호하지 않는 소지품을 들음";
			gotoxy(x+10,y++);
         }
      }
      if(player.stringItems()=="향수"||player.stringItems()=="거울"||player.stringItems()=="꽃다발"||player.stringItems()=="보조배터리"){
         gotoxy(x,y);
         cout << "  +        5";
         gotoxy(x+10,y++);
         cout <<"      '" << "외출에 유용한 소지품을 들음";
		 gotoxy(x+10,y++);
      }

      // 이름 맞추기 게임, 상식 퀴즈, 음료선택(커피/주스/쌍화탕) 
	  for(int i=0;i<3;i++){
         if(thirdStageBaseGame[i]==0){
            // 게임 실패 -> 호감도 10 감소
            gotoxy(x,y);
			player.setHeart(-5);
			gotoxy(10,y,"  -         5");
            gotoxy(x+15,y++);
            cout <<"  "<< thirdStageBaseGameName[i];
			gotoxy(x+10,y-1,"실패!");
			gotoxy(x+15,y++);
			
         }
         else{
            // 게임 성공 -> 호감도 10 증가
            gotoxy(x,y);
			player.setHeart(+5);
            gotoxy(10,y,"  +         5");
            gotoxy(x+15,y++);
            cout <<"  "<< thirdStageBaseGameName[i];
			gotoxy(x+10,y-1,"성공!");
			gotoxy(x+15,y++);

         }
      }

      // randGame[3]; //아재, 댄스, 날씨, -1 실행안함 0 실패 1 성공
      if(randGame[0]==0){
         gotoxy(x,y);
         gotoxy(10,y,"  -         5");
         gotoxy(x+10,y++);
         cout <<"  "<< randGameName[0];// << " 오답";
		 gotoxy(x+10,y-1,"오답!");
		 gotoxy(x+15,y++);
      }
      if(randGame[0]==1){
         gotoxy(x,y);
         gotoxy(10,y,"  +         5");
         gotoxy(x+15,y++);
         cout <<"  "<< randGameName[0];// << " 정답";
		 gotoxy(x+10,y-1,"정답!");
		 gotoxy(x+15,y++);
      }
      if(randGame[1]==1){
         gotoxy(x,y);
         gotoxy(10,y,"  -         5");
         gotoxy(x+10,y++);
         cout <<"  "<< randGameName[1];// << " 성공";
		 gotoxy(x+10,y-1,"성공!");
		 gotoxy(x+15,y++);
      }
      if(randGame[2]==1){
         gotoxy(x,y);
         gotoxy(10,y,"  +         5");
         gotoxy(x+15,y++);
         cout <<"  "<< randGameName[2] ;//<< " 성공";
		 gotoxy(x+10,y-1,"성공!");
		 gotoxy(x+15,y++);
      } 
	  if(randGame[2]==0){
         gotoxy(x,y);
         gotoxy(10,y,"  -         5");
         gotoxy(x+15,y++);
         cout <<"  "<< randGameName[2] ;//<< " 실패";
		 gotoxy(x+10,y-1,"실패!");
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
      
	  gotoxy(10,y,"━━━━━━━━━━━━━━━━");
      gotoxy(2,y+2,"현재 남은 호감도  ♥");
      //gotoxy(17,18,""); 
	  cout <<"       " <<player.getHeart();
      gotoxy(0,31,""); 
      //출력 화면 유지
      Sleep(2500);

      //화면 비우기
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


