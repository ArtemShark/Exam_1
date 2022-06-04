#include "Header.h"

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