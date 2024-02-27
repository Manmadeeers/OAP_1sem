#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int size_of_matrix;//ввод размера матрицы
	cout << "Введите размер матрицы:";
	cin >> size_of_matrix;
	int** matrix;//создание указателя на область памяти
	matrix = new int* [size_of_matrix];//выделение динамической памяти
	for (int i = 0; i < size_of_matrix; i++) {//цикл в цикле для ввода элементов матрицы
		matrix[i] = new int[size_of_matrix];//выделение динамической памяти под строку
		for (int j = 0; j < size_of_matrix; j++) {
			cout << "Введите элемент матрицы:";
			cin >> matrix[i][j];
		}
	}
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < size_of_matrix; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < size_of_matrix; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	int number_of_null_strings = 0;//создание счётной переменной для подстчёта строк с нулевыми элементами
	for (int i = 0; i < size_of_matrix; i++) {//цикл в цикле для проверки на наличие нулевого элемента в каждой строке
		for (int j = 0; j < size_of_matrix; j++) {
			if (matrix[i][j] == 0) {//если нулевой элемент есть
				number_of_null_strings++;//увеличение счётной переменной на 1
				break;//выход из цикла
			}
		}
	}
	if (number_of_null_strings == size_of_matrix) {//елси вв каждой строке есть нулевой элемент 
		cout << "Во всех строках есть хотя бы один нулевой элемент.";
	}
	else {//если не в каждой строке есть нулевой элемент
		cout << "Матрица после преобразования:" << endl;
		for (int i = 0; i < size_of_matrix; i++) {//цикл в цикле для вывода преобразованной матрицы
			for (int j = 0; j < size_of_matrix; j++) {
				if (matrix[i][j] < 0) {//если элемент матрицы меньше нуля
					matrix[i][j] = 0;//превратить такой элемент в нуль
				}
				cout << matrix[i][j] << ' ';
			}
			cout << "\n";
		}
	}
	for (int k = 0; k < size_of_matrix; k++) {//цикл для очистки элементов
		delete[]matrix[k];//очистка динамической памяти
	}
	delete[]matrix;//очистка динамической памяти
}