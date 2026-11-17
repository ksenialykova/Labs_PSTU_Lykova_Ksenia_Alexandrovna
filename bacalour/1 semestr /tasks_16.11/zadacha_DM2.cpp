#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    // 1. Создание и ввод массива
    int* arr = new int[size];
    int* ptr = arr;
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; ++i) {
        cin >> *(ptr + i); // Ввод через указатель
    }

    // 2. Замена четных элементов
    ptr = arr; // Сбрасываем указатель на начало
    while (ptr < arr + size) {
        if (*ptr % 2 == 0) {
            if (ptr == arr) { // Первый элемент
                *ptr = 0;
            }
            else if (ptr == arr + size - 1) { // Последний элемент
                *ptr = 0;
            }
            else { // Элемент в середине
                *ptr = *(ptr - 1) + *(ptr + 1);
            }
        }
        ++ptr;
    }

    // 3. Вывод измененного массива
    cout << "Массив после замены: ";
    for (ptr = arr; ptr < arr + size; ++ptr) {
        cout << *ptr << " ";
    }
    cout << "\n";

    // 4. Освобождение памяти
    delete[] arr;
    return 0;
}