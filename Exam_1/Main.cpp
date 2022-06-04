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

double factor()  // функция отвечает за скобки 
{
    double result;
    char factor;
    int temp = 1;

    factor = cin.get();  // заставляет систему ожидать ввода пользователем любого символа, который она считывает


    switch (factor)
    {
    case '-':
        temp = -1;
    case '+':
        factor = cin.get();  // заставляет систему ожидать ввода пользователем любого символа, который она считывает
        break;
    }


    if (factor == '(')
    {
        result = example();
        factor = cin.get();  // заставляет систему ожидать ввода пользователем любого символа, который она считывает

        if (factor != ')')
        {
            cout << "Incorrect placement of brackets!" << endl;
            exit(-1); // код выхода 
        }
    }
    else
    {
        cin.putback(factor); // возвращаем обратно в буфер значение
        result = final_result();
    }

    return temp * result;

}

double final_result() // функция отвечает за результат
{
    double result = 0.0;
    char character; // символ
    double number = 10.0;
    int temp = 1;

    character = cin.get(); // заставляет систему ожидать ввода пользователем любого символа, который она считывает

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
        character = cin.get(); // заставляет систему ожидать ввода пользователем любого символа, который она считывает

        if (character >= '0' && character <= '9') {
            result = result * 10.0 + (character - '0');
        }
        else
        {
            cin.putback(character); // возвращаем обратно в буфер значение
            break;
        }
    }

    return temp * result;
}


int main() {
    double number;

    cout << "Enter an expression: "; // Введите выражение 

    number = example();

    cout << setprecision(12) << "Calculation result: " << number << endl;
    // setprecision - указывает сколько знаков после запетой, мы хотим видеть.
	return 0;
}