#include <iostream>
void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	int t;
	char a;
	float b;
	double c;
	cout << "Введите t= ";
	cin >> t;
	cout << "Введите a= ";
	cin >> a;
	cout << "Введите b= ";
	cin >> b;
	cout << "Введите c= ";
	cin >> c;
	cout << "t=" << t << " a=" << a << " b=" << b << " c=" << c << endl;
	cout << "Размер в байтах" << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "char: " << sizeof(char) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
}