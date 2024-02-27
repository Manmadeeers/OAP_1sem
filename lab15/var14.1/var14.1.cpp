#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int size_of_massive;//ввод размерности массива
	cout << "Введите размерность массива:";
	cin >> size_of_massive;
	double* ptr;//создание указателя на область памти
	if (!(ptr = (double*)malloc(size_of_massive * sizeof(double)))) {//проверка, достаточно ли выделенной памяти
		cout << "Недостаточно памяти!";//если нет  - вывод сообщения
		return;
	}
	for (int i = 0; i < size_of_massive; i++) {//цикл для ввода каждого элемента массива
		cout << "Введите элемент массива:";
		cin >> *(ptr + i);
	}
	double C;//ввод числа , с которым будет сравнение
	cout << "Введите число , с которым будет сравнение:";
	cin >> C;
	int elements_count = 0;//создание счётной переменной для подсчётна кол-ва элементов больших введённого числа
	for (int i = 0; i < size_of_massive; i++) {//цикл для вычисления такого кол-ва
		if (*(ptr + i) > C) {
			elements_count++;
		}
	}
	cout << "Кол-во элементов массива , больших заданного числа:" << elements_count << endl;//вывод кол-ва элементов больших заданного числа
	double* max = ptr;//создание указателя на максимальны элемент массива
	int position_of_max;//создание переменной для хранения позиции максимального по модулю элемента
	for (int i = 0; i < size_of_massive; i++) {//цикл для вычисления максимального по модулю элемента и его позиции в массиве
		if (abs(*(ptr + i)) > *max) {
			*max = abs(*(ptr + i));
			position_of_max = i;
		}
	}
	double mult_elements = 1;//создание переменной для вычисления произведения элементов стоящих после максимального по модулю
	for (int i = position_of_max + 1; i < size_of_massive; i++) {
		mult_elements = mult_elements * *(ptr + i);
	}
	cout << "Произведение элементов , идущих после наибольшего по модулю:" << mult_elements;//вывод такого произведения
}