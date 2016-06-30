#include"good.h"
#include"account good.h"
#include<fstream>
#include<iostream>


string good::getBarcode() {
	return barcode;
}
string good::getName() {
	return name;
}
string good::getUnit() {
	return unit;
}
float good::getPrice() {
	return price;
}
float good::getDiscount() {
	return discount;
}
