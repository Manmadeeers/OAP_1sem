#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int size_of_matrix;//ввод размера матрицы
	cout << "Введите размер квадратной матрицы:";
	cin >> size_of_matrix;
	int** matrix;//создание указателя на область памяти
	matrix = new  int* [size_of_matrix];//выделение динамической памяти
	for (int i = 0; i < size_of_matrix; i++) {//цикл для ввод элементов двумерного массива
		matrix[i] = new int[size_of_matrix];//выделение памяти под строку
		for (int j = 0; j < size_of_matrix; j++) {
			cout << "Введите элемент матрицы:";
			cin >> matrix[i][j];
		}
	}
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < size_of_matrix; i++) {//цикл для вывода введённой матрицы
		for (int j = 0; j < size_of_matrix; j++) {
			cout << matrix[i][j]<<' ';
		}
		cout << "\n";
	}
	int null_string;//создание переменной для хранения номера нулевой строки
	int null_control = 0;//создание счётной переменной для нахождения нулевой строки
	for (int i = 0; i < size_of_matrix; i++) {//цтикл в цикле для проверки каждого элемента матрицы
		for (int j = 0; j < size_of_matrix; j++) {
			if (matrix[i][j] == 0) {//условие если элемент нулевой
				null_control++;//увеличение контрольной переменной на 1
				if (null_control == size_of_matrix) {//если контрольная переменная достигает значения размера строки
					null_string = i;//присвоение переменной номера строки
					break;//выход из цикла
				}
			}
		}
	}
	
	cout << "Номер нулевой строки:" << null_string+1 << endl;//вывод номера нулевой строки
	cout << "Матрица после изменения:" << endl;
	int colomn = null_string;//присвоение переменной для номера столбца номера строки
	for (int i = 0; i < size_of_matrix; i++) {//цикл для уменьшения вдвое элементво соответствующего по номеру столбца
		matrix[i][colomn] = matrix[i][colomn] / 2;
	}
	for (int i = 0; i < size_of_matrix; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < size_of_matrix; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	for (int k = 0; k < size_of_matrix; k++) {//цикл для очистки элементов
		delete[]matrix[k];//очистка динамической памяти
	}
	delete[]matrix;//очистка динамической памяти
}