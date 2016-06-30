#pragma once
#include<string>
#include"good.h"

using namespace std;
class acountGood{
private:
	string name;
	string unit;
	float price;
	int count;//数量
	float discount;
public:		acountGood*next=NULL;//指针备用，链表用
	void increase() {
		count++;
	}
	float intatl() {
		return price*count*discount;
	}
	string getName();//以下是得到类中属性的函数
	string getUnit();
	float getPrice();
	int getCount();
	float getDiscount();
	
	acountGood(string na,string uni,float pric,float dis) {
		name = na;
		unit = uni;
		price = pric;
		count = 0;
		discount = dis;		
	}		
};
