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