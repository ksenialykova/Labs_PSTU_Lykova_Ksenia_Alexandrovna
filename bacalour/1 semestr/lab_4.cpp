#include <iostream>
#include <stdlib.h>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,"65.001");
    int N;
    int arr[100];
    cout << "Укажите размерность массива: ";
    cin >> N;
    for(int i=0; i<N; i++)
    {
        arr[i]=rand()%100;
    }
    cout<<"Иcходный массив: ";
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    if (N>=5)
    {
        N-=5;
    }
    else
    {
        N=0;
    }
    int val1=arr[1];
    int val2=arr[2];
    int val3=arr[3];
    for (int i=N-1; i>=0; i--)
    {
        arr[i+3]=arr[i];
    }
    arr[0]=val1;
    arr[1]=val2;
    arr[2]=val3;
    N+=3;
    cout<<"Итоговый массив: ";
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}