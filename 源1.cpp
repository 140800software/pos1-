#include<iostream>
#include<fstream>
#include"account good.h"
#include"good.h"
using namespace std;

int main() {
	acountGood*getFinalList();
	acountGood*head = getFinalList();
	acountGood*p = head;
	float total = 0, sub = 0;
	cout << "***商店购物清单***" << endl;
	while (p) {
		if (p->getDiscount() != 1)
			sub = sub + (1 - p->getDiscount())*p->getCount()*p->getPrice();
		cout << "名称：" << p->getName() << ",数量：" << p->getCount() << p->getUnit() << "，单价：" << p->getPrice() << "(元)" << ",小计：" << p->intatl() << endl;
		total = total + p->intatl();
		p = p->next;
	}
	cout << "----------------------" << endl;
	cout << "总计：" << total << endl;
	if (sub != 0)
		cout << "节省：" << sub << endl;
	cout << "**********************" << endl;
	system("pause");

	return 0;
}
good*getList() {
	good* ghead = NULL;
	good* gp = NULL;
	ifstream ifile("lalala.txt");

	if (!ifile) {
		cerr << "open error!" << endl;
		exit(1);
	}
	string jud;
	ifile >> jud;
	if (jud == "[") {
		while (ifile >> jud) {
			if (jud == "{") {//一个good节点生成
				string barcode, name, unit;
				float price;
				float discount = 1;
				while (ifile >> jud) {//节点内容读取
					if (jud == "},") {
						good*ptr = NULL;
						ptr = new good(barcode, name, unit, price, discount);

						if (ghead == NULL) {//节点生成并连接链表（当头指针为空）

							ghead = ptr;
							gp = ghead;
							break;
						}

						else {

							gp->next = ptr;
							gp = gp->next;

							break;


						}
					}
					else if (jud == "barcode:") {


						ifile >> barcode;

						continue;
					}
					else if (jud == "name:") {


						ifile >> name;

						continue;
					}
					else if (jud == "unit:") {


						ifile >> unit;

						continue;
					}
					else if (jud == "price:") {


						ifile >> price;

						continue;
					}
					else if (jud == "discount:") {


						ifile >> discount;

						continue;
					}

				}




			}
			else if (jud == "]")
				break;

		}
	}

	ifile.close();
	return ghead;
}
acountGood*getFinalList() {
	good*getList();

	acountGood* ahead = NULL;
	acountGood*ap = NULL;
	good*p = NULL;
	acountGood*pt = NULL;
	acountGood*pw = NULL;
	good*ghead = getList();
	p = ghead;
	while (p != NULL) {
		int judg = 1;
		pw = ahead;
		if (ahead == NULL) {
			acountGood*ptr = NULL;
			ptr = new acountGood(p->getName(), p->getUnit(), p->getPrice(), p->getDiscount());
			ahead = ptr;
			pt = ahead;
			continue;
		}
		while (pw != NULL) {
			if (pw->getName() == p->getName()) {
				pw->increase();
				judg = 0;

				break;
			}
			else
				pw = pw->next;

		}
		if (judg) {
			acountGood*ptr = NULL;
			ptr = new acountGood(p->getName(), p->getUnit(), p->getPrice(), p->getDiscount());
			pt->next = ptr;
			pt = pt->next;
			pt->increase();
		}
		p = p->next;
	}
	while (ghead->next != NULL)
	{
		p = ghead->next;
		ghead->next = p->next;
		delete p;
	}
	p =ghead;
	ghead = NULL;
	delete p;
	return ahead;



}
