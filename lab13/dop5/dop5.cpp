#include <iostream>//подключение стандартной библиотеки 
#include <string>//подключение библиотеки для работы со строками
#include <Windows.h>//подключение заголовоного файла для локализации консоли
#include <vector>//подклчение библиотеки для рботы с вктор-массивами
#include <algorithm>

using namespace std;

bool wordscomparison(const string& a, const string& b)
{
	return a.length() < b.length();
}


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string sent1;
	cout << "Первое предложение:";
	getline(cin,sent1);
	string sent2;
	cout << "Второе предложение:";
	getline(cin, sent2);
	string tmp[100];
	int n = 0;
	for (int i = 0; i < sent1.length(); i++) {
		if (sent1[i] != ' ') {
			tmp[n] += sent1[i];
		}
		else {
			n++;
		}
	}
	vector<string>words;
	for (int i = 0; i <= n; i++) {
		words.push_back(tmp[i]);
	}
	cout << endl;
	sort(words.begin(), words.end(), wordscomparison);
	for (const string& word : words) {
		cout << word << ' ';
	}
	cout << endl;
	string tmp2[100];
	int k = 0;
	cout << "Отсортированное первое:";
	for (int i = 0; i < sent2.length(); i++) {
		if (sent2[i] != ' ') {
			tmp2[k] += sent2[i];
		}
		else {
			k++;
		}
	}
	vector<string>words2;
	for (int i = 0; i <= k; i++) {
		words2.push_back(tmp2[i]);
	}
	sort(words2.begin(), words2.end(), wordscomparison);
	cout << "Отсортированное второе:";
	for (const string& word2 : words) {
		cout << word2 << ' ';
	}
	cout << endl;
	int f = 0;
	for (int i = 0; i <= k; i++) {
		if (words[f] != words2[f]) {
			cout << "Самое короткое слово первого предложения , которого нет во втором предложении: " << words[f];
			break;
		}
		else {
			f++;
		}
	}
}