#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a=0.1, b=1.0, e=0.0001;
    int k=10, n_zad=10;
    double step=(b-a)/k;
    double x=a;

    while (x<=b)
    {
        double SN=0.0;
        double a_n=1.0;

        for (int n=0; n<n_zad; n++)
        {
            SN+=a_n;
            a_n=a_n*(2.0*n+3.0)/((2.0*n+1.0)*(n+1.0))*pow(x,2);
            
        }

        double SE=0.0;
        a_n=1.0;
        int n=0;

        while (abs(a_n)>=e)
        {
            SE+=a_n;
            a_n=a_n*(2.0*n+3.0)/((2.0*n+1.0)*(n+1.0))*pow(x,2);
            n++;
        }

        double Y=(1.0+2.0*pow(x,2))*exp(pow(x,2));

        cout<<"X= "<<x<<" SN= "<<SN<<" SE= "<<SE<<" Y= "<<Y<<endl;

        x+=step;
    }
    return 0;
}
