#include <iostream>
using namespace std;
int main()
{
	int a = 12;
	int* ptr = &a;//ptr - указатель, хранит адрес переменной а
	int copy = *ptr;//записываем в переменную copy значение, которое находится по адресу ptr
	(*ptr)++;//увеличиваем значение по адресу ptr на 1.Тоесть переменную а
	cout << a << ' ' << copy;
}