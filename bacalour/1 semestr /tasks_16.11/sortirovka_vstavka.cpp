#include <iostream>
using namespace std;

int main() {
    int n;
    cout<< "Введите размер массива: ";
    cin>> n;

    int a[6];

    cout<< "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin>> a[i];
    }

    
    for (int i = 0; i < n - 1; i++) {
        int min_val = a[i];
        int k = i; 

        
        for (int j = i; j < n; j++) {
            if (min_val > a[j]) {
                min_val = a[j];
                k = j;
            }
        }

        
        a[k] = a[i];
        a[i] = min_val;
    }

    
    cout<< "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout<< a[i]<< " ";
    }
    cout<< endl;

    return 0;
}