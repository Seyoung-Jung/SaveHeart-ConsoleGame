#ifndef __UTIL_H__
#define __UTIL_H__
#include "util.h"
#endif

#ifndef __CLOTHES_H__
#define __CLOTHES_H__
#include "Clothes.h"
#endif

#ifndef __ITEM_H__
#define __ITEM_H__
#include "Item.h"
#endif

using namespace std;

//사람에 대한 정보를 담는 클래스 (캐릭터 생성 클래스 ) 
class Person{
   private:
      string name; //이름
      string gender; //성별 
	  
   public:
	Person(){
		name = "차분한 김상중";
		gender = "여성";
	}
	Person(string name, string gender){
		this->name = name;
		this->gender = gender;
	}
	void setName(string name){ this->name = name; } //이름 설정 
	void setGender(string gender){ this->gender = gender; }  //성별 설정 
	string getName(){ return name; } //이름 가져오기 
	string getGender(){ return gender; } //성별 가져오기    

};

//게임하는 사람에 대한 정보를 담는 클래스 

static 	string nameArray[4] = {"차분한 강수지","자유로운 김완선", "엉뚱한 최양락", "보수적인 홍준표"};

class Player:public Person{ 
	//사람에 대한 것을 상속 받는다.
 
	Clothes clothes;
	Items items;
	int heart; //호감도 
   
public:
	Player() {
		//clothes, things, person 생성자 ? 자동 초기화?
		heart = 100;
	}  
	void setHeart(int heart){
		this->heart += heart;
	} 
	int getHeart(){
		return heart;
	}
	void setclothes(int t, int p, int s){
		clothes.setClothes(t,p,s);		
	}
	Clothes getClothes(){
		return clothes;
	}
	void setitems(int w, int s, int m){
		items.setItems(w,s,m);
	}
	Items getItems(){
		return items;
	}
	string stringItems(){
      return items.getItemString();
   }
};
