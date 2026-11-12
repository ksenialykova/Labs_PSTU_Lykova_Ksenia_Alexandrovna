#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "65.001");

    // Исходная строка (максимум 255 символов по заданию)
    char str[256];
    cout << "Введите строку: ";
    cin.getline(str, 256); // Замена Gets(s)

    // Создаем три пустые строки для наших групп слов
    char digitsStr[256] = "";  // Для слов только из цифр
    char lettersStr[256] = ""; // Для слов только из букв
    char mixedStr[256] = "";   // Для смешанных слов

    int len = strlen(str); // Длина исходной строки
    int i = 0;

    // Проходим по всей строке
    while (i < len) 
    {
        // Пропускаем пробелы и точку (разделители)
        while (i < len && (str[i] == ' ' || str[i] == '.')) 
        {
            i++;
        }

        // Если дошли до конца строки - выходим
        if (i >= len) break;

        // Начало нового слова
        char word[256];
        int w_len = 0;

        // Считываем слово до следующего пробела или точки
        while (i < len && str[i] != ' ' && str[i] != '.') 
        {
            word[w_len] = str[i];
            w_len++;
            i++;
        }
        word[w_len] = '\0'; // Завершаем слово нулевым символом

        //  Анализируем, из чего состоит слово
        bool hasDigit = false;
        bool hasLetter = false;
        bool hasOther = false;

        for (int j = 0; j < w_len; j++) 
        {
            if (isdigit(word[j])) hasDigit = true;
            else if (isalpha(word[j])) hasLetter = true;
            else hasOther = true; // Если есть другие символы (не буквы и не цифры)
        }

        // Распределяем слово в нужную строку
        if (hasDigit && !hasLetter && !hasOther) 
        {
            // Только цифры
            strcat(digitsStr, word);
            strcat(digitsStr, " ");
        } 
        else if (hasLetter && !hasDigit && !hasOther) 
        {
            // Только буквы
            strcat(lettersStr, word);
            strcat(lettersStr, " ");
        } 
        else 
        {
            // Смешанные (есть и буквы, и цифры, либо спецсимволы)
            strcat(mixedStr, word);
            strcat(mixedStr, " ");
        }
    }

    // Выводим результат
    cout << "Результат: ";
    cout << digitsStr << lettersStr << mixedStr << endl;

    return 0;
}