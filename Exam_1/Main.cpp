#include "Header.h"

double example() // ������� ���������
{
    double result;
    char expression; // ���������

    result = mult_div();

    while (true)
    {
        expression = cin.get(); // ���������� ������� ������� ����� ������������� ������ �������, ������� ��� ���������

        switch (expression)
        {
        case '+':
            result += mult_div();
            break;
        case '-':
            result -= mult_div();
            break;
        default:
            cin.putback(expression); // ���������� ������� � ����� ��������
            return result;
        }
    }
}

int main() {

	return 0;
}