
#include <iostream>
using namespace std;
int MashNULL() {
    double x = 1;
    for (int i = 0; i < 325; i++) {
        x = pow(10, -i);
        cout << "Точность:" << x << endl;
    }
    return 0;
}
template <class T>
T MashEps(T e, int& k)
{
    T e1;
    k = 0;

    do {
        e /= 2.0;
        e1 = e + 1.0;
        k++;
    } while (e1 > 1.0);

    return e;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Машинный ноль: " <<endl;
    MashNULL(); 
    cout << endl << endl;
    cout << "Машинный эпсилон: " << endl;
    int k = 0;

    float f_e = MashEps((float)1.0, k);
    cout << "float" << endl;
    cout << "Число делений на 2: " << k << endl;
    cout << "Машинный эпсилон: " << f_e << endl;

    double d_e = MashEps((double)1.0, k);
    cout << "double" << endl;
    cout << "Число делений на 2: " << k << endl;
    cout << "Машинный эпсилон: " << d_e << endl;

    long double ld_e = MashEps((long double)1.0, k);
    cout << "long double" << endl;
    cout << "Число делений на 2: " << k << endl;
    cout << "Машинный эпсилон: " << ld_e << endl;
    return 0;
}

