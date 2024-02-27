#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int size_of_massive;//ввод размерности массива
	cout << "Введите размерность массива:";
	cin >> size_of_massive;
	double *ptr;//создание указателя на область памяти с массивом
	if (!(ptr = (double*)malloc(size_of_massive * sizeof(double)))) {//проверка, достаточно ли выделенной памяти
		cout << "Недостаточно памяти!";//если нет  - вывод сообщения
		return;
	}
	for (int i = 0; i < size_of_massive; i++) {//цикл для ввода элемента массива
		cout << "Введите элемент массива:";
		cin >> *(ptr + i);
	}
	double c;//ввод значения переменной , с которым будет сравнение
	cout << "Введите число , с которым будет сравнение:";
	cin >> c;
	int number_of_elements = 0;//создание счётной переменной для подсчёта кол-ва элементов , меньших ведённого числа
	for (int i = 0; i < size_of_massive; i++) {//цикл для вычисления таких элементов
		if (*(ptr + i) < c) {
			number_of_elements++;
		}
	}
	cout << "Кол-во элементов,меньших введённого числа:" << number_of_elements << endl;//вывод кол-ва элементов 
	int position_of_last_negative;//создание переменной для хранения номера последенго отрицательного элемента
	for (int i = size_of_massive - 1; i >= 0; i--) {//цикл для вычисления такого значения
		if (*(ptr + i) < 0) {
			position_of_last_negative = i;
			break;//выход из цикла . если значение найдено
		}
	}
	cout << "Позиция последнего отрицательного элемента массива:" << position_of_last_negative+1 << endl;//вывод позиции такого элемента на экран
	int sum_of_integer = 0;//создание переменной для значения суммы элементов после последнего отрицательного
	for (int i = position_of_last_negative; i < size_of_massive; i++) {//цикл для вычисления суммы
		sum_of_integer += int(*(ptr + i));
	}
	cout << "Сумма целых частей элементов:" << sum_of_integer << endl;//вывод суммы
}