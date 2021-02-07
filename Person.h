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

//����� ���� ������ ��� Ŭ���� (ĳ���� ���� Ŭ���� ) 
class Person{
   private:
      string name; //�̸�
      string gender; //���� 
	  
   public:
	Person(){
		name = "������ �����";
		gender = "����";
	}
	Person(string name, string gender){
		this->name = name;
		this->gender = gender;
	}
	void setName(string name){ this->name = name; } //�̸� ���� 
	void setGender(string gender){ this->gender = gender; }  //���� ���� 
	string getName(){ return name; } //�̸� �������� 
	string getGender(){ return gender; } //���� ��������    

};

//�����ϴ� ����� ���� ������ ��� Ŭ���� 

static 	string nameArray[4] = {"������ ������","�����ο� ��ϼ�", "������ �־��", "�������� ȫ��ǥ"};

class Player:public Person{ 
	//����� ���� ���� ��� �޴´�.
 
	Clothes clothes;
	Items items;
	int heart; //ȣ���� 
   
public:
	Player() {
		//clothes, things, person ������ ? �ڵ� �ʱ�ȭ?
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
