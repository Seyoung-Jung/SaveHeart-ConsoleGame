#ifndef __IOSTREAM_H__
#define __IOSTREAM_H__
#include <iostream>
#endif

#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif

using namespace std;



//static으로 한 이유
static string Weathers[4] = {"목도리","우산","손난로","휴대선풍기"};
static string Sense[4] = {"손수건","향수","보조배터리","거울"};
static string Mood[4] = {"꽃다발","마이크","신문","유머책"};

class Items{

public:


	// 선택한 옷 , 호감도+5인 성향 , 호감도 +3인 성향 , 호감도 -5인 성향 , 호감도 -10인 계절 
	// 옷, 성향 = 각 인덱스, 상관 없음 = 4 
	// 여름 = 0, 겨울 = 1 , 상관 없음 = 2 
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