#include <iostream>//подключение необходимых библиотек
#include <ctime>
using namespace std;
void byLink(int& value)//функция для передачи по ссылке
{
	cout << "По указателю передано " << value << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	clock_t start = clock();//представление начального времени выполнения программы
	int number = 666;
	byLink(number);
	double time = (clock() - start) / (double)CLOCKS_PER_SEC;//расчёт времени выполнения программы исходя из полученных данных
	cout << "Время выполнения программы: " << time << " секунд" << endl;//вывод ответа
}

