#include "Header.h"

double degree() // функция отвечает за степень
{
    double result;
    char expression;
    vector < double > arguments; // создали вектор типа double 

    arguments.push_back(factor()); // добавление функции в вектор

    while (true)
    {
        expression = cin.get();  // заставляет систему ожидать ввода пользователем любого символа, который она считывает


        if (expression == '^') {
            arguments.push_back(factor());
        }
        else
        {
            cin.putback(expression); // возвращаем обратно в буфер значение
            break;
        }
    }

    for (int i = arguments.size() - 1; i > 0; i--) {
        arguments[i - 1] = pow(arguments[i - 1], arguments[i]);
    }
    // arguments.size - узнаем длину вектора
    // функция pow - возвращает результат первого аргумента, возведенного в степень второго аргумента.

    return arguments[0];
}

int main() {

	return 0;
}