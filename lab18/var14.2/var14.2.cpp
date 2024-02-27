#include <iostream>//подключение библиотек
#include <Windows.h>
#include <stdio.h>
using namespace std;

int main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	FILE* f;//создание указателя на файл f
	errno_t errF;//переменная для ошибки
	errF = fopen_s(&f, "f.txt", "r");//открытие файла f для чтения 
	if (errF != 0) {//если ошибка
		perror("Ошибка открытия файла!");//вывести сообщение
		return 1;
	}
	int unique_numbers[100];//создание массива для хранения единственного вхождения каждого числа
	int num_unique = 0;//создание переменной для вычисления кол-ва никальных чисел
	int number;//создание переменной для текущего чистаемого элмента файла

	while (fscanf_s(f, "%d", &number) == 1) {//цикл для чтения каждого элемента файла
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

	fclose(f);//закрыть файл f
	FILE* g;//создание указателя на файл g
	errno_t errG;//переменная для ошибки
	errG = fopen_s(&g, "g.txt", "w");//открытие файла g для чтения
	if (errG != 0) {//если ошилка
		perror("Ошибка открытия файла!");//вывести сообзение 
		fclose(f);//закрыть файл f
		return 2;
	}
	for (int i = 0; i < num_unique; i++) {//запись уникальных элементов файла f в файл g
		fprintf(g, "%d\t", unique_numbers[i]);
	}
	fclose(g);//закрыть файл g
	printf("Программа успешно выполнена!");


	return 0;

}