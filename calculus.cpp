#include <iostream>
#include <string>
#include <cmath>

using namespace std;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
float F(float x,int n) {
    int a;
    if (n % 2 == 0)
        a = 1;
    else
        a = -1;
    float temp = 1;
    for (int i = 1; i <= 2 * n; i++)
        temp = temp * x / i;
    return a * temp;
}
double myCos(double x) 
{
    double cos=0;
    int n=0;
   while (abs(F(x, n)) > 0.00001) {
        cos += F(x, n);
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
    return sqrt(1-myCos(x)*myCos(x));
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
    else
    
    
    return sqrt(x);
}
