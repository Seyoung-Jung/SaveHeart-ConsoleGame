#ifndef __STDIO_H__
#define __STDIO_H__
#include <stdio.h>
#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif

#ifndef __IO_H__
#define __IO_H__
#include <io.h>
#endif

#ifndef __WINDOWS_H__
#define __WINDOWS_H__
#include <Windows.h>
#endif

#ifndef __STRING_H__
#define __STRING_H__
#include <string.h>
#endif

#ifndef __UTIL_H__
#define __UTIL_H__
#include "util.h"
#endif

char* GetPureFileName(char* strFileName)
{
   char* pToken[10];
   int iIndex = 0;

   //argv�� ���������� ���۸� �̿�
   pToken[iIndex++] = strtok(strFileName, "\\");
   while (pToken[iIndex - 1] != NULL)
   {
      pToken[iIndex++] = strtok(NULL, "\\");
   }
   return pToken[iIndex - 2];
}

void OpenFile(FILE** ppFile, char* strFileName, char* pMode)
{
   *ppFile = fopen(strFileName, pMode);
   if (*ppFile == NULL)
   {
      perror("���� ��Ʈ�� ���� ����");
      exit(EXIT_FAILURE);
   }
}

void CloseFile(FILE* pFile)
{
   if (fclose(pFile) == EOF)
   {
      perror("���� ��Ʈ�� ���� ����!");
      exit(EXIT_FAILURE);
   }
}

typedef enum _State
{
   PLAY, STOP
}STATE;

double CheckTime(LARGE_INTEGER* pLastTime, LARGE_INTEGER* pNowTime, LARGE_INTEGER* pFrequency)
{
   double dTimeInterval;

   QueryPerformanceCounter(pNowTime);

   dTimeInterval = ((double)(pNowTime->QuadPart - pLastTime->QuadPart) / (double)pFrequency->QuadPart);
   pLastTime->QuadPart = pNowTime->QuadPart;
   return dTimeInterval;
}


void introMain()
{	
	

   char source[100] = "./intro";

   char Buffer[500];
   char cLF;
   char FindPath[100];
   char rt[] = "rt";
   int iResult = 0;
   double dResult = 0.0; //���� �Ҵ� ������ ��� ���� �ʱ�ȭ
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4����Ʈ�� 8����Ʈ ��ȯ
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //���� �ý��� ������ �� �ִ� �ʴ� ���ļ� ���ϱ�
   //���� �ý��� ���� ��� 3320337 --> ���ļ��� 3320337 �Ǹ� 1��
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("���� �ڵ� �������� ����");
         return;
      }

      iResult = 0;

      while (iResult != -1)
      {
         if (eState == PLAY)
         {
            strcpy(FindPath, source);
            strcat(FindPath, "\\");
            strcat(FindPath, FindASCIIArt.name);

            OpenFile(&pASCIIArt, FindPath, rt);

            while (feof(pASCIIArt) == 0)
            {
               fscanf(pASCIIArt, "%[^\n]s", Buffer);
               fscanf(pASCIIArt, "%c", &cLF);
               puts(Buffer);
            }

            CloseFile(pASCIIArt);
            eState = STOP;
         }
		
         //������ �ð� ����
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 1.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //��� �۾� ���� �� ���� ���� ã��

            eState = PLAY;
         }
      }
      _findclose(FileHandle);
	  return;
	  
   }
   
}

void storyMain()
{	
	

   char source[100] = "./story";

   char Buffer[500];
   char cLF;
   char FindPath[100];
   char rt[] = "rt";
   int iResult = 0;
   double dResult = 0.0; //���� �Ҵ� ������ ��� ���� �ʱ�ȭ
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4����Ʈ�� 8����Ʈ ��ȯ
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //���� �ý��� ������ �� �ִ� �ʴ� ���ļ� ���ϱ�
   //���� �ý��� ���� ��� 3320337 --> ���ļ��� 3320337 �Ǹ� 1��
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("���� �ڵ� �������� ����");
         return;
      }

      iResult = 0;

      while (iResult != -1)
      {
         if (eState == PLAY)
         {
            strcpy(FindPath, source);
            strcat(FindPath, "\\");
            strcat(FindPath, FindASCIIArt.name);

            OpenFile(&pASCIIArt, FindPath, rt);

            while (feof(pASCIIArt) == 0)
            {
               fscanf(pASCIIArt, "%[^\n]s", Buffer);
               fscanf(pASCIIArt, "%c", &cLF);
               puts(Buffer);
            }

            CloseFile(pASCIIArt);
            eState = STOP;
         }

         //������ �ð� ����
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 3.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //��� �۾� ���� �� ���� ���� ã��

            eState = PLAY;
         }
      }
      _findclose(FileHandle);
	  return;
	  
   }
   
}

void motorMain()
{	
	

   char source[100] = "./motorcycle";

   char Buffer[500];
   char cLF;
   char FindPath[100];
   char rt[] = "rt";
   int iResult = 0;
   double dResult = 0.0; //���� �Ҵ� ������ ��� ���� �ʱ�ȭ
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4����Ʈ�� 8����Ʈ ��ȯ
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //���� �ý��� ������ �� �ִ� �ʴ� ���ļ� ���ϱ�
   //���� �ý��� ���� ��� 3320337 --> ���ļ��� 3320337 �Ǹ� 1��
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("���� �ڵ� �������� ����");
         return;
      }

      iResult = 0;

      while (iResult != -1)
      {
         if (eState == PLAY)
         {
            strcpy(FindPath, source);
            strcat(FindPath, "\\");
            strcat(FindPath, FindASCIIArt.name);

            OpenFile(&pASCIIArt, FindPath, rt);

            while (feof(pASCIIArt) == 0)
            {
               fscanf(pASCIIArt, "%[^\n]s", Buffer);
               fscanf(pASCIIArt, "%c", &cLF);
               puts(Buffer);
            }

            CloseFile(pASCIIArt);
            eState = STOP;
         }

         //������ �ð� ����
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 3.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //��� �۾� ���� �� ���� ���� ã��

            eState = PLAY;
         }
      }
      _findclose(FileHandle);
	  return;
	  
   }
   
}

void failureMain()
{	
	

   char source[100] = "./failure";

   char Buffer[500];
   char cLF;
   char FindPath[100];
   char rt[] = "rt";
   int iResult = 0;
   double dResult = 0.0; //���� �Ҵ� ������ ��� ���� �ʱ�ȭ
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4����Ʈ�� 8����Ʈ ��ȯ
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //���� �ý��� ������ �� �ִ� �ʴ� ���ļ� ���ϱ�
   //���� �ý��� ���� ��� 3320337 --> ���ļ��� 3320337 �Ǹ� 1��
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("���� �ڵ� �������� ����");
         return;
      }

      iResult = 0;

      while (iResult != -1)
      {
         if (eState == PLAY)
         {
            strcpy(FindPath, source);
            strcat(FindPath, "\\");
            strcat(FindPath, FindASCIIArt.name);

            OpenFile(&pASCIIArt, FindPath, rt);

            while (feof(pASCIIArt) == 0)
            {
               fscanf(pASCIIArt, "%[^\n]s", Buffer);
               fscanf(pASCIIArt, "%c", &cLF);
               puts(Buffer);
            }

            CloseFile(pASCIIArt);
            eState = STOP;
         }

         //������ �ð� ����
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 1.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //��� �۾� ���� �� ���� ���� ã��

            eState = PLAY;
         }
      }
      _findclose(FileHandle);
	  return;
	  
   }
   
}

void successMain()
{	
	

   char source[100] = "./success";

   char Buffer[500];
   char cLF;
   char FindPath[100];
   char rt[] = "rt";
   int iResult = 0;
   double dResult = 0.0; //���� �Ҵ� ������ ��� ���� �ʱ�ȭ
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4����Ʈ�� 8����Ʈ ��ȯ
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //���� �ý��� ������ �� �ִ� �ʴ� ���ļ� ���ϱ�
   //���� �ý��� ���� ��� 3320337 --> ���ļ��� 3320337 �Ǹ� 1��
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("���� �ڵ� �������� ����");
         return;
      }

      iResult = 0;

      while (iResult != -1)
      {
         if (eState == PLAY)
         {
            strcpy(FindPath, source);
            strcat(FindPath, "\\");
            strcat(FindPath, FindASCIIArt.name);

            OpenFile(&pASCIIArt, FindPath, rt);

            while (feof(pASCIIArt) == 0)
            {
               fscanf(pASCIIArt, "%[^\n]s", Buffer);
               fscanf(pASCIIArt, "%c", &cLF);
               puts(Buffer);
            }

            CloseFile(pASCIIArt);
            eState = STOP;
         }

         //������ �ð� ����
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 1.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //��� �۾� ���� �� ���� ���� ã��

            eState = PLAY;
         }
      }
      _findclose(FileHandle);
	  return;
	  
   }
   
}