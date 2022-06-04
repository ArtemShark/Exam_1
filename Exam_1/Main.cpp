#include "Header.h"

double example() // функция выражения
{
    double result;
    char expression; // выражение

    result = mult_div();

    while (true)
    {
        expression = cin.get(); // заставляет систему ожидать ввода пользователем любого символа, который она считывает

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

double mult_div() // функция отвечает за умножение, деление 
{
    char expression;
    double result;
    double temp;

    result = degree();

    while (true)
    {
        expression = cin.get();  // заставляет систему ожидать ввода пользователем любого символа, который она считывает

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
                exit(-1); // код выхода
            }

            result /= temp;

            break;
        default:
            cin.putback(expression); // возвращаем обратно в буфер значение
            return result;
        }
    }
}

int main() {

	return 0;
}