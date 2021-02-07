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
static string Tops[4] = {"����","����","����","�е�"};
static string Pants[4] = {"�߸���","�ݹ���","�����","������"};
static string Shoes[4] = {"������","����","�ȭ","����"};

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
		// ���� ����  
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

