#pragma once
#include <string>
#include <iostream>
using namespace std;
class DetailItem
{
protected:
	string id;
	double price;
	int role; // role = 0 is subDetail , role = 1 is Detail

public:
	virtual DetailItem* search(string _id) {
		return nullptr;
	}
	string getId() {
		return id;
	}
	virtual double getPrice() {
		return 0;
	}
	virtual string toString() {
		return "";
	}
	virtual int countSubDetail() {
		return 0;
	}
};

