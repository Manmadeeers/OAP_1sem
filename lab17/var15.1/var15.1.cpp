#include <iostream>
using namespace std;


int MinElem(int* Arr, int size)//функция для вычисления минимального элемента массива
{
	int position_of_min;
	int* min = Arr;//создание указателя на массив
	for (int i = 0; i < size; i++) {//цикл для вычисления минимального элемента
		if (*(Arr + i) <= *min) {
			min = (Arr + i);
			position_of_min = i;
		}
	}
	return position_of_min;//вернуть позицию минимального элемента
}


int ArrCheck(int* Arr, int size)//функция для вычисления ответа
{
	int elem_count = 0;//создание счётной переменной для подсчёта кол-ва элементов после последнего минимального
	for (int i = MinElem(Arr,size) + 1; i < size; i++) {//цикл для подсчёта 
		if (*(Arr + i) < 0) {//если элемент отрицательный
			elem_count++;
		}
	}
	return elem_count;//вернуть кол-во элементов
}

void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int size;//ввод размерности массива
	cout << "Введите размерность массива:";
	cin >> size;
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	int* Arr;//создание указателя на область памяти для массива
	Arr = new int[size];//выделение динамической памяти под массив
	for (int i = 0; i < size; i++) {//цикл для ввода элементов массива
		cout << "Введите элемент массива:";
		cin >> *(Arr + i);
	}
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	cout << "Количество элементов после последнего отрицательного:"<<ArrCheck(Arr,size);//вывод ответа
	delete[]Arr;//очистка динамической памяти
}