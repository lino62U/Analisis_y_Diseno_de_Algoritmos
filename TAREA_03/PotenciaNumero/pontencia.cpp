#include <iostream>
using namespace std;

double power(double base, int exponent) {
    if (exponent == 0)
        return 1.0;
    else if (exponent % 2 == 0) {
        double temp = power(base, exponent / 2);
        return temp * temp;
    } else {
        double temp = power(base, (exponent - 1) / 2);
        return base * temp * temp;
    }
}

int main() {
    double base;
    int exponent;

    cout << "Ingrese la base: ";
    cin >> base;

    cout << "Ingrese el exponente: ";
    cin >> exponent;

    double result = power(base, exponent);

    cout << "El resultado de " << base << "^" << exponent << " es: " << result << endl;

    return 0;
}
