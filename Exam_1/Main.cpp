#include "Header.h"

double final_result() // ������� �������� �� ���������
{
    double result = 0.0;
    char character; // ������
    double number = 10.0;
    int temp = 1;

    character = cin.get(); // ���������� ������� ������� ����� ������������� ������ �������, ������� ��� ���������

    switch (character)
    {
    case '-':
        temp = -1;
        break;
    default:
        if (character != '+')
            cin.putback(character);

        break;
    }

    while (true)
    {
        character = cin.get(); // ���������� ������� ������� ����� ������������� ������ �������, ������� ��� ���������

        if (character >= '0' && character <= '9') {
            result = result * 10.0 + (character - '0');
        }
        else
        {
            cin.putback(character); // ���������� ������� � ����� ��������
            break;
        }
    }

    return temp * result;
}

int main() {

	return 0;
}