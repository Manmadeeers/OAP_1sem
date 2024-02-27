#include <iostream>//подключение библиотек
#include <Windows.h>
#include <stdio.h>
using namespace std;

int main()//главная функиця
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	FILE* fileA;//создание указател яна файл А
	errno_t errA;//переменная для ощибки
	errA = fopen_s(&fileA, "FileA.txt", "r");//открытие файла А для чтения
	if (errA != 0) {//если ошибка
		perror("Ошибка открытия файла!");//вывести сообщение
		return 1;
	}
	int amm_of_columns;//создание переменной для подсчёта кол-ва столбцов из первого элемента
	fscanf_s(fileA, "%d", &amm_of_columns);//считывание первого элемента из файла
	double matrix[100][100];//создание матрицы
	for (int i = 0; i < amm_of_columns; i++) {//цикл в цикле для добваления элементов файла в матрицу
		for (int j = 0; j < amm_of_columns; j++) {
			fscanf_s(fileA, "%lf", &matrix[i][j]);//считывание элементов из файла
		}
	}
	fclose(fileA);//закрытие файла А
	int k;//вовод номера искомого столбца с калвиатуры
	cout << "Введите искомый номер столбца: ";
	cin >> k;
	FILE* fileB;//создание указателя на файл В
	errno_t errB;//переменная для ошибки
	errB = fopen_s(&fileB, "FileB.txt", "w");//открытие файла В для записи
	if (errB != 0) {//если ошибка
		perror("Ошидка открытия файла!");//вывести сообщение
		fclose(fileA);//закрыть файл А
		return 2;
	}
	for (int i = 0; i < amm_of_columns; i++) {//цикл дял ввода нужных элементов матрицы в файл В
		fprintf(fileB, "%lf\n", matrix[i][k-1]);
	}
	fclose(fileB);//закрытие файла В
	printf("Программа успешно выполнена!");
	return 0;
}