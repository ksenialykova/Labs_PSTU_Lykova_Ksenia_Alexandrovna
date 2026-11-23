#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    // ввод размера массива 
    int n, m;
    cout<<"Введите количсество строк массива: ";
    cin>>n;
    cout<<"Введите количество столбцов массива: ";
    cin>>m;
    if (n<=0 || m<=0)
    {
        cout<<"Размеры должны быть положительными!";
        return;
    }

    // создание исходного массива
    int** arr= new int* [n];
    for (int i=0; i<n; i++)
    {
        arr[i]=new int[m];
    }

    // заполнение случайными числами 
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            arr[i][j]=rand()%100-50;
        }
    }

    // вывод исходного массива 
    cout<<"Исходный массив: "<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }

    // ввод номеров добавляемых строки и столбца
    int k, p;
    cout<<"Введите номер добавляемой строки: ";
    cin>>k;
    cout<<"Введите номер добавляемого столбца: ";
    cin>>p;
    
    if (k<=0 || k>n || p<=0 || p>m)
    {
        cout<<"Неподходящий номер!"<<endl;
        
    // перед выходом освобождаем память
    for (int i=0; i<m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return;
    }

    int r=k-1; // индекс новой строки (с нуля)
    int s=p-1; // индекс нового столбца (с нуля)


    // формирование нового массива (размер: [n+1] на [m+1])
    int** res=new int* [n+1];
    for (int i=0; i<n+1; i++)
    {
        res[i]=new int [m+1];
    }
    
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<m+1; j++)
        {
            if (i==r || j==s)
            {
                // клетка новой строки или нового столбца-случайное число
                res[i][j]=rand()%100-50;
            }
            else
            {
                // обычная клетка-берем из исходного массива со сдвигом 
                int si=i;
                if (i>r) si=i-1;

                int sj=j;
                if (j>s) sj=j-1;

                res[i][j]=arr[si][sj];
            }
        }
    }

// печать результата 
cout<<"Конечный массив: "<< endl;
for( int i=0; i<n+1; i++)
{
    for (int j=0; j<m+1; j++)
    {
        cout<<res[i][j]<<' ';
    }
    cout<<endl;
}

// удаление массивов 
for (int i=0; i<n; i++)
{
    delete[] arr[i];
}
delete[] arr;
for (int i=0; i<n+1; i++)
{
    delete[] res[i];
}
delete[] res;

return 0;

}