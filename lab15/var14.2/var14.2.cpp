#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int size_of_matrix;//ввод размера матрицы
	cout << "Введиет размер матрицы:";
	cin >> size_of_matrix;
	int** matrix;//создание указателя на двумерный массив
	matrix = new int* [size_of_matrix];//выделение динамической памяти
	for (int i = 0; i < size_of_matrix; i++) {//цикл в цикле для ввода элементов матрицы
		matrix[i] = new int[size_of_matrix];//выделение памяти под строку
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
	int number_of_string;//созданеи переменной для хранения номера строки с нулевым элементом
	int first_element;//создание переменной для хранения значения первого элемента строки с нулевым элементом
	for (int i = 0; i < size_of_matrix; i++) {//цикл в цикле для вычисления номера строки с нуевым элементом и её первого элемента
		for (int j = 0; j < size_of_matrix; j++) {
			if (matrix[i][j] == 0) {
				first_element = matrix[i][0];
				number_of_string = i;
				break;//выход из цикла , если такая строка найдена
			}
		}
	}
	cout << "Номер строки с нулевым элементом:" << number_of_string+1 << endl;//вывод номера строки с нулевым элементом
	cout << "Первый элемент строки с нулевым элементом:" << first_element << endl;//вывод первого элемента такой строки
	cout << "Матрица после преобразования:" << endl;
	for (int i = 0; i < size_of_matrix; i++) {//цикл в цикле для перобразования и вывод получишейся матрицы
		for (int j = 0; j < size_of_matrix; j++) {
			matrix[i][j] = matrix[i][j] - first_element;
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	for (int k = 0; k < size_of_matrix; k++) {//цикл для очистки элементов
		delete[]matrix[k];//очистка динамической памяти
	}
	delete[]matrix;//очистка динамической памяти
}