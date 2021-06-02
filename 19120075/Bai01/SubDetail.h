#pragma once
#include "DetailItem.h"
#include <iostream>
class SubDetail :
    public DetailItem
{
public:
    DetailItem* search(string _id) {
        if (_id.compare(id) == 0) {
            return this;
        }
        return nullptr;
    }
    SubDetail(string _id, double _price) {
        role = 0;
        id = _id;
        price = _price;
    }
    double getPrice() {
        return price;
    }
    string toString() {
        string res = "{ Id: " + id + " , Price: ";
        res += to_string(price);
        res += " }";
        return res;
    }
    int countSubDetail() {
        return 1;
    }
};

