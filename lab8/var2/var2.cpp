﻿#include <iostream>
void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	float m = 4, c = -0.045,g=0;
	float b[4] = { 0.9,0.5,-2,-0.1 };//задание значений элементов массива b
	for (int j = 0; j < 4; j++) {//цикл,вычисляющий g
		g += c * pow(b[j] + 1, 2) * m;//вычисление значчения g
	}
	float y[5] = { 6,2,0.9,0.1,5 };//задание значения элементов массива у
	float q = 0, t = y[0];
	int n = sizeof(y) / sizeof(y[0]);//вычисление размерности массива у
	for (int f = 0; f < 5; f++) {//цикл для вычисления минимального элемента массива у
		if (y[f] < t) {
			t = y[f];
		}
	}
	for (int i = 0; i < 5; i++) {//вычисление значения q
		q += (y[i] + t) * n;
	}
	cout << "g=" << g << endl;//вывод на экран значения g
	cout << "t=" << t << endl;//вывод на экран значения t
	cout << "q=" << q << endl;//вывод на экран значения q
}