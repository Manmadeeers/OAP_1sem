#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	unsigned int A;//ввод числа А
	cout << "Введите число А:";
	cin >> A;
	unsigned int mask = 15;//задание маски для числа А
	if ((A&mask) == 0) {//проверка на кратность 16-ти
		cout << "А кратно шестнадцати";
	}
	else {
		cout << "А не кратно шестнадцати";//условие , если А не кратно 16-ти
	}
}