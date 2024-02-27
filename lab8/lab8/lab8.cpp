//var 12
#include <iostream>//подключение стандартной библиотеки

void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");//локализация консоли
	float t = 0.45,sum=0;
	float x[5] = { 7,2,5.7,6,11 };//задание первого массива
	for (int i = 0; i < 5; i++) {//цикл , вычисляющий значения для вычисления у
		float a = pow(x[i], 3);
		sum += a;
	}
	float y = t * sum;//вычисление значения у
	float x1[6] = { 1.1,6.2,3,-4,6,1 };//задание второго массива
	float sum1 = 0;
	for (int n = 0; n < 6; n++) {//цикл ,вычисляющий значения для вычисления q
		float b = (x1[n] + 1) / x1[n];
		sum1 += b;
	}
	float q = t + sum1;//вычисление q
	cout << "y=" << y << endl;//вывод y
	cout << "q=" << q << endl;//вывод q
}
