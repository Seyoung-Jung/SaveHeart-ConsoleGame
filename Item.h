#ifndef __IOSTREAM_H__
#define __IOSTREAM_H__
#include <iostream>
#endif

#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif

using namespace std;



//static���� �� ����
static string Weathers[4] = {"�񵵸�","���","�ճ���","�޴뼱ǳ��"};
static string Sense[4] = {"�ռ���","���","�������͸�","�ſ�"};
static string Mood[4] = {"�ɴٹ�","����ũ","�Ź�","����å"};

class Items{

public:


	// ������ �� , ȣ����+5�� ���� , ȣ���� +3�� ���� , ȣ���� -5�� ���� , ȣ���� -10�� ���� 
	// ��, ���� = �� �ε���, ��� ���� = 4 
	// ���� = 0, �ܿ� = 1 , ��� ���� = 2 
	string weather;
	string sense;
	string mood;	
	

	Items(){
		weather = "";
		sense = "";
		mood = "";
	}
	Items(int w, int s, int m){	
		weather = Weathers[w];
		sense = Sense[s];
		mood = Mood[m];
		
	}
	void setWeather(int w){
		if(w==-1){
			weather = "";
			return;
		}
		weather = Weathers[w];		
	}
	void setSense(int s){
		if(s==-1){
			sense = "";
			return;
		}
		sense = Sense[s];
	}
	void setMood(int m){
		if(m==-1){
			mood = "";
			return;
		}
		mood = Mood[m];
	}
	void setItems(int w, int s, int m){	
		setWeather(w);
		setSense(s);
		setMood(m);
	}
	string getWeather(){
		if(weather==""){
			return "";
		}
		return weather;
	}
	string getSense(){
		if(sense==""){
			return "";
		}
		return sense;
	}
	string getMood(){
		if(mood==""){
			return "";
		}
		return mood;
	}
	int intWeather(){
		for(int i=0;i<4;i++){
			if(weather == Weathers[i])
				return i;
		}
		return -1;
	}
	int intSense(){
		for(int i=0;i<4;i++){
			if(sense == Sense[i])
				return i;
		}
		return -1;
	}
	int intMood(){
		for(int i=0;i<4;i++){
			if(mood == Mood[i])
				return i;
		}
		return -1;
	}

	string getItemString(){
      if(weather != "")
         return weather;
      if(sense != "")
         return sense;
      if(mood != "")
         return mood;
      return "";
   }

}; 