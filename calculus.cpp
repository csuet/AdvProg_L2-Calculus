#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    int a, n;
    if (n % 2 == 0) a = 1;
        else a = -1;
    float temp;
    for (int i = 1; i <= 2*n; i++)
        temp = temp * x/i;
    double count = a*temp;
    float cos = 1;
    while (count > 0.00001)
    {
        cos += count;
        n++;

    }
    return cos;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{

    int a, n;
    if (n % 2 == 0) a = 1;
    else a = -1;
    float temp;
    for ( int i = 1; i <= 2*n + 1; i++ )
        temp = temp * x/i;
    double count = a*temp;
    float sin = 0;
    while (count > 0.00001){
        sin += count;
        n++;
    }
            return sin;

}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else{
        double sqrt;
        double a[100];
        a[0] = 10.00;
        int i=1;
        do{
            a[i]=(a[i-1]+(x/a[i-1]))/2;
            sqrt=a[i];
            i++;
        }while(a[i]!=a[i-1] && i<100);
        return sqrt;
    }
            return 0;

}
