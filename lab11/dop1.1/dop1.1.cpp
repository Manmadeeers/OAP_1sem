﻿#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	unsigned int A;//ввод переменной А
	cout << "Ввод А:";
	cin >> A;
	unsigned int mask = 1 << 3;//задание маски для переменной А
	if((A&mask) == 0) {//проверка на кратность четырём
		cout << "А кратно четырём";
	}
	else{
		cout << "А не кратно чтырём";//условие , если А не кратно четырём
	}
}