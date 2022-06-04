#include "Header.h"

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

int main() {

	return 0;
}