#include <stdio.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    // Открываем файлы для чтения
    FILE* fileA;//открытие файла А
    errno_t errA;
    errA= fopen_s(&fileA, "NameA.txt", "r");//Открытие файла А для чтения
    FILE* fileB;//файл В
    errno_t errB;
    errB = fopen_s(&fileB,"NameB.txt", "r");//открытие файла В для чтения
    FILE* fileC;//файл С
    errno_t errC;
    errC = fopen_s(&fileC,"NameC.txt", "r");//открытие файла С для чтения

    if (fileA == NULL || fileB == NULL || fileC == NULL) {//проверка файлов на ошибки
        printf("Ошибка при открытии файлов.\n");
        return 1;//завершенеи , если ощибка найдена
    }

    FILE* fileD;//файл D
    errno_t errD;
    errD = fopen_s(&fileD,"NameD.txt", "w");//открытие файла D для записи
    if (fileD == NULL) {//проферка файла на ощибки
        printf("Ошибка при создании/открытии файла NameD.txt\n");
        return 1;//выход , если ошилбки есть
    }

    int numElements;//создание переменной для размера файлов
    fscanf_s(fileA, "%d", &numElements);//вычисление размера 

 
    for (int i = 0; i < numElements; ++i) {//цикл для чтение элементов каждого файла
        int a, b, c;
        fscanf_s(fileA, "%d", &a);//чтение элемента файла А
        fscanf_s(fileB, "%d", &b);//чтение элемента фалйа В
        fscanf_s(fileC, "%d", &c);//чтение элемента файла С

        int min = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);//тернарный оператор для находения минимального элемента каждой позиции
        fprintf(fileD, "%d ", min);//запись такого элемента в файл D
    }

    //Закрытие всех файдов
    fclose(fileA);
    fclose(fileB);
    fclose(fileC);
    fclose(fileD);

    printf("Программа успешно выполнена!");//вывод сообщения об успешном выполнении программы в консоль

    return 0;
}
