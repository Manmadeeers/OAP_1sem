﻿#include <iostream>//подключение библиотек
using namespace std;

void matrixtoarr()//функция для преобразования матрицы в одномерный массив
{
	srand(time(0));//функция для реализации рандома
	int n;//переменная для размерности квадратной матрицы
	cout << "Какой размерности матрицу хотите привести к одномерному массиву? ";//ввод размерности квадратной матрицы с клавиатуры
	cin >> n;
	int** matrix;//создание указателя на двумерный массив квадратной матрицы
	matrix = new int* [n];//выделение динамической памяти под матрицу
	for (int i = 0; i < n; i++) {//цикл в цикле для заполнения матрицы
		matrix[i] = new int[n];//выделение динамиечской памяти под строки
		for (int j = 0; j < n; j++) {
			matrix[i][j] = rand() % 100 + 1;//заполнение матрицы элементами
		}
	}
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < n; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	int arr_size = n * n;//создание переменной для размерности массива
	int* new_arr;//создание указателя на область памяти под массив
	new_arr = new int[arr_size];//выделение динамической памяти под одномерный массив
	int count = 0;//создание счётной переменной для контроя индексов элементов одномерного массива
	for (int i = 0; i < n; i++) {//цикл в цикле для ввода элементов матрицы в массив
		for (int j = 0; j < n; j++) {
			new_arr[count] = matrix[i][j];//ввыод элемента
			count++;//увеличение счётной переменной на 1
		}
	}
	cout << "Получившийся массив:" << endl;
	for (int i = 0; i < arr_size; i++) {//цикл для вывода получившегося массива
		cout << new_arr[i] << ' ';
	}
	for (int i = 0; i < n; i++) {//цикл для очистки динамической памяти под строки
		delete[]matrix[i];
	}
	delete[]matrix;//очистка динамической памяти под матрицу
	delete[]new_arr;//очистка динамической памяти под одномерный массив
}
void arrtomatrix()//функция для преобразования одномерного массива в матрицу
{
	srand(time(0));//функция для реализации рандома
	int size;//создание переменной для ввода размерности массива
	cout << "Какой размерности одномерный массив хотите преобразовать в матрицу?";//ввод размерности массива с клавиатуры
	cin >> size;
	int* arr;//создание указателя на область памяти под одномерный массив
	arr = new int[size];//выделение динамической памяти под массив
	int check = sqrt(size);//создание переменной для возможности построения квадратной матрицы
	if (pow(check,2)==size) {//если возмжно построить квадратную матрицу
		cout << "Одномерный массив:" << endl;
		for (int i = 0; i < size; i++) {//цикл для заполнения одномерного массива элементами и вывода оных
			arr[i] = rand() % 100 + 1;//заполнение 
			cout << arr[i] << ' ';//вывод
		}
		cout << endl << "Получившаяся матрица:" << endl;
		int** new_matrix;//создание указателя на область памяти для матрицы
		new_matrix = new int* [check];//выделение динамиечской памяти под матрицуу
		int count = 0;//создание счётной переменной для контрля индексов одномерного массива
		for (int i = 0; i < check; i++) {//цкил в цикле для заполнения элементов матрицы элементами массива
			new_matrix[i] = new int[check];//выделение динамической памяти подьстрок
			for (int j = 0; j < check;j++) {
				new_matrix[i][j] = arr[count];//выделение динамиечкой памяти под строки
				cout << new_matrix[i][j] << ' ';//вывод элемента полчившейся матрицы
				count++;//увелиение контрольной переменной на 1
			}
			cout << "\n";
		}
		for (int i = 0; i < check; i++) {//цикл для очистки динамической памяти под строки новой матрицы
			delete[]new_matrix[i];//очистка памяти
		}
		delete[]new_matrix;//очистка динамической памяти под матрицу
		delete[]arr;//очитска динамической памяти под одномерный массив
	}
	else {//если же квадратную матрицу построить нельзя
		cout << endl << "Нельзя построить такую квадратную матрицу , останутся лишние элементы.";//вывести пообщение 
	}
}

void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	char sw;//создание переменной для работы оператора switch
	do {
		cout << "Что хотите сделать?\n\t1-Преобразовать матрицу размерности n*n в одномерный массив\n\t2-Преобразовать одномерный массив размерности в матрицу размерности n*n\n\t3-Выход из программы\n\t";//вывод вариантов использования программы
		cin >> sw;//ввод варианта использования программы
		while (!(sw >= '0' && sw <= '9')) {//проверка на ввод нецифрового символа
			cout << "Варианты нужно вводить цифрами!Попробуйте ещё раз:" << endl;//если да - вывести сообщение 
			cout << "Что хотите сделать?\n\t1-Преобразовать матрицу размерности n*n в одномерный массив\n\t2-Преобразовать одномерный массив размерности в матрицу размерности n*n\n\t3-Выход из программы\n\t";//вывод вариантов использования программы
			cin >> sw;//ввод варианта использования программы
		}
		switch (sw-'0') {//оператор switch, использующий числовое представление символьного значения переменной sw
		case 1: matrixtoarr(); break;//если введена 1
		case 2:arrtomatrix(); break;//если введена 2
		case 3:exit(0);//если введена 3
		default:cout << "Введён неправильный вариант использования программы!Попробуйте ещё раз:"<<endl;//если введена цифра , которая не является вариантом выполнения программы
		}

	} while (true);//постусловие для возможности выполнения программы несколько раз
}