#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int b = 20;
	int& r = a; //r ссылка для переменной а
	r = b;//значение b записывается в а и в r
	r++;//увеличиваем r на 1 и а на 1
	cout << a << ' ' << b;
	return 0;
}