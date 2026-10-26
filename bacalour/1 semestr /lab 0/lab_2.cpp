#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
int main()
{
     setlocale(LC_ALL, "RU");
     double e = pow (10,-4), sum = 0.0;
     int n = 1;
     double a = 1.0;
     for (a; fabs(a) >= e; n++)
     {
        sum += a;
        a = a * pow(n / (n + 1.0), n);
     }
     cout << "Сумма ряда равна " << sum << endl;
     return 0;
}
