#include <iostream>
#include <clocale>
using namespace std;

    int main() 
    {
        setlocale(LC_ALL, "RU");

        int n;
        cout<< "Введите размер массива: ";
        cin>> n;

        int a[6];

        cout<< "Введите элементы массива: ";
        for (int i = 0; i < n; i++) {
            cin>> a[i];
        }

        
        for (int i = 0; i < n - 1; i++) {
            
            for (int j = n - 1; j > i; j--) {
                if (a[j - 1] > a[j]) {
                    
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                }
            }
        }

        
        cout<< "Отсортированный массив: ";
        for (int i = 0; i < n; i++) {
            cout<< a[i]<< " ";
        }
        cout<< endl;

        return 0;
    }


