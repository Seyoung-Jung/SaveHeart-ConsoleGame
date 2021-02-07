#ifndef __UTIL_H__
#define __UTIL_H__
#include "util.h"
#endif

using namespace std;


void cafeImageDraw(const char* name, int x,int y){

   //       BBBB BBB \n
   // _ 이전까지 한글자씩 받고 x++
   // _부터 \n 이전까지 받고 출력, y++
   char Buffer[200];
   for(int i=0;i<200;i++){
      Buffer[i] = '.';
   }
   char Temp[1000];
   char front;
   char frontLine[500];
   FILE *image = NULL;
   char eol;
   char start;
   int tempX = x;
   fopen_s(&image, name, "r");
   bool first = false;
   if(image==NULL)
      return;

   //feof()는 파일의 끝일때 0이 아닌 값(=참)을 반환
   
   while(!feof(image)){
      fscanf(image,"%[^\n]s", Buffer);
      fscanf(image,"%c",&eol);
      strcpy(Temp, Buffer);
      for(int i=0;i<200;i++){
         if(Buffer[i]=='.'){
            break;
         }
         if(first==false && Buffer[i] ==' '){
            tempX++;
         }
         else if(first==false && Buffer[i]!=' '){
            first = true;
            gotoxy(tempX++,y);
            putc(' ',stdout);
            gotoxy(tempX++,y);
            putc(' ',stdout);
            gotoxy(tempX++,y);
            putc(Buffer[i],stdout);
         }
         else if(first==true){
            gotoxy(tempX++,y);
            putc(Buffer[i],stdout);
         }
      }
      tempX = x;
      y++;
      first = false;
      for(int i=0;i<200;i++){
      Buffer[i] = '.';
      }
   }
   fclose(image);
}

void draw3(){
gotoxy(0,1,"♡━━━━ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ♡    ");
gotoxy(0,2,"┃┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓┃"); 
gotoxy(0,3,"┃┃                                                                               ┃┃");
gotoxy(0,4,"┃┃                                                                               ┃┃");
gotoxy(0,5,"┃┃                                                                               ┃┃");
gotoxy(0,6,"┃┃                                                                               ┃┃");
gotoxy(0,7,"┃┃                                                                               ┃┃");	
gotoxy(0,8,"┃┃                                                                               ┃┃");
gotoxy(0,9,"┃┃                                                                               ┃┃");
gotoxy(0,10,"┃┃                                                                               ┃┃");
gotoxy(0,11,"┃┃                                                                               ┃┃");
gotoxy(0,12,"┃┃                                                                               ┃┃");
gotoxy(0,13,"┃┃                                                                               ┃┃");
gotoxy(0,14,"┃┃                                                                               ┃┃");
gotoxy(0,15,"┃┃                                                                               ┃┃");
gotoxy(0,16,"┃┃                                                                               ┃┃");
gotoxy(0,17,"┃┃                                                                               ┃┃");
gotoxy(0,18,"┃┃                                                                               ┃┃");
gotoxy(0,19,"┃┃                                                                               ┃┃");
gotoxy(0,20,"┃┃                                                                               ┃┃");
gotoxy(0,21,"┃┃                                                                               ┃┃");
gotoxy(0,22,"┃┃                                                                               ┃┃");
gotoxy(0,23,"┃┃                                                                               ┃┃");
gotoxy(0,24,"┃┃                                                                               ┃┃");
gotoxy(0,25,"┃┃                                                                               ┃┃");
gotoxy(0,26,"┃┃                                                                               ┃┃");
gotoxy(0,27,"┃┃                                                                               ┃┃");
gotoxy(0,28,"┃┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛┃ ");
gotoxy(0,29,"♡━━━━ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ♡ ");

}


void draw2(){
gotoxy(0,1,"♡━━━━ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ♡    ");
gotoxy(0,2,"┃┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓┃"); 
gotoxy(0,3,"┃┃                                                                    ┃┃");
gotoxy(0,4,"┃┃                                                                    ┃┃");
gotoxy(0,5,"┃┃                                                                    ┃┃");
gotoxy(0,6,"┃┃                                                                    ┃┃");
gotoxy(0,7,"┃┃                                                                    ┃┃");	
gotoxy(0,8,"┃┃                                                                    ┃┃");
gotoxy(0,9,"┃┃                                                                    ┃┃");
gotoxy(0,10,"┃┃                                                                    ┃┃");
gotoxy(0,11,"┃┃                                                                    ┃┃");
gotoxy(0,12,"┃┃                                                                    ┃┃");
gotoxy(0,13,"┃┃                                                                    ┃┃");
gotoxy(0,14,"┃┃                                                                    ┃┃");
gotoxy(0,15,"┃┃                                                                    ┃┃");
gotoxy(0,16,"┃┃                                                                    ┃┃");
gotoxy(0,17,"┃┃                                                                    ┃┃");
gotoxy(0,18,"┃┃                                                                    ┃┃");
gotoxy(0,19,"┃┃                                                                    ┃┃");
gotoxy(0,20,"┃┃                                                                    ┃┃");
gotoxy(0,21,"┃┃                                                                    ┃┃");
gotoxy(0,22,"┃┃                                                                    ┃┃");
gotoxy(0,23,"┃┃                                                                    ┃┃");
gotoxy(0,24,"┃┃                                                                    ┃┃");
gotoxy(0,25,"┃┃                                                                    ┃┃");
gotoxy(0,26,"┃┃                                                                    ┃┃");
gotoxy(0,27,"┃┃                                                                    ┃┃");
gotoxy(0,28,"┃┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛┃ ");
gotoxy(0,29,"♡━━━━ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ♡ ");

}

void draw1(){
gotoxy(5,5,"▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩"); 
gotoxy(5,6,"▩▩                                                    ▩▩");
gotoxy(5,7,"▩  ▩                                                ▩  ▩");
gotoxy(5,8,"▩                                                        ▩");
gotoxy(5,9,"▩                                                        ▩");
gotoxy(5,10,"▩                                                        ▩");
gotoxy(5,11,"▩                                                        ▩");
gotoxy(5,12,"▩                                                        ▩");
gotoxy(5,13,"▩                                                        ▩");
gotoxy(5,14,"▩                                                        ▩");
gotoxy(5,15,"▩                                                        ▩");
gotoxy(5,16,"▩                                                        ▩");
gotoxy(5,17,"▩                                                        ▩");
gotoxy(5,18,"▩                                                        ▩");
gotoxy(5,19,"▩                                                        ▩");
gotoxy(5,20,"▩                                                        ▩");
gotoxy(5,21,"▩  ▩                                                ▩  ▩");
gotoxy(5,22,"▩▩                                                    ▩▩ ");
gotoxy(5,23,"▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");
}
 
void keyDraw(){
gotoxy(41,13," ┏━━━━┓");
gotoxy(41,14," ┃  W ┃");
gotoxy(39,15,"┏━━━━╋━━━━╋━━━━┓");
gotoxy(39,16,"┃  A ┃  S ┃  D ┃");
gotoxy(39,17,"┗━━━━┻━━━━┻━━━━┛");

gotoxy(49,15,"┏━━━━━━━━━━━━━┓");
gotoxy(49,16,"┃     SPACE   ┃");
gotoxy(49,17,"┗━━━━━━━━━━━━━┛");

gotoxy(42,19,"방향키");
gotoxy(51,19," 선택키");
} 

void imageDraw(const char* name, int x,int y){
	char Buffer[1000];
	char Temp[1000];
	FILE *image = NULL;
	char eol;
	fopen_s(&image, name, "r");

	if(image==NULL)
		return;

	//feof()는 파일의 끝일때 0이 아닌 값(=참)을 반환
	fscanf(image,"%[^\n]s", Buffer);
	fscanf(image,"%c",&eol);
	while(!feof(image)){
		gotoxy(x,y++);
		strcpy(Temp, Buffer);
		puts(Temp);
		fscanf(image,"%[^\n]s", Buffer);
		fscanf(image,"%c",&eol);
	}

	fclose(image);
}

void charImageDraw(const char* name, int x,int y){

	//       _BBBB BBB \n
	// _ 이전까지 한글자씩 받고 x++
	// _부터 \n 이전까지 받고 출력, y++
	char Buffer[100];
	for(int i=0;i<100;i++){
		Buffer[i] = '.';
	}
	char Temp[1000];
	char front;
	char frontLine[500];
	FILE *image = NULL;
	char eol;
	char start;
	int tempX = x;
	fopen_s(&image, name, "r");
	bool first = false;
	if(image==NULL)
		return;

	//feof()는 파일의 끝일때 0이 아닌 값(=참)을 반환
	
	while(!feof(image)){
		fscanf(image,"%[^\n]s", Buffer);
		fscanf(image,"%c",&eol);
		strcpy(Temp, Buffer);
		for(int i=0;i<100;i++){
			if(Buffer[i]=='.'){
				break;
			}
			if(first==false && Buffer[i] !='B'){
				tempX++;
			}
			else if(first==false && Buffer[i]=='B'){
				first = true;
				gotoxy(tempX++,y);
				putc(' ',stdout);
				gotoxy(tempX++,y);
				putc(' ',stdout);
				gotoxy(tempX++,y);
				putc(Buffer[i],stdout);
			}
			else if(first==true){
				gotoxy(tempX++,y);
				putc(Buffer[i],stdout);
			}
		}
		tempX = x;
		y++;
		first = false;
		for(int i=0;i<100;i++){
		Buffer[i] = '.';
		}
	}
	fclose(image);
}


void BasicOutlineDraw(){
	system("cls");
	changeInit();
	imageDraw("가로100.txt",0,0);
	imageDraw("세로.txt",0,2);
	imageDraw("세로.txt",697,2);
	imageDraw("가로100.txt",0,277); 
	imageDraw("wasd100.txt",800,100);
	imageDraw("space100.txt",950,100);
	imageDraw("방향키9.txt",825,150);
	imageDraw("선택키9.txt",975,150);
	imageDraw("도움말9.txt",1105, 265);
	imageDraw("help30.txt", 1117, 240);
}
void selectClothesOutlineDraw(){
	BasicOutlineDraw();
	imageDraw("가로100.txt",0,25);
	imageDraw("옷장10.txt",300,7);
	imageDraw("가로100.txt",0,200);
}

void selectItemsOutlineDraw(){
	BasicOutlineDraw();
	imageDraw("가로100.txt",0,25);
	imageDraw("소지품50.txt",300,7);
	imageDraw("가로100.txt",0,200);
}


void selectLivingOutLineDraw(){
	imageDraw("가로100.txt",0,25);
	imageDraw("거실10.txt",300,7);
	imageDraw("가로100.txt",0,200);
}



void selectCafeOutLineDraw(){
	// BasicOutlineDraw();
	imageDraw("가로100.txt",0,25);
	imageDraw("카페10.txt",300,7);
	imageDraw("가로100.txt",0,200);
}


void selectItemsMainMenuDraw(){
	imageDraw("최종선택30.txt",7,205);

	imageDraw("왼쪽화살표9.txt",50,150);
//	imageDraw("왼쪽화살표9.txt",270,150);
//	imageDraw("왼쪽화살표9.txt",500,150);

	imageDraw("weather100.txt",70,80);
	imageDraw("날씨9.txt",100,150);
	imageDraw("sense100.txt",290,80);
	imageDraw("센스9.txt",320,150);
	imageDraw("mood100.txt",510,80);
	imageDraw("분위기9.txt",535,150);
}

void selectClothesMainMenuDraw(){
	imageDraw("패션아이템9.txt",7,205);
    imageDraw("카테9.txt",7,217);
    imageDraw("최종선택1009.txt",7,229);

	imageDraw("왼쪽화살표9.txt",50,150);
//	imageDraw("왼쪽화살표9.txt",270,150);
//	imageDraw("왼쪽화살표9.txt",500,150);

	imageDraw("top100.txt",70,80);
	imageDraw("상의9.txt",100,150);
	imageDraw("pants100.txt",290,80);
	imageDraw("하의9.txt",320,150);
	imageDraw("shoes100.txt",510,80);
	imageDraw("신발9.txt",550,150);
}

int topDraw(){
	
//	Draw();
	selectClothesOutlineDraw();


	imageDraw("왼쪽화살표9.txt",70,150);

	imageDraw("sleeve100.txt",65,80);
	imageDraw("나시9.txt",100,150);
	imageDraw("top100.txt",215,80);
	imageDraw("반팔9.txt",250,150);
	imageDraw("shirt100.txt",365,80);
	imageDraw("정장9.txt",400,150);
	imageDraw("padding100.txt",515,80);
	imageDraw("패딩9.txt",550,150);

//  '>'의 x,y 좌표
//	imageDraw("왼쪽화살표9.txt",70,150);
//	imageDraw("왼쪽화살표9.txt",220,150);
//	imageDraw("왼쪽화살표9.txt",370,150);
//	imageDraw("왼쪽화살표9.txt",520,150);

	int x=70;
	int y=150;
	//나시
	imageDraw("땡땡9.txt",7,205);
	imageDraw("나시9.txt",25,205);
	
	imageDraw("보수적인9.txt",7,220);
	imageDraw("사람은9.txt",80,220);
	imageDraw("선호하지않음9.txt",145,220);

	imageDraw("겨울에9.txt",7,230);
	imageDraw("어울리지않음9.txt",70,230);



	while(true){
		//사용자가 입력한 값을 n으로(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//기존 '>' 지워주기
				//'>' 출력(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					x=370; //정장

					imageDraw("clothesBlank.txt",7,205);

					//boxClear(7,205);

					imageDraw("땡땡9.txt",7,205);
					imageDraw("정장9.txt",25,205);
	
					imageDraw("자유로운9.txt",7,220);
					imageDraw("사람은9.txt",80,220);
					imageDraw("선호하지않음9.txt",145,220);



				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					x=220; //반팔

					imageDraw("clothesBlank.txt",7,205);
					// boxClear(7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("반팔9.txt",25,205);
	
					imageDraw("엉뚱한9.txt",7,220);
					imageDraw("사람은9.txt",70,220);
					imageDraw("선호하지않음9.txt",145,220);



				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",70,150);
					x=70; //나시
					imageDraw("clothesBlank.txt",7,205);
					// boxClear(7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("나시9.txt",25,205);
	
					imageDraw("보수적인9.txt",7,220);
					imageDraw("사람은9.txt",80,220);
					imageDraw("선호하지않음9.txt",145,220);

					imageDraw("겨울에9.txt",7,230);
					imageDraw("어울리지않음9.txt",70,230);

				}
				break;
			}
			case RIGHT : {
				//기존 '>' 지워주기
				//'>' 출력(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					x=220; //반팔
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("반팔9.txt",25,205);
	
					imageDraw("엉뚱한9.txt",7,220);
					imageDraw("사람은9.txt",70,220);
					imageDraw("선호하지않음9.txt",145,220);


				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					x=370; //정장
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("정장9.txt",25,205);
	
					imageDraw("자유로운9.txt",7,220);
					imageDraw("사람은9.txt",80,220);
					imageDraw("선호하지않음9.txt",145,220);

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",520,150);
					x=520; //패딩
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("패딩9.txt",25,205);

					imageDraw("여름에9.txt",7,220);
					imageDraw("어울리지않음9.txt",70,220);

				}
				break;
			}
			case SUBMIT : {
				if(x==70) return 0;
				else if(x==220) return 1;
				else if(x==370) return 2;
				else if(x==520) return 3;
			}
		}

	}

}
int pantsDraw(){
	
//	Draw();
	selectClothesOutlineDraw();

	imageDraw("왼쪽화살표9.txt",70,150);

	imageDraw("추리닝100.txt",70,80);
	imageDraw("추리닝9.txt",100,150);
	imageDraw("반바지100.txt",220,80);
	imageDraw("반바지9.txt",250,150);
	imageDraw("긴바지100.txt",370,80);
	imageDraw("긴바지9.txt",400,150);
	imageDraw("슬랙스100.txt",520,80);
	imageDraw("슬랙스9.txt",550,150);

//  '>'의 x,y 좌표
//	imageDraw("왼쪽화살표9.txt",70,150);
//	imageDraw("왼쪽화살표9.txt",220,150);
//	imageDraw("왼쪽화살표9.txt",370,150);
//	imageDraw("왼쪽화살표9.txt",520,150);

	int x=70;
	int y=150;
	//추리닝
	imageDraw("땡땡9.txt",7,205);
	imageDraw("추리닝9.txt",25,205);
	
	imageDraw("차분한9.txt",7,220);
	imageDraw("사람은9.txt",70,220);
	imageDraw("선호하지않음9.txt",145,220);


	while(true){
		//사용자가 입력한 값을 n으로(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//기존 '>' 지워주기
				//'>' 출력(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					x=370; //긴바지
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("긴바지9.txt",25,205);
	
					imageDraw("엉뚱한9.txt",7,220);
					imageDraw("사람은9.txt",70,220);
					imageDraw("선호하지않음9.txt",145,220);


				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					x=220; //반바지
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("반바지9.txt",25,205);
	
					imageDraw("보수적인9.txt",7,220);
					imageDraw("사람은9.txt",80,220);
					imageDraw("선호하지않음9.txt",145,220);

					imageDraw("겨울에9.txt",7,230);
					imageDraw("어울리지않음9.txt",70,230);

				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",70,150);
					x=70; //추리닝
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("추리닝9.txt",25,205);
	
					imageDraw("차분한9.txt",7,220);
					imageDraw("사람은9.txt",70,220);
					imageDraw("선호하지않음9.txt",145,220);


				}
				break;
			}
			case RIGHT : {
				//기존 '>' 지워주기
				//'>' 출력(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					x=220; //반바지
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("반바지9.txt",25,205);
	
					imageDraw("보수적인9.txt",7,220);
					imageDraw("사람은9.txt",80,220);
					imageDraw("선호하지않음9.txt",145,220);

					imageDraw("겨울에9.txt",7,230);
					imageDraw("어울리지않음9.txt",70,230);

				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					x=370; //긴바지
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("긴바지9.txt",25,205);
	
					imageDraw("엉뚱한9.txt",7,220);
					imageDraw("사람은9.txt",70,220);
					imageDraw("선호하지않음9.txt",145,220);

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",520,150);
					x=520; //슬랙스
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("슬랙스9.txt",25,205);
	
					imageDraw("자유로운9.txt",7,220);
					imageDraw("사람은9.txt",80,220);
					imageDraw("선호하지않음9.txt",145,220);


				}
				break;
			}
			case SUBMIT : {
				if(x==70) return 0;
				else if(x==220) return 1;
				else if(x==370) return 2;
				else if(x==520) return 3;
			}
		}

	}

}
int shoesDraw(){
	
//	Draw();
	selectClothesOutlineDraw();


	imageDraw("왼쪽화살표9.txt",70,150);

	imageDraw("슬리퍼100.txt",75,80);
	imageDraw("슬리퍼9.txt",100,150);
	imageDraw("샌들100.txt",218,80);
	imageDraw("샌들9.txt",250,150);
	imageDraw("운동화100.txt",375,80);
	imageDraw("운동화9.txt",400,150);
	imageDraw("구두100.txt",518,80);
	imageDraw("구두9.txt",550,150);

//  '>'의 x,y 좌표
//	imageDraw("왼쪽화살표9.txt",70,150);
//	imageDraw("왼쪽화살표9.txt",218,150);
//	imageDraw("왼쪽화살표9.txt",375,150);
//	imageDraw("왼쪽화살표9.txt",518,150);

	int x=70;
	int y=150;
	//슬리퍼
	imageDraw("땡땡9.txt",7,205);
	imageDraw("슬리퍼9.txt",25,205);
	
	imageDraw("차분한9.txt",7,220);
	imageDraw("사람은9.txt",70,220);
	imageDraw("선호하지않음9.txt",145,220);

	imageDraw("겨울에9.txt",7,230);
	imageDraw("어울리지않음9.txt",70,230);



	while(true){
		//사용자가 입력한 값을 n으로(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//기존 '>' 지워주기
				//'>' 출력(518->375,375->218,218->70)
				if(x==518){
					imageDraw("TSmallBlank.txt",518,150);
					imageDraw("왼쪽화살표9.txt",375,150);
					x=375; //운동화
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("운동화9.txt",25,205);
	
					imageDraw("엉뚱한9.txt",7,220);
					imageDraw("사람은9.txt",70,220);
					imageDraw("선호하지않음9.txt",145,220);


				}
				else if(x==375){
					imageDraw("TSmallBlank.txt",375,150);
					imageDraw("왼쪽화살표9.txt",218,150);
					x=218; //샌들
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("샌들9.txt",25,205);
	
					imageDraw("보수적인9.txt",7,220);
					imageDraw("사람은9.txt",80,220);
					imageDraw("선호하지않음9.txt",145,220);

					imageDraw("겨울에9.txt",7,230);
					imageDraw("어울리지않음9.txt",70,230);

				}
				else if(x==218){
					imageDraw("TSmallBlank.txt",218,150);
					imageDraw("왼쪽화살표9.txt",70,150);
					x=70; //슬리퍼
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("슬리퍼9.txt",25,205);
	
					imageDraw("차분한9.txt",7,220);
					imageDraw("사람은9.txt",70,220);
					imageDraw("선호하지않음9.txt",145,220);

					imageDraw("겨울에9.txt",7,230);
					imageDraw("어울리지않음9.txt",70,230);

				}
				break;
			}
			case RIGHT : {
				//기존 '>' 지워주기
				//'>' 출력(70->218,218->375,375->518)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("왼쪽화살표9.txt",218,150);
					x=218; //샌들
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("샌들9.txt",25,205);
	
					imageDraw("보수적인9.txt",7,220);
					imageDraw("사람은9.txt",80,220);
					imageDraw("선호하지않음9.txt",145,220);

					imageDraw("겨울에9.txt",7,230);
					imageDraw("어울리지않음9.txt",70,230);

				}
				else if(x==218){
					imageDraw("TSmallBlank.txt",218,150);
					imageDraw("왼쪽화살표9.txt",375,150);
					x=375; //운동화
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("운동화9.txt",25,205);
	
					imageDraw("엉뚱한9.txt",7,220);
					imageDraw("사람은9.txt",70,220);
					imageDraw("선호하지않음9.txt",145,220);


				}
				else if(x==375){
					imageDraw("TSmallBlank.txt",375,150);
					imageDraw("왼쪽화살표9.txt",518,150);
					x=518; //구두
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("구두9.txt",25,205);
	
					imageDraw("자유로운9.txt",7,220);
					imageDraw("사람은9.txt",80,220);
					imageDraw("선호하지않음9.txt",145,220);


				}
				break;
			}
			case SUBMIT : {
				if(x==70) return 0;
				else if(x==218) return 1;
				else if(x==375) return 2;
				else if(x==518) return 3;
			}
		}

	}

}

void ThreeBasicOutlineDraw(){
   system("cls");
   changeInit();
   imageDraw("가로100.txt",0,0);
   imageDraw("세로.txt",0,2);
   imageDraw("세로.txt",697,2);
   imageDraw("가로100.txt",0,277); 
   imageDraw("12345.txt",875,100);
   imageDraw("선택키9.txt",925,150);
}
int itemDraw1(){
	
//	Draw();
	selectItemsOutlineDraw();


	imageDraw("왼쪽화살표9.txt",70,150);

	imageDraw("scarf100.txt",70,80);
	imageDraw("목도리9.txt",100,150);
	imageDraw("umbrella100.txt",220,80);
	imageDraw("우산9.txt",255,150);
	imageDraw("handhot100.txt",370,80);
	imageDraw("손난로9.txt",400,150);
	imageDraw("handfan100.txt",520,80);
	imageDraw("휴대선풍기9.txt",545,150);

//  '>'의 x,y 좌표
//	imageDraw("왼쪽화살표9.txt",70,150);
//	imageDraw("왼쪽화살표9.txt",220,150);
//	imageDraw("왼쪽화살표9.txt",370,150);
//	imageDraw("왼쪽화살표9.txt",520,150);

	int x=70;
	int y=150;
	 
	imageDraw("땡땡9.txt",7,205);
	imageDraw("목도리9.txt",25,205);
	
	imageDraw("목도리설명9.txt",7,220);
	 

	while(true){
		//사용자가 입력한 값을 n으로(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//기존 '>' 지워주기
				//'>' 출력(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					 x=370;  
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("손난로9.txt",25,205);
	
					imageDraw("손난로설명9.txt",7,220);
					

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("우산9.txt",25,205);
	
					imageDraw("우산설명9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",70,150);
					 x=70; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("목도리9.txt",25,205);
	
					imageDraw("목도리설명9.txt",7,220);
					
				}
				break;
			}
			case RIGHT : {
				//기존 '>' 지워주기
				//'>' 출력(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("우산9.txt",25,205);
	
					imageDraw("우산설명9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					x=370; //긴바지
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("손난로9.txt",25,205);
	
					imageDraw("손난로설명9.txt",7,220);
					
				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",520,150);
					 x=520; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("휴대선풍기9.txt",25,205);
	
					imageDraw("휴대선풍기설명9.txt",7,220);
					
				}
				break;
			}
			case SUBMIT : {
				if(x==70) return 0;
				else if(x==220) return 1;
				else if(x==370) return 2;
				else if(x==520) return 3;
			}
		}

	}

}
int itemDraw2(){
	
//	Draw();
	selectItemsOutlineDraw();


	imageDraw("왼쪽화살표9.txt",70,150);

	imageDraw("handkerchief100.txt",70,80);
	imageDraw("손수건9.txt",100,150);
	imageDraw("perfume100.txt",220,80);
	imageDraw("향수9.txt",250,150);
	imageDraw("powerbank100.txt",370,80);
	imageDraw("보조배터리9.txt",395,150);
	imageDraw("mirror100.txt",520,80);
	imageDraw("거울9.txt",550,150);

//  '>'의 x,y 좌표
//	imageDraw("왼쪽화살표9.txt",70,150);
//	imageDraw("왼쪽화살표9.txt",220,150);
//	imageDraw("왼쪽화살표9.txt",370,150);
//	imageDraw("왼쪽화살표9.txt",520,150);

	int x=70;
	int y=150;
	
	imageDraw("땡땡9.txt",7,205);
	imageDraw("손수건9.txt",25,205);
	
	imageDraw("손수건설명9.txt",7,220);
	

	while(true){
		//사용자가 입력한 값을 n으로(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//기존 '>' 지워주기
				//'>' 출력(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					x=370; //긴바지
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("보조배터리9.txt",25,205);
	
					imageDraw("보조배터리설명9.txt",7,220);
					

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("향수9.txt",25,205);
	
					imageDraw("향수설명9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",70,150);
					 x=70; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("손수건9.txt",25,205);
	
					imageDraw("손수건설명9.txt",7,220);
					
				}
				break;
			}
			case RIGHT : {
				//기존 '>' 지워주기
				//'>' 출력(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("향수9.txt",25,205);
	
					imageDraw("향수설명9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					x=370; //긴바지
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("보조배터리9.txt",25,205);
	
					imageDraw("보조배터리설명9.txt",7,220);
					
				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",520,150);
					 x=520; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("거울9.txt",25,205);
	
					imageDraw("거울설명9.txt",7,220);
					
				}
				break;
			}
			case SUBMIT : {
				if(x==70) return 0;
				else if(x==220) return 1;
				else if(x==370) return 2;
				else if(x==520) return 3;
			}
		}

	}

}
int itemDraw3(){
		

	selectItemsOutlineDraw();


	imageDraw("왼쪽화살표9.txt",70,150);

	imageDraw("flower100.txt",70,80);
	imageDraw("꽃다발9.txt",100,150);
	imageDraw("mic100.txt",220,80);
	imageDraw("마이크9.txt",250,150);
	imageDraw("newspaper100.txt",370,80);
	imageDraw("신문9.txt",400,150);
	imageDraw("humorbook100.txt",520,80);
	imageDraw("유머책9.txt",550,150);

//  '>'의 x,y 좌표
//	imageDraw("왼쪽화살표9.txt",70,150);
//	imageDraw("왼쪽화살표9.txt",220,150);
//	imageDraw("왼쪽화살표9.txt",370,150);
//	imageDraw("왼쪽화살표9.txt",520,150);

	int x=70;
	int y=150;
	
	imageDraw("땡땡9.txt",7,205);
	imageDraw("꽃다발9.txt",25,205);
	
	imageDraw("꽃다발설명9.txt",7,220);
	

	while(true){
		//사용자가 입력한 값을 n으로(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//기존 '>' 지워주기
				//'>' 출력(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					 x=370;
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("신문9.txt",25,205);
	
					imageDraw("신문설명9.txt",7,220);
					

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					 x=220; 
					imageDraw("blank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("마이크9.txt",25,205);
	
					imageDraw("마이크설명9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",70,150);
					 x=70; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("꽃다발9.txt",25,205);
	
					imageDraw("꽃다발설명9.txt",7,220);
					
				}
				break;
			}
			case RIGHT : {
				//기존 '>' 지워주기
				//'>' 출력(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("왼쪽화살표9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("마이크9.txt",25,205);
	
					imageDraw("마이크설명9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("왼쪽화살표9.txt",370,150);
					 x=370; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("신문9.txt",25,205);
	
					imageDraw("신문설명9.txt",7,220);
					
				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("왼쪽화살표9.txt",520,150);
					 x=520; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("땡땡9.txt",7,205);
					imageDraw("유머책9.txt",25,205);
	
					imageDraw("유머책설명9.txt",7,220);
					
				}
				break;
			}
			case SUBMIT : {
				if(x==70) return 0;
				else if(x==220) return 1;
				else if(x==370) return 2;
				else if(x==520) return 3;
			}
		}

	}

}