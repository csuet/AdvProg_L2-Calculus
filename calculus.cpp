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
    //cos(x) = sqrt(1 - sin(x)^2)
    double result = mySin(x);
    result = result * result;
    result = 1 - result;
    result = mySqrt(result);
    return result;
}


/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double F(double x,int n) {
    int a;
    if (n % 2 == 0)
        a = 1;
    else
        a = -1;
    double temp = 1;
    for (int i = 1; i <= 2 * n + 1; i++)
        temp = temp * x / i;
    return a * temp;
}

double mySin(double x)
{
    //sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
    double sin = 0;
    int n = 0;
    while (abs(F(x, n)) > 0.000001)
    {
        sin += F(x, n);
        n += 2;
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
    double result = 1;
    while (fabs(result * result - x) / x >= 0.000001)
        result = (x / result  - result) / 2 + result;
    return result;
}