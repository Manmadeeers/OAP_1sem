﻿#include <iostream>
void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	float a[] = { 0.5,2,2.5,1,0,8 };//задание значений элементов массива а
	int lengtha = sizeof(a) / sizeof(a[0]);//вчисление размера массива a
	float b[] = { 2.3,4,0.5,2,3,9 };//задание зачений элементов массива b
	int lengthb = sizeof(b) / sizeof(b[0]);//вычисление значения массива b
	float x[] = { 2,1.3,0.4,5.1,7 };//задание значений элементов массива х
	int lengthx = sizeof(x) / sizeof(x[0]);//вычисление размера массива х

	float c,d=0;
	for (int i = 0; i < lengtha; i++) {//цикл для вычисления значения переменных d и с
		c = sqrt(a[i] + b[i]);//вычисление значения с
		d += c / (i+1);//вычисление значения d
		cout << "c=" << c << endl;//вывод значения с с каждой итерацией цикла
	}
	cout << "d=" << d << endl;//вывод значения d
	float min = x[0];
	for (int n = 0; n < lengthx; n++) {//циклЮвычисляющий минимальный элемент массива х
		if (x[n] < min) {
			min = x[n];
		}
	}
	
	float y;
	for (float t = 0.5; t < 3; t += 0.5) {//цикл,вычисляющий значение переменной у, в зависимости от переменной j
		if (t > 2) {
			y = min;//вычисление значения у
		}
		else if (t <= 2) {
			y = cos(pow(t, 2));//вычисление значения у
		}
		cout << "y=" << y << endl;//вывод значения у на экран
	}
}