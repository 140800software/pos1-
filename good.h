#pragma once
#include<string>
#include"account good.h"

using namespace std;
class good {
private:
	string barcode;
	string name;
	string unit;
	float price;
	float discount=1;	
public:	good* next=NULL;//链表备用
	string getBarcode();//一下为得到类中属性
	string getName();
	string getUnit();
	float getPrice();
	float getDiscount();

	good(string bar, string nam,string un,float pri,float discou) {
		barcode = bar;
		name = nam;
		unit = un;
		price = pri;
		discount =discou;
	}		
};
