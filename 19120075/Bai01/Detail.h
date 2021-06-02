#pragma once
#include "DetailItem.h"
#include "SubDetail.h"
#include <vector>
class Detail :
    public DetailItem
{
private:
    vector<DetailItem*> subDetail;
    int numSubDetail;
public:
    DetailItem* search(string _id) {
        if (id.compare(_id) == 0) {
            return this;
        }
        else {
            for (int i = 0; i < numSubDetail; i++) {
                if (subDetail[i]->search(_id) != nullptr) {
                    return subDetail[i];
                }
            }
            return nullptr;
        }
    }
    Detail(vector<DetailItem*> _subDetail, int _numSubDetail, string _id) {
        role = 1;
        price = 0;
        subDetail.resize(_numSubDetail);
        numSubDetail = _numSubDetail;
        id = _id;
        for (int index = 0; index < _numSubDetail; index++) {
            subDetail[index] = _subDetail[index];
            price += _subDetail[index]->getPrice();
        }
    }
    double getPrice() {
        return price;
    }
    string toString() {
        string res = "{ ";
        res += "Id : " + id;
        res += " , Total price: ";
        res += to_string(price) + " ";
        for (int index = 0; index < numSubDetail; index++) {
            res += subDetail[index]->toString();
        }
        res += " }";
        return res;
    }
    int countSubDetail() {
        int count = 0;
        for (int i = 0; i < numSubDetail; i++) {
            count += subDetail[i]->countSubDetail();
        }
        return count;
    }
};

