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
        }
    }
}

double mult_div() // ������� �������� �� ���������, ������� 
{
    char expression;
    double result;
    double temp;

    result = degree();

    while (true)
    {
        expression = cin.get();  // ���������� ������� ������� ����� ������������� ������ �������, ������� ��� ���������

        switch (expression)
        {
        case '*':
            result *= degree();
            break;
        case '/':
            temp = degree();

            if (temp == 0.0)
            {
                cout << "Division by zero!" << endl;
                exit(-1); // ��� ������
            }

            result /= temp;

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