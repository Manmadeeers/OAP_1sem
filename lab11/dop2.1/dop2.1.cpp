#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	unsigned int A;//ввод числа А
	cout << "Введите число А:";
	cin >> A;
	unsigned int mask = 1;//задание маски для числа А
	if ((A & mask) == 0) {//проверка на кратность двум
		cout << "А кратно двум";
	}
	else {
		cout << "А не кратно двум";//условие , если а не кратно двум
	}
}