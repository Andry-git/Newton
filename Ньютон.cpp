using namespace std;
#include <iostream>
#include <vector>

double interpolyac()
{
	double n, x, y, z, result = 0;
	double currentX;
	cout << "Введите количество точек: \n";
	cin >> n;
	vector <double> vectorX(n), vectorY(n);
	vector <double> func(n), f(n);

	cout << "Введите значения X: " << endl;

	for (int i = 0; i < n; i++) {
		cout << "Введите X" << i << "= ";
		cin >> x;
		vectorX.at(i) = x;
	}

	cout << "Введите значения Y: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Введите Y" << i << "= ";
		cin >> y;
		vectorY.at(i) = y;
	}
	cout << "X: ";
	for (int i = 0; i < n; i++) {
		cout << vectorX.at(i) << "\t";
	}
	cout << endl;
	cout << "Y: ";
	for (int i = 0; i < n; i++) {
		cout << vectorY.at(i) << "\t";
	}
	cout << endl;
	/////////////////////////////////////////////////
	cout << "Введите x: ";
	cin >> currentX;
	for (int i = 0; i < n-1; i++) {
		func.at(i) = (vectorY.at(i + 1) - vectorY.at(i)) / (vectorX.at(i + 1) - vectorX.at(i));
	}
	f.at(0) = func.at(0);
	int k = 2;
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n - k; i++) {
			func.at(i) = (func.at(i + 1) - func.at(i)) / (vectorX.at(i + k) - vectorX.at(i));
		}
		f.at(j) = func.at(0);
		k++;
	}
	result = vectorY.at(0);
	double d = currentX - vectorX.at(0);
	int j = 1;
	for (int i = 1; i < n; i++) {
		for (j; j < i; j++) {
			d = d * (currentX - vectorX.at(j));
		}
		result = result + (f.at(i-1) * d);
		if (i > 1)
			j++;
	}
	return result;
}

int main()
{
	double rez = 0;
	setlocale(LC_ALL, "Rus");
	rez = interpolyac();
	cout << endl;
	cout << "Результат: " << rez;
	return 0;
}