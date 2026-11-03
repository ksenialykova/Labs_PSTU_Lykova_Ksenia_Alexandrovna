/*
нарисовать равнобедренный треугольник с осноанием n 
   *
  ***
 *****
******* 
*/

#include <iostream>
using namespace std;
int main()
{
	int n, i, j;
	cin >> n;
	int z = 1;
	int p = (n - 1) / 2;
	for (i = 1; i <= (n + 1) / 2; ++i)
	{
		for (j = 1; j <= p; ++j)
		{
			cout << ' ';
		}
		for (j = 1; j <= z; ++j)
		{
			cout << '*';
		}
		cout << endl;
		p -= 1;
		z += 2;
    
	}
	return 0;
}