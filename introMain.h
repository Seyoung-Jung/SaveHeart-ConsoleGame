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

   //argv는 내부적으로 버퍼를 이용
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
      perror("파일 스트림 생성 실패");
      exit(EXIT_FAILURE);
   }
}

void CloseFile(FILE* pFile)
{
   if (fclose(pFile) == EOF)
   {
      perror("파일 스트림 생성 실패!");
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
   double dResult = 0.0; //복합 할당 연산자 사용 위해 초기화
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4바이트와 8바이트 전환
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //현재 시스템 측정할 수 있는 초당 주파수 구하기
   //현재 시스템 측정 결과 3320337 --> 주파수가 3320337 되면 1초
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("파일 핸들 가져오기 실패");
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
		
         //프레임 시간 측정
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 1.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //모든 작업 끝난 후 다음 파일 찾음

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
   double dResult = 0.0; //복합 할당 연산자 사용 위해 초기화
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4바이트와 8바이트 전환
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //현재 시스템 측정할 수 있는 초당 주파수 구하기
   //현재 시스템 측정 결과 3320337 --> 주파수가 3320337 되면 1초
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("파일 핸들 가져오기 실패");
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

         //프레임 시간 측정
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 3.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //모든 작업 끝난 후 다음 파일 찾음

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
   double dResult = 0.0; //복합 할당 연산자 사용 위해 초기화
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4바이트와 8바이트 전환
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //현재 시스템 측정할 수 있는 초당 주파수 구하기
   //현재 시스템 측정 결과 3320337 --> 주파수가 3320337 되면 1초
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("파일 핸들 가져오기 실패");
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

         //프레임 시간 측정
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 3.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //모든 작업 끝난 후 다음 파일 찾음

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
   double dResult = 0.0; //복합 할당 연산자 사용 위해 초기화
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4바이트와 8바이트 전환
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //현재 시스템 측정할 수 있는 초당 주파수 구하기
   //현재 시스템 측정 결과 3320337 --> 주파수가 3320337 되면 1초
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("파일 핸들 가져오기 실패");
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

         //프레임 시간 측정
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 1.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //모든 작업 끝난 후 다음 파일 찾음

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
   double dResult = 0.0; //복합 할당 연산자 사용 위해 초기화
   STATE eState = PLAY;
   FILE* pASCIIArt = NULL;
   intptr_t FileHandle; // 4바이트와 8바이트 전환
   LARGE_INTEGER LastTime, NowTime, Frequency;
   COORD CursorPos = { 0,0 };
   struct _finddata_t FindASCIIArt;

   //현재 시스템 측정할 수 있는 초당 주파수 구하기
   //현재 시스템 측정 결과 3320337 --> 주파수가 3320337 되면 1초
   QueryPerformanceFrequency(&Frequency);
   QueryPerformanceCounter(&LastTime);


   while(true)
   {

      strcpy(FindPath, source);
      strcat(FindPath, "\\*.txt");
      FileHandle = _findfirst(FindPath, &FindASCIIArt);

      if (FileHandle == -1)
      {
         perror("파일 핸들 가져오기 실패");
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

         //프레임 시간 측정
         dResult += CheckTime(&LastTime, &NowTime, &Frequency);

         if (dResult >= 1.0 / 14.0)
         {
            dResult = 0.0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

            iResult = _findnext(FileHandle, &FindASCIIArt); //모든 작업 끝난 후 다음 파일 찾음

            eState = PLAY;
         }
      }
      _findclose(FileHandle);
	  return;
	  
   }
   
}