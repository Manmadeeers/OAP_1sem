﻿#include <iostream>
using namespace std;
void func(int* A, int n,int k)//функция для выполнения условия задания
{
	for (int i = 0; i < n; i++) {//сравнения введённого элемента с элементами массива
		if (A[i] == k) {//условие равентсва
			cout << i<<endl;
		}
		else if (A[i] < k) {//условие , если элемент меньше
			cout<<i<<endl;
		}
		else if (A[i] > k) {//условие , если элемент больше
			cout<<i<<endl;
		}
	}
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int n;//ввод размера массива
	cout << "Введите размер массива:";
	cin >> n;
	int k;//ввод числа , с которым будет сравнение
	cout << "Введите число , с которым будет сравнение:";
	cin >> k;
	int A[100];//задание массива А
	for (int i = 0; i < n; i++) {//заполнение массива случайными числами
		A[i] = rand() % 99;
	}
	cout << "\nМассив А:" << endl;//вывод элементов массива на экран
	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}
	cout << "\nНомера:" << endl;//вывод номернов подходящих элементов используя функцию выше
	func(A, n, k);

}