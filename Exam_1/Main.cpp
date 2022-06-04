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