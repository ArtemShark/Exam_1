#include "Header.h"

int main() {
    double number;

    cout << "Enter an expression: "; // ������� ��������� 

    number = example();

    cout << setprecision(12) << "Calculation result: " << number << endl;
    // setprecision - ��������� ������� ������ ����� �������, �� ����� ������.
	return 0;
}