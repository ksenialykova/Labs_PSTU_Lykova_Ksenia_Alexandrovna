#include <iostream>
using namespace std;
int main() {
	int a = 5, b = 8;
	int& r = a;//r - ссылка на а
	int& s = a;//s - тоже ссылка на а
	int copy = a;
	r = b;//записываем значение b в а
	s += 2;//к а прибавляем 2
	b = copy;//записываем значение copy в b
	cout << a << " " << b << " "\
		<< r << " " << s << " " << copy;
	return 0;
}