#include <iostream>//подключение библиотек
#include <Windows.h>
#include <stdio.h>
using namespace std;

int main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	FILE* fileA;//создание указателя на файл f
	errno_t errA;//переменная для ошибки
	errA = fopen_s(&fileA, "fileA.txt", "r");//открытие файла f для чтения 
	if (errA != 0) {//если ошибка
		perror("Ошибка открытия файла!");//вывести сообщение
		return 1;
	}
	int unique_numbers[100];//создание массива для хранения единственного вхождения каждого числа
	int num_unique = 0;//создание переменной для вычисления кол-ва никальных чисел
	int number;//создание переменной для текущего чистаемого элмента файла

	while (fscanf_s(fileA, "%d", &number) == 1) {//цикл для чтения каждого элемента файла
		int isDuplicate = 0;//созжание контрольной переменной 
		for (int i = 0; i < num_unique; i++) {//цикл для проверки вхождения уникальных чисел
			if (unique_numbers[i] == number) {
				isDuplicate = 1;//если найдено повторное фхождение
				break;//выйти из подцикла
			}
		}
		if (!isDuplicate) {//добавить уникальное число в массив
			unique_numbers[num_unique] = number;
			num_unique++;
		}
	}

	fclose(fileA);//закрыть файл f
	FILE* fileB;//создание указателя на файл g
	errno_t errB;//переменная для ошибки
	errB = fopen_s(&fileB, "fileB.txt", "w");//открытие файла g для чтения
	if (errB != 0) {//если ошилка
		perror("Ошибка открытия файла!");//вывести сообзение 
		fclose(fileA);//закрыть файл f
		return 2;
	}
	for (int i = 0; i < num_unique; i++) {//запись уникальных элементов файла f в файл g
		fprintf(fileB, "%d\t", unique_numbers[i]);
	}
	fclose(fileB);//закрыть файл g
	printf("Программа успешно выполнена!");


	return 0;

}