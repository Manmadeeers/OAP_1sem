#include <iostream>
#include <set>//подключение библиотеки для работы с контейнерами
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int k;
	cout << "Введите размерность массива:";//ввод размерности массива
	cin >> k;
	double M[100] = {};//задание массива М
	set<int> unique;//задание контейнера unique
	for (int i = 0; i < k; i++) {//цикл для ввод каждого элемента массива и ввод этого элемента в контейнер
		cout << "Введите элемент массива:";
		cin >> M[i];
		unique.insert(M[i]);
	}
	int count = unique.size();//присвоение переменной count значкния кол-ва элементов в контейнере
	cout << "Количество неповторяющихся элементов:" << count << endl;//выод ответа на экран
}