#include "Header.h"

double degree() // ������� �������� �� �������
{
    double result;
    char expression;
    vector < double > arguments; // ������� ������ ���� double 

    arguments.push_back(factor()); // ���������� ������� � ������

    while (true)
    {
        expression = cin.get();  // ���������� ������� ������� ����� ������������� ������ �������, ������� ��� ���������


        if (expression == '^') {
            arguments.push_back(factor());
        }
        else
        {
            cin.putback(expression); // ���������� ������� � ����� ��������
            break;
        }
    }

    for (int i = arguments.size() - 1; i > 0; i--) {
        arguments[i - 1] = pow(arguments[i - 1], arguments[i]);
    }
    // arguments.size - ������ ����� �������
    // ������� pow - ���������� ��������� ������� ���������, ������������ � ������� ������� ���������.

    return arguments[0];
}

int main() {

	return 0;
}