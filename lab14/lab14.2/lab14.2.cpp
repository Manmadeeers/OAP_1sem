﻿#include <iostream>
using namespace std;


void main()
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	const int m = 4;//задание размерности многомерного массива
	const int n = 5;
	int matrix[m][n];//инициализация матрицы
	for (int i = 0; i < m; i++) {//цикл в цикле для ввода каждого элемента матрицы
		for (int j = 0; j < n; j++) {
			cout << "Введите элемент матрицы";
			cin >> matrix[i][j];
		}
		cout << "\n";
	}
	cout << "Получившаяся матрица:" << endl;//вывод получившейся матрицы для удобства визуального сравнения
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	//проверка
	int k = 0;//создание счётной переменной для контрля строк
	for (int i = 0; i < m; i++) {//цикл в цикле для проверки каждого элемента в каждой строке
		for (int j = 0; j, n; j++) {
			if (matrix[i][j] > 0) {//если хотя бы один элемент положителен - выход из подцикла и переход на следующую строку
				k++;
				break;
			}
		}
	}
	if (k != 4) {//если не в каждой строке есть хотя бы 1 положительный элемент 
		cout << "Ни в одной строке нет положительного элемента.";//вывод сообщения на экран
	}
	if (k == 4) {//если в каждой строке есть хотя бы 1 положительный элемент
		cout << "Матрица с изменёнными знаками элементов:" << endl;
		for (int i = 0; i < m; i++) {//цикл в цикле для вывода каждого элемента матрицы с изменённым знаком
			for (int j = 0; j < n; j++) {
				matrix[i][j] = matrix[i][j] * -1;
				cout << matrix[i][j] << ' ';
			}
			cout << "\n";
		}
	}
}