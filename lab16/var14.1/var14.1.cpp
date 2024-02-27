#include <iostream>
using namespace std;


void OperationsWithMassive(double* massive,int size)//функция для реалищации условия
{
	double* min = massive;//создание указателя на минимальный элемент массива
	int position_of_min;//создание переменной для хранения позиции минимального элемента в массиве
	for (int i = 0; i < size; i++) {//цикл для вычисления минимадьного элемента
		if (abs(*(massive + i)) < abs(*min)) {
			min = (massive + i);
			position_of_min = i;
		}
	}
	cout << "Минимальный по модулю элемент массива:" << *min << endl;//вывод минимального по модулю элемента массива
	cout << "Позиция минимального элемента:" << position_of_min + 1 << endl;//вывод позиции такого элемента
	int position_of_first_negative;//создание переменной жля хранения позиции первого отрицательного элемента
	for (int i = 0; i < size; i++) {//цикл для вычисления позиции такого элемента
		if (massive[i] < 0) {
			position_of_first_negative = i;//присвоение переменной номера элемента
			break;//выход из цикла
		}
	}
	int sum = 0;//создание переменной для подсчёта суммы элементов после первого отрицательного
	for (int i = position_of_first_negative+1; i < size; i++) {//цикл для вычисления этой суммы
		sum += abs(massive[i]);
	}
	cout << "Сумма модулей элементов после первого отрицательного:" << sum;//вывод суммы
}

void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int size;//ввод размерности массива
	cout << "Введите размерность массива:";
	cin >> size;
	double* massive;//создание указателя на область памяти для массива
	massive = new double[size];//выделение динамической памяти под массив
	for (int i = 0; i < size; i++) {//цикл для ввода элементов массива
		cout << "Введите элемент массива:";
		cin >> massive[i];
	}
	OperationsWithMassive(massive, size);//использование вышеописанной функции
	delete[]massive;//очистка динамической памяти
}