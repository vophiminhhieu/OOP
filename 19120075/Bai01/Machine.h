#pragma once
#include "SubDetail.h"
#include "Detail.h"
#include "DetailItem.h"
class Machine
{
private:
	vector<DetailItem*> listDetail;
public:
	void Add(DetailItem* detail) {
		listDetail.resize(listDetail.size() + 1);
		listDetail[listDetail.size() - 1] = detail;
	}
	void Show() {
		cout << "Ban co " << listDetail.size() << " chi tiet may: ";
		for (int i = 0; i < listDetail.size(); i++) {
			cout<<listDetail[i]->toString()<<endl;
		}
	}
	DetailItem* Search() {
		cout << " Moi ban nhap id : ";
		string _id;
		cin >> _id;
		for (int i = 0; i < listDetail.size(); i++) {
			if (listDetail[i]->search(_id) != nullptr) {
				return listDetail[i];
			}
		}
		return nullptr;
	}
	int countSubDetail() {
		int count = 0;
		for (int i = 0; i < listDetail.size(); i++) {
			count += listDetail[i]->countSubDetail();
		}
		return count;
	}
	double MoneyMachine() {
		double cost = 0;
		for (int i = 0; i < listDetail.size(); i++) {
			cost += listDetail[i]->getPrice();
		}
		return cost;
	}
	double MoneyDetail(DetailItem* it) {
		return it->getPrice();
	}
};

