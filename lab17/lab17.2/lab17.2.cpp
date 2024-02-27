#include <iostream>
using namespace std;

void MatrixCheck(int** matrix, int amm_of_colomns, int amm_of_rows)//функиция для изменения матрицы
{
	int number_of_row[100];//создание массива для включения в него номеров строк с отрицательными элемнетами
	int n = 0;//создане счётной переменной для вычисления размера массива
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для проверки каждого элемента матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			if (matrix[i][j] < 0) {//если элемент отрицательный
				number_of_row[n] = i;//добавление номера строки в массив
				n++;//увеличение счётной переменной на 1    
			}
		}
	}
	for (int i = 0; i < n; i++) {//цикл для вывода номерув нулевых строк
		cout << "Отрицтельный элемент в строке номер " << number_of_row[i]+1 << endl;
	}
	for (int i = 0; i < n; i++) {//цикл в цикле для уменьшения соответствующих столбцов вдвое
		for (int j = 0; j < amm_of_rows; j++) {
			matrix[j][number_of_row[i]] = matrix[j][number_of_row[i]] / 2;//уменьшение вдвое
		}
	}
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << matrix[i][j] << ' ';//вывод элемента с пробелом
		}
		cout << "\n";
	}
}



void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int amm_of_rows;//ввод кол-ва строк матрицы
	cout << "Введите количество строк:";
	cin >> amm_of_rows;
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	int amm_of_colomns;//ввод кол-ва столбцов матрицы
	cout << "Введите кол-во столбцов";
	cin >> amm_of_colomns;
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	int** matrix;//создание указателя на область памяти с массивом
	matrix = new int* [amm_of_rows];//выделение динамической памяти под массив
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для ввода элементов матрицы
		matrix[i] = new int[amm_of_colomns];//выделение динамической памяти под строку
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << "Введите элемент матрицы:";
			cin >> matrix[i][j];//ввод элемента матрицы
		}
	}
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	MatrixCheck(matrix, amm_of_colomns, amm_of_rows);//использование вышеописанной функции
	for (int i = 0; i < amm_of_rows; i++) {//цикл для очистки динамиеской памяти под строки
		delete[]matrix[i];
	}
	delete[]matrix;//очистка динамической памяти под массив
}