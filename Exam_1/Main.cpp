#include "Header.h"

double factor()  // ������� �������� �� ������ 
{
    double result;
    char factor;
    int temp = 1;

    factor = cin.get();  // ���������� ������� ������� ����� ������������� ������ �������, ������� ��� ���������


    switch (factor)
    {
    case '-':
        temp = -1;
    case '+':
        factor = cin.get();  // ���������� ������� ������� ����� ������������� ������ �������, ������� ��� ���������
        break;
    }


    if (factor == '(')
    {
        result = example();
        factor = cin.get();  // ���������� ������� ������� ����� ������������� ������ �������, ������� ��� ���������

        if (factor != ')')
        {
            cout << "Incorrect placement of brackets!" << endl;
            exit(-1); // ��� ������ 
        }
    }
    else
    {
        cin.putback(factor); // ���������� ������� � ����� ��������
        result = final_result();
    }

    return temp * result;
}

int main() {

	return 0;
}