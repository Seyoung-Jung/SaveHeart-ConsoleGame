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
static string Tops[4] = {"나시","반팔","정장","패딩"};
static string Pants[4] = {"추리닝","반바지","긴바지","슬랙스"};
static string Shoes[4] = {"슬리퍼","샌들","운동화","구두"};

class Clothes{

public:

	string top;
	string pants;
	string shoes;
	

	Clothes(){
		top = Tops[0];
		pants = Pants[0];
		shoes = Shoes[0];
	}
	Clothes(int t, int p, int s){	
		// 상의 설정  
		top = Tops[t];
		pants = Pants[p];
		shoes = Shoes[s];
	}
	void setTop(int t){
		top = Tops[t];
	}
	void setPants(int p){
		pants = Pants[p];
	}
	void setShoes(int s){
		shoes = Shoes[s];
	}
	void setClothes(int t, int p, int s){	
		setTop(t);
		setPants(p);
		setShoes(s);
	}
	string getTop(){
		return top;
	}
	string getPants(){
		return pants;
	}
	string getShoes(){
		return shoes;
	}
	int intTop(){
		for(int i=0;i<4;i++){
			if(top == Tops[i])
				return i;
		}
		return 0;
	}
	int intPants(){
		for(int i=0;i<4;i++){
			if(pants == Pants[i])
				return i;
		}
		return 0;
	}
	int intShoes(){
		for(int i=0;i<4;i++){
			if(shoes == Shoes[i])
				return i;
		}
		return 0;
	}

}; 

