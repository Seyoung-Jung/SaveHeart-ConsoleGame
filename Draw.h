#ifndef __UTIL_H__
#define __UTIL_H__
#include "util.h"
#endif

using namespace std;


void cafeImageDraw(const char* name, int x,int y){

   //       BBBB BBB \n
   // _ �������� �ѱ��ھ� �ް� x++
   // _���� \n �������� �ް� ���, y++
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

   //feof()�� ������ ���϶� 0�� �ƴ� ��(=��)�� ��ȯ
   
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
gotoxy(0,1,"���������� ���������������������������������������������������������������������������������������������������������������������������������������������������� ��    ");
gotoxy(0,2,"����������������������������������������������������������������������������������������������������������������������������������������������������������������������"); 
gotoxy(0,3,"����                                                                               ����");
gotoxy(0,4,"����                                                                               ����");
gotoxy(0,5,"����                                                                               ����");
gotoxy(0,6,"����                                                                               ����");
gotoxy(0,7,"����                                                                               ����");	
gotoxy(0,8,"����                                                                               ����");
gotoxy(0,9,"����                                                                               ����");
gotoxy(0,10,"����                                                                               ����");
gotoxy(0,11,"����                                                                               ����");
gotoxy(0,12,"����                                                                               ����");
gotoxy(0,13,"����                                                                               ����");
gotoxy(0,14,"����                                                                               ����");
gotoxy(0,15,"����                                                                               ����");
gotoxy(0,16,"����                                                                               ����");
gotoxy(0,17,"����                                                                               ����");
gotoxy(0,18,"����                                                                               ����");
gotoxy(0,19,"����                                                                               ����");
gotoxy(0,20,"����                                                                               ����");
gotoxy(0,21,"����                                                                               ����");
gotoxy(0,22,"����                                                                               ����");
gotoxy(0,23,"����                                                                               ����");
gotoxy(0,24,"����                                                                               ����");
gotoxy(0,25,"����                                                                               ����");
gotoxy(0,26,"����                                                                               ����");
gotoxy(0,27,"����                                                                               ����");
gotoxy(0,28,"���������������������������������������������������������������������������������������������������������������������������������������������������������������������� ");
gotoxy(0,29,"���������� ���������������������������������������������������������������������������������������������������������������������������������������������������� �� ");

}


void draw2(){
gotoxy(0,1,"���������� ������������������������������������������������������������������������������������������������������������������������������ ��    ");
gotoxy(0,2,"������������������������������������������������������������������������������������������������������������������������������������������������"); 
gotoxy(0,3,"����                                                                    ����");
gotoxy(0,4,"����                                                                    ����");
gotoxy(0,5,"����                                                                    ����");
gotoxy(0,6,"����                                                                    ����");
gotoxy(0,7,"����                                                                    ����");	
gotoxy(0,8,"����                                                                    ����");
gotoxy(0,9,"����                                                                    ����");
gotoxy(0,10,"����                                                                    ����");
gotoxy(0,11,"����                                                                    ����");
gotoxy(0,12,"����                                                                    ����");
gotoxy(0,13,"����                                                                    ����");
gotoxy(0,14,"����                                                                    ����");
gotoxy(0,15,"����                                                                    ����");
gotoxy(0,16,"����                                                                    ����");
gotoxy(0,17,"����                                                                    ����");
gotoxy(0,18,"����                                                                    ����");
gotoxy(0,19,"����                                                                    ����");
gotoxy(0,20,"����                                                                    ����");
gotoxy(0,21,"����                                                                    ����");
gotoxy(0,22,"����                                                                    ����");
gotoxy(0,23,"����                                                                    ����");
gotoxy(0,24,"����                                                                    ����");
gotoxy(0,25,"����                                                                    ����");
gotoxy(0,26,"����                                                                    ����");
gotoxy(0,27,"����                                                                    ����");
gotoxy(0,28,"������������������������������������������������������������������������������������������������������������������������������������������������ ");
gotoxy(0,29,"���������� ������������������������������������������������������������������������������������������������������������������������������ �� ");

}

void draw1(){
gotoxy(5,5,"�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�"); 
gotoxy(5,6,"�̢�                                                    �̢�");
gotoxy(5,7,"��  ��                                                ��  ��");
gotoxy(5,8,"��                                                        ��");
gotoxy(5,9,"��                                                        ��");
gotoxy(5,10,"��                                                        ��");
gotoxy(5,11,"��                                                        ��");
gotoxy(5,12,"��                                                        ��");
gotoxy(5,13,"��                                                        ��");
gotoxy(5,14,"��                                                        ��");
gotoxy(5,15,"��                                                        ��");
gotoxy(5,16,"��                                                        ��");
gotoxy(5,17,"��                                                        ��");
gotoxy(5,18,"��                                                        ��");
gotoxy(5,19,"��                                                        ��");
gotoxy(5,20,"��                                                        ��");
gotoxy(5,21,"��  ��                                                ��  ��");
gotoxy(5,22,"�̢�                                                    �̢� ");
gotoxy(5,23,"�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�");
}
 
void keyDraw(){
gotoxy(41,13," ������������");
gotoxy(41,14," ��  W ��");
gotoxy(39,15,"��������������������������������");
gotoxy(39,16,"��  A ��  S ��  D ��");
gotoxy(39,17,"��������������������������������");

gotoxy(49,15,"������������������������������");
gotoxy(49,16,"��     SPACE   ��");
gotoxy(49,17,"������������������������������");

gotoxy(42,19,"����Ű");
gotoxy(51,19," ����Ű");
} 

void imageDraw(const char* name, int x,int y){
	char Buffer[1000];
	char Temp[1000];
	FILE *image = NULL;
	char eol;
	fopen_s(&image, name, "r");

	if(image==NULL)
		return;

	//feof()�� ������ ���϶� 0�� �ƴ� ��(=��)�� ��ȯ
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
	// _ �������� �ѱ��ھ� �ް� x++
	// _���� \n �������� �ް� ���, y++
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

	//feof()�� ������ ���϶� 0�� �ƴ� ��(=��)�� ��ȯ
	
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
	imageDraw("����100.txt",0,0);
	imageDraw("����.txt",0,2);
	imageDraw("����.txt",697,2);
	imageDraw("����100.txt",0,277); 
	imageDraw("wasd100.txt",800,100);
	imageDraw("space100.txt",950,100);
	imageDraw("����Ű9.txt",825,150);
	imageDraw("����Ű9.txt",975,150);
	imageDraw("����9.txt",1105, 265);
	imageDraw("help30.txt", 1117, 240);
}
void selectClothesOutlineDraw(){
	BasicOutlineDraw();
	imageDraw("����100.txt",0,25);
	imageDraw("����10.txt",300,7);
	imageDraw("����100.txt",0,200);
}

void selectItemsOutlineDraw(){
	BasicOutlineDraw();
	imageDraw("����100.txt",0,25);
	imageDraw("����ǰ50.txt",300,7);
	imageDraw("����100.txt",0,200);
}


void selectLivingOutLineDraw(){
	imageDraw("����100.txt",0,25);
	imageDraw("�Ž�10.txt",300,7);
	imageDraw("����100.txt",0,200);
}



void selectCafeOutLineDraw(){
	// BasicOutlineDraw();
	imageDraw("����100.txt",0,25);
	imageDraw("ī��10.txt",300,7);
	imageDraw("����100.txt",0,200);
}


void selectItemsMainMenuDraw(){
	imageDraw("��������30.txt",7,205);

	imageDraw("����ȭ��ǥ9.txt",50,150);
//	imageDraw("����ȭ��ǥ9.txt",270,150);
//	imageDraw("����ȭ��ǥ9.txt",500,150);

	imageDraw("weather100.txt",70,80);
	imageDraw("����9.txt",100,150);
	imageDraw("sense100.txt",290,80);
	imageDraw("����9.txt",320,150);
	imageDraw("mood100.txt",510,80);
	imageDraw("������9.txt",535,150);
}

void selectClothesMainMenuDraw(){
	imageDraw("�мǾ�����9.txt",7,205);
    imageDraw("ī��9.txt",7,217);
    imageDraw("��������1009.txt",7,229);

	imageDraw("����ȭ��ǥ9.txt",50,150);
//	imageDraw("����ȭ��ǥ9.txt",270,150);
//	imageDraw("����ȭ��ǥ9.txt",500,150);

	imageDraw("top100.txt",70,80);
	imageDraw("����9.txt",100,150);
	imageDraw("pants100.txt",290,80);
	imageDraw("����9.txt",320,150);
	imageDraw("shoes100.txt",510,80);
	imageDraw("�Ź�9.txt",550,150);
}

int topDraw(){
	
//	Draw();
	selectClothesOutlineDraw();


	imageDraw("����ȭ��ǥ9.txt",70,150);

	imageDraw("sleeve100.txt",65,80);
	imageDraw("����9.txt",100,150);
	imageDraw("top100.txt",215,80);
	imageDraw("����9.txt",250,150);
	imageDraw("shirt100.txt",365,80);
	imageDraw("����9.txt",400,150);
	imageDraw("padding100.txt",515,80);
	imageDraw("�е�9.txt",550,150);

//  '>'�� x,y ��ǥ
//	imageDraw("����ȭ��ǥ9.txt",70,150);
//	imageDraw("����ȭ��ǥ9.txt",220,150);
//	imageDraw("����ȭ��ǥ9.txt",370,150);
//	imageDraw("����ȭ��ǥ9.txt",520,150);

	int x=70;
	int y=150;
	//����
	imageDraw("����9.txt",7,205);
	imageDraw("����9.txt",25,205);
	
	imageDraw("��������9.txt",7,220);
	imageDraw("�����9.txt",80,220);
	imageDraw("��ȣ��������9.txt",145,220);

	imageDraw("�ܿ￡9.txt",7,230);
	imageDraw("��︮������9.txt",70,230);



	while(true){
		//����ڰ� �Է��� ���� n����(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//���� '>' �����ֱ�
				//'>' ���(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					x=370; //����

					imageDraw("clothesBlank.txt",7,205);

					//boxClear(7,205);

					imageDraw("����9.txt",7,205);
					imageDraw("����9.txt",25,205);
	
					imageDraw("�����ο�9.txt",7,220);
					imageDraw("�����9.txt",80,220);
					imageDraw("��ȣ��������9.txt",145,220);



				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					x=220; //����

					imageDraw("clothesBlank.txt",7,205);
					// boxClear(7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����9.txt",25,205);
	
					imageDraw("������9.txt",7,220);
					imageDraw("�����9.txt",70,220);
					imageDraw("��ȣ��������9.txt",145,220);



				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",70,150);
					x=70; //����
					imageDraw("clothesBlank.txt",7,205);
					// boxClear(7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����9.txt",25,205);
	
					imageDraw("��������9.txt",7,220);
					imageDraw("�����9.txt",80,220);
					imageDraw("��ȣ��������9.txt",145,220);

					imageDraw("�ܿ￡9.txt",7,230);
					imageDraw("��︮������9.txt",70,230);

				}
				break;
			}
			case RIGHT : {
				//���� '>' �����ֱ�
				//'>' ���(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					x=220; //����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����9.txt",25,205);
	
					imageDraw("������9.txt",7,220);
					imageDraw("�����9.txt",70,220);
					imageDraw("��ȣ��������9.txt",145,220);


				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					x=370; //����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����9.txt",25,205);
	
					imageDraw("�����ο�9.txt",7,220);
					imageDraw("�����9.txt",80,220);
					imageDraw("��ȣ��������9.txt",145,220);

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",520,150);
					x=520; //�е�
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�е�9.txt",25,205);

					imageDraw("������9.txt",7,220);
					imageDraw("��︮������9.txt",70,220);

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

	imageDraw("����ȭ��ǥ9.txt",70,150);

	imageDraw("�߸���100.txt",70,80);
	imageDraw("�߸���9.txt",100,150);
	imageDraw("�ݹ���100.txt",220,80);
	imageDraw("�ݹ���9.txt",250,150);
	imageDraw("�����100.txt",370,80);
	imageDraw("�����9.txt",400,150);
	imageDraw("������100.txt",520,80);
	imageDraw("������9.txt",550,150);

//  '>'�� x,y ��ǥ
//	imageDraw("����ȭ��ǥ9.txt",70,150);
//	imageDraw("����ȭ��ǥ9.txt",220,150);
//	imageDraw("����ȭ��ǥ9.txt",370,150);
//	imageDraw("����ȭ��ǥ9.txt",520,150);

	int x=70;
	int y=150;
	//�߸���
	imageDraw("����9.txt",7,205);
	imageDraw("�߸���9.txt",25,205);
	
	imageDraw("������9.txt",7,220);
	imageDraw("�����9.txt",70,220);
	imageDraw("��ȣ��������9.txt",145,220);


	while(true){
		//����ڰ� �Է��� ���� n����(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//���� '>' �����ֱ�
				//'>' ���(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					x=370; //�����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�����9.txt",25,205);
	
					imageDraw("������9.txt",7,220);
					imageDraw("�����9.txt",70,220);
					imageDraw("��ȣ��������9.txt",145,220);


				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					x=220; //�ݹ���
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�ݹ���9.txt",25,205);
	
					imageDraw("��������9.txt",7,220);
					imageDraw("�����9.txt",80,220);
					imageDraw("��ȣ��������9.txt",145,220);

					imageDraw("�ܿ￡9.txt",7,230);
					imageDraw("��︮������9.txt",70,230);

				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",70,150);
					x=70; //�߸���
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�߸���9.txt",25,205);
	
					imageDraw("������9.txt",7,220);
					imageDraw("�����9.txt",70,220);
					imageDraw("��ȣ��������9.txt",145,220);


				}
				break;
			}
			case RIGHT : {
				//���� '>' �����ֱ�
				//'>' ���(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					x=220; //�ݹ���
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�ݹ���9.txt",25,205);
	
					imageDraw("��������9.txt",7,220);
					imageDraw("�����9.txt",80,220);
					imageDraw("��ȣ��������9.txt",145,220);

					imageDraw("�ܿ￡9.txt",7,230);
					imageDraw("��︮������9.txt",70,230);

				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					x=370; //�����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�����9.txt",25,205);
	
					imageDraw("������9.txt",7,220);
					imageDraw("�����9.txt",70,220);
					imageDraw("��ȣ��������9.txt",145,220);

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",520,150);
					x=520; //������
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("������9.txt",25,205);
	
					imageDraw("�����ο�9.txt",7,220);
					imageDraw("�����9.txt",80,220);
					imageDraw("��ȣ��������9.txt",145,220);


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


	imageDraw("����ȭ��ǥ9.txt",70,150);

	imageDraw("������100.txt",75,80);
	imageDraw("������9.txt",100,150);
	imageDraw("����100.txt",218,80);
	imageDraw("����9.txt",250,150);
	imageDraw("�ȭ100.txt",375,80);
	imageDraw("�ȭ9.txt",400,150);
	imageDraw("����100.txt",518,80);
	imageDraw("����9.txt",550,150);

//  '>'�� x,y ��ǥ
//	imageDraw("����ȭ��ǥ9.txt",70,150);
//	imageDraw("����ȭ��ǥ9.txt",218,150);
//	imageDraw("����ȭ��ǥ9.txt",375,150);
//	imageDraw("����ȭ��ǥ9.txt",518,150);

	int x=70;
	int y=150;
	//������
	imageDraw("����9.txt",7,205);
	imageDraw("������9.txt",25,205);
	
	imageDraw("������9.txt",7,220);
	imageDraw("�����9.txt",70,220);
	imageDraw("��ȣ��������9.txt",145,220);

	imageDraw("�ܿ￡9.txt",7,230);
	imageDraw("��︮������9.txt",70,230);



	while(true){
		//����ڰ� �Է��� ���� n����(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//���� '>' �����ֱ�
				//'>' ���(518->375,375->218,218->70)
				if(x==518){
					imageDraw("TSmallBlank.txt",518,150);
					imageDraw("����ȭ��ǥ9.txt",375,150);
					x=375; //�ȭ
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�ȭ9.txt",25,205);
	
					imageDraw("������9.txt",7,220);
					imageDraw("�����9.txt",70,220);
					imageDraw("��ȣ��������9.txt",145,220);


				}
				else if(x==375){
					imageDraw("TSmallBlank.txt",375,150);
					imageDraw("����ȭ��ǥ9.txt",218,150);
					x=218; //����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����9.txt",25,205);
	
					imageDraw("��������9.txt",7,220);
					imageDraw("�����9.txt",80,220);
					imageDraw("��ȣ��������9.txt",145,220);

					imageDraw("�ܿ￡9.txt",7,230);
					imageDraw("��︮������9.txt",70,230);

				}
				else if(x==218){
					imageDraw("TSmallBlank.txt",218,150);
					imageDraw("����ȭ��ǥ9.txt",70,150);
					x=70; //������
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("������9.txt",25,205);
	
					imageDraw("������9.txt",7,220);
					imageDraw("�����9.txt",70,220);
					imageDraw("��ȣ��������9.txt",145,220);

					imageDraw("�ܿ￡9.txt",7,230);
					imageDraw("��︮������9.txt",70,230);

				}
				break;
			}
			case RIGHT : {
				//���� '>' �����ֱ�
				//'>' ���(70->218,218->375,375->518)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("����ȭ��ǥ9.txt",218,150);
					x=218; //����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����9.txt",25,205);
	
					imageDraw("��������9.txt",7,220);
					imageDraw("�����9.txt",80,220);
					imageDraw("��ȣ��������9.txt",145,220);

					imageDraw("�ܿ￡9.txt",7,230);
					imageDraw("��︮������9.txt",70,230);

				}
				else if(x==218){
					imageDraw("TSmallBlank.txt",218,150);
					imageDraw("����ȭ��ǥ9.txt",375,150);
					x=375; //�ȭ
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�ȭ9.txt",25,205);
	
					imageDraw("������9.txt",7,220);
					imageDraw("�����9.txt",70,220);
					imageDraw("��ȣ��������9.txt",145,220);


				}
				else if(x==375){
					imageDraw("TSmallBlank.txt",375,150);
					imageDraw("����ȭ��ǥ9.txt",518,150);
					x=518; //����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����9.txt",25,205);
	
					imageDraw("�����ο�9.txt",7,220);
					imageDraw("�����9.txt",80,220);
					imageDraw("��ȣ��������9.txt",145,220);


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
   imageDraw("����100.txt",0,0);
   imageDraw("����.txt",0,2);
   imageDraw("����.txt",697,2);
   imageDraw("����100.txt",0,277); 
   imageDraw("12345.txt",875,100);
   imageDraw("����Ű9.txt",925,150);
}
int itemDraw1(){
	
//	Draw();
	selectItemsOutlineDraw();


	imageDraw("����ȭ��ǥ9.txt",70,150);

	imageDraw("scarf100.txt",70,80);
	imageDraw("�񵵸�9.txt",100,150);
	imageDraw("umbrella100.txt",220,80);
	imageDraw("���9.txt",255,150);
	imageDraw("handhot100.txt",370,80);
	imageDraw("�ճ���9.txt",400,150);
	imageDraw("handfan100.txt",520,80);
	imageDraw("�޴뼱ǳ��9.txt",545,150);

//  '>'�� x,y ��ǥ
//	imageDraw("����ȭ��ǥ9.txt",70,150);
//	imageDraw("����ȭ��ǥ9.txt",220,150);
//	imageDraw("����ȭ��ǥ9.txt",370,150);
//	imageDraw("����ȭ��ǥ9.txt",520,150);

	int x=70;
	int y=150;
	 
	imageDraw("����9.txt",7,205);
	imageDraw("�񵵸�9.txt",25,205);
	
	imageDraw("�񵵸�����9.txt",7,220);
	 

	while(true){
		//����ڰ� �Է��� ���� n����(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//���� '>' �����ֱ�
				//'>' ���(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					 x=370;  
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�ճ���9.txt",25,205);
	
					imageDraw("�ճ��μ���9.txt",7,220);
					

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("���9.txt",25,205);
	
					imageDraw("��꼳��9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",70,150);
					 x=70; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�񵵸�9.txt",25,205);
	
					imageDraw("�񵵸�����9.txt",7,220);
					
				}
				break;
			}
			case RIGHT : {
				//���� '>' �����ֱ�
				//'>' ���(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("���9.txt",25,205);
	
					imageDraw("��꼳��9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					x=370; //�����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�ճ���9.txt",25,205);
	
					imageDraw("�ճ��μ���9.txt",7,220);
					
				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",520,150);
					 x=520; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�޴뼱ǳ��9.txt",25,205);
	
					imageDraw("�޴뼱ǳ�⼳��9.txt",7,220);
					
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


	imageDraw("����ȭ��ǥ9.txt",70,150);

	imageDraw("handkerchief100.txt",70,80);
	imageDraw("�ռ���9.txt",100,150);
	imageDraw("perfume100.txt",220,80);
	imageDraw("���9.txt",250,150);
	imageDraw("powerbank100.txt",370,80);
	imageDraw("�������͸�9.txt",395,150);
	imageDraw("mirror100.txt",520,80);
	imageDraw("�ſ�9.txt",550,150);

//  '>'�� x,y ��ǥ
//	imageDraw("����ȭ��ǥ9.txt",70,150);
//	imageDraw("����ȭ��ǥ9.txt",220,150);
//	imageDraw("����ȭ��ǥ9.txt",370,150);
//	imageDraw("����ȭ��ǥ9.txt",520,150);

	int x=70;
	int y=150;
	
	imageDraw("����9.txt",7,205);
	imageDraw("�ռ���9.txt",25,205);
	
	imageDraw("�ռ��Ǽ���9.txt",7,220);
	

	while(true){
		//����ڰ� �Է��� ���� n����(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//���� '>' �����ֱ�
				//'>' ���(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					x=370; //�����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�������͸�9.txt",25,205);
	
					imageDraw("�������͸�����9.txt",7,220);
					

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("���9.txt",25,205);
	
					imageDraw("�������9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",70,150);
					 x=70; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�ռ���9.txt",25,205);
	
					imageDraw("�ռ��Ǽ���9.txt",7,220);
					
				}
				break;
			}
			case RIGHT : {
				//���� '>' �����ֱ�
				//'>' ���(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("���9.txt",25,205);
	
					imageDraw("�������9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					x=370; //�����
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�������͸�9.txt",25,205);
	
					imageDraw("�������͸�����9.txt",7,220);
					
				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",520,150);
					 x=520; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�ſ�9.txt",25,205);
	
					imageDraw("�ſＳ��9.txt",7,220);
					
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


	imageDraw("����ȭ��ǥ9.txt",70,150);

	imageDraw("flower100.txt",70,80);
	imageDraw("�ɴٹ�9.txt",100,150);
	imageDraw("mic100.txt",220,80);
	imageDraw("����ũ9.txt",250,150);
	imageDraw("newspaper100.txt",370,80);
	imageDraw("�Ź�9.txt",400,150);
	imageDraw("humorbook100.txt",520,80);
	imageDraw("����å9.txt",550,150);

//  '>'�� x,y ��ǥ
//	imageDraw("����ȭ��ǥ9.txt",70,150);
//	imageDraw("����ȭ��ǥ9.txt",220,150);
//	imageDraw("����ȭ��ǥ9.txt",370,150);
//	imageDraw("����ȭ��ǥ9.txt",520,150);

	int x=70;
	int y=150;
	
	imageDraw("����9.txt",7,205);
	imageDraw("�ɴٹ�9.txt",25,205);
	
	imageDraw("�ɴٹ߼���9.txt",7,220);
	

	while(true){
		//����ڰ� �Է��� ���� n����(wasd, space)
		int n= keyControl();
		switch(n){
			case LEFT : {
				//���� '>' �����ֱ�
				//'>' ���(520->370,370->220,220->70)
				if(x==520){
					imageDraw("TSmallBlank.txt",520,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					 x=370;
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�Ź�9.txt",25,205);
	
					imageDraw("�Ź�����9.txt",7,220);
					

				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					 x=220; 
					imageDraw("blank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����ũ9.txt",25,205);
	
					imageDraw("����ũ����9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",70,150);
					 x=70; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�ɴٹ�9.txt",25,205);
	
					imageDraw("�ɴٹ߼���9.txt",7,220);
					
				}
				break;
			}
			case RIGHT : {
				//���� '>' �����ֱ�
				//'>' ���(70->220,220->370,370->520)
				if(x==70){
					imageDraw("TSmallBlank.txt",70,150);
					imageDraw("����ȭ��ǥ9.txt",220,150);
					 x=220; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����ũ9.txt",25,205);
	
					imageDraw("����ũ����9.txt",7,220);
					
				}
				else if(x==220){
					imageDraw("TSmallBlank.txt",220,150);
					imageDraw("����ȭ��ǥ9.txt",370,150);
					 x=370; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("�Ź�9.txt",25,205);
	
					imageDraw("�Ź�����9.txt",7,220);
					
				}
				else if(x==370){
					imageDraw("TSmallBlank.txt",370,150);
					imageDraw("����ȭ��ǥ9.txt",520,150);
					 x=520; 
					imageDraw("clothesBlank.txt",7,205);
					imageDraw("����9.txt",7,205);
					imageDraw("����å9.txt",25,205);
	
					imageDraw("����å����9.txt",7,220);
					
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