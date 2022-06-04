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
    double number;

    cout << "Enter an expression: "; // ������� ��������� 

    number = example();

    cout << setprecision(12) << "Calculation result: " << number << endl;
    // setprecision - ��������� ������� ������ ����� �������, �� ����� ������.
	return 0;
}