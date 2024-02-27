#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	unsigned int A;
	cout << "Введите число А:";//ввод числа А
	cin >> A;
	cout << "Двоичное представление числа А:";
	unsigned int mask = 1 << 15;
	for (int i = 0; i <=16; i++) {
		putchar(mask & A ? '1' : '0');
		A <<= 1;
	}
	int p;
	cout << "\nС какой позиции начинать инвертировать биты?";
	cin >> p;
	int n;
	cout << "Сколько битов инвертировать?";
	cin >> n;
	unsigned int A1 = A;
	cout << "Число А после инверсии:";
	for (int i = 0; i < p; i++) {
		putchar(mask & A1 ? '1' : '0');
		A1 <<= 1;
	}

	for (int i = p; i <= n; i++) {
		putchar(mask & A1 ? '0' : '1');
		A1 <<= 1;
	}

	for (int i = n+1; i <16; i++) {
		putchar(mask & A1 ? '1' : '0');
		A1 <<= 1;
	}
}