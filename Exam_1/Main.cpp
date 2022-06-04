#include "Header.h"

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

	return 0;
}