#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int max_size=25; //максимальный размер матрицы

// функция для проверки упрядоченности строки
// возвращает: 1(по возрастанию), -1(по убыванию), 0(не упорядочена или все элементы равны)
int check_order(int* arr, int N) 

{
    bool ascending=true;
    bool descending=true;
    for (int i=0;i<N-1;i++)
    {
        if (arr[i]>arr[i+1])
        {
            ascending=false; // нарушено возрастание 
        }
        if (arr[i]<arr[i+1])
        {
            descending=false; // нарушено убывание 
        }
    }
    if (ascending) return 1;
    if (descending) return -1;
    return 0;
}

// функция сортировки строки по возрастанию пузырьком 
void bubble_sort(int* arr, int N)
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL,"65.001");
    srand(time(0));
    
    int N;
     cout<<"Введите размерность массива: ";
     do
     {
        cin>>N;
     } while (N<=0 || N>=max_size);
     int matrix[max_size][max_size];
     cout<<"Исходный массив: "<<endl;
     for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            matrix[i][j]=rand()%101-50;
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;

    }

    for (int i=0; i<N; i++)
    {
        int order=check_order(matrix[i],N);
        if (order !=1)
        {
            bubble_sort(matrix[i],N);
        }
    }
    cout<<"Конечный массив:5 "<<endl;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}

