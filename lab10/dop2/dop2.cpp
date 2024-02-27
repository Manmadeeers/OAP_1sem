#include <iostream>


using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double X[100] = {};//задание массива Х
	int n;
	cout << "Введите размерность массива:";//ввод размерности массива
	cin >> n;
	for (int i = 0; i < n; i++) {//ввод каждого элемента массива по очереди
		cout << "Введите элемент массива:";
		cin >> X[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++) {//вычисление равных пар
		if (X[i] == X[i + 1]) {
			count++;
		}
	}
	cout << "Кол-во однаковых пар:" << count << endl;//вывод ответа на экран
}