#include <stdio.h>

// Объявление внешней ассемблерной функции
extern "C" int process_all_words(char* input, char* output);

int main()
{
    char input[256];  // Буфер для введенной строки
    char output[512]; // Буфер для результата

    // Основной цикл программы
    while (1)
    {
        // Вывод приглашения для ввода
        printf("Enter a string (empty to exit): ");

        // Чтение строки с клавиатуры
        fgets(input, sizeof(input), stdin);

        // Вызов ассемблерной функции
        int result = process_all_words(input, output);

        // Если были слова - выводим весь результат
        if (result == 0) {
            printf("%s", output); // Вывод всех слов
        }

        // Если в строке не было ни одного слова - завершаем программу
        if (result == 1)
            break;
    }

    return 0;
}