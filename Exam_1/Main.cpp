#include "Header.h"

int main() {
    double number;

    cout << "Enter an expression: "; // Введите выражение 

    number = example();

    cout << setprecision(12) << "Calculation result: " << number << endl;
    // setprecision - указывает сколько знаков после запетой, мы хотим видеть.
	return 0;
}