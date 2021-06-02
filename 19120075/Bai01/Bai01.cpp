#include "Detail.h"
#include "DetailItem.h"
#include "SubDetail.h"
#include "Machine.h"
void menuPrint() {
	cout << endl << endl << endl;
	cout << "                                       MENU" << endl;
	cout << "        [1] .    Nhap cac chi tiet cho may" << endl;
	cout << "        [2] .    Tim kiem mot chi tiet may theo ma so" << endl;
	cout << "        [3] .    Tinh tien cho mot chi tiet may, hoac cho may" << endl;
	cout << "        [4] .    Xuat cac chi tiet may" << endl;
	cout << "        [5] .    Dem so luong chi tiet don co trong cai may" << endl;
	cout << "        [6] .    Thoat" << endl;
	cout << endl << endl;
	cout << "                 Moi ban nhap lua chon : ";
}

DetailItem* option1() {
	cout << "        Moi ban nhap them chi tiet moi. Ban muon nhap chi tiet don (0) hay phuc (1) : ";
	int option = 0;
	cin >> option;
	DetailItem* dtItem;
	string id;
	double price;
	int count;
	cout << "Moi ban nhap id: ";
	cin >> id;
	if (option == 0) {
		cout << "Moi ban nhap gia: ";
		cin >> price;
		dtItem = new SubDetail(id, price);
	}
	else {
		cout << "Moi ban nhap so luong chi tiet con (>=1) : ";
		cin >> count;
		vector<DetailItem*> dt;
		dt.resize(count);
		for (int i = 0; i < count; i++) {
			cout << "--------------   Moi ban nhap chi tiet thu " << (i + 1) << "   --------"<<endl;
			dt[i] = option1();
		}
		dtItem = new Detail(dt, count, id);
	}
	return dtItem;
}

int main()
{
	Machine machine;
	int option = 0;
	menuPrint();
	cin >> option;
	system("cls");
	while (option != 6) {
		if (option == 1)
		{
			machine.Add(option1());
			system("cls");
		}
		else if (option == 2) {
			DetailItem* it = machine.Search();
			if (it != nullptr) {
				cout << "Da tim thay chi tiet cua ban tim: " << endl << it->toString() << endl;
			}
			else {
				cout << "Khong tim thay chi tiet can tim!!" << endl;
			}
		}
		else if (option == 3) {
			cout << "Ban muon tinh tien cho chi tiet (0) hay cho may (1): ";
			int subOption = 0;  cin >> subOption;
			if (subOption == 0) {
				DetailItem* it = machine.Search();
				if (it != nullptr) {
					cout << "Tong tien: " << machine.MoneyDetail(it);
				}
				else {
					cout << "Khong tim thay chi tiet can tim!!" << endl;
				}
			}
			else {
				cout << "Tong tien: " << machine.MoneyMachine();
			}
		}
		else if (option == 4) {
			machine.Show();
		}
		else if (option == 5) {
			cout << "Tong so chi tiet don la: " << machine.countSubDetail() << endl;
		}
		menuPrint();
		cin >> option;
		system("cls");
	}
}