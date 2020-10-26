
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	double x;
	double X[400], Y[400];
	const double pi = 3.141592653589793;
	double rez;
	for (int i = 0; i < 360; i++)
	{
		X[i] = i;
		Y[i] = sin(X[i] * pi / 180);
	}
	double h, x1, x2, y1, y2;
	cout << "Введите X= ";
	cin >> x;
	for (int i = 0; i < 360; i++)
	{
		if (X[i] <= x)
		{
			x1 = X[i - 1];
			y1 = Y[i - 1];
			x2 = X[i];
			y2 = Y[i];
		}
		break;
	}
	h = x2 - x1;
	rez = (y1 - y2) / h;
	cout << "Левая разностная производная: " << rez;
	return 0;
}
