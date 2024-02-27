#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float n[] = { 1.7,2.8,3.9,55.4,20,14.3,-2,4 };
	int lengthn = sizeof(n) / sizeof(n[0]);
	float min = n[0], max = n[0];
	for (int i = 0; i < lengthn; i++) {
		if (n[i] < min) {
			min = n[i];
			float* fr = n;
			float inmin = &n[i] - fr;
		}
		if (n[i] > max) {
			max = n[i];
			float* frm = n;
			float inmax = &n[i] - frm;
		}
	}
	int amm = int(sizeof(n[max]) / sizeof(n[min]);
	cout << "amm=" << amm << endl;

}