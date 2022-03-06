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
/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
float F(float x,int n) {
    int a;
    if (n % 2 == 0)
        a = 1;
    else
        a = -1;
    float temp = 1;
    for (int i = 1; i <= 2 * n + 1; i++)
        temp = temp * x / i;
    return a * temp;
}
double mySin(double x)
{

    int sin = 0;
    int n = 0;
    while (abs(F(x, n)) > 0.00001) {
        sin += F(x, n);
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
    else {
        double result = 1.0f;
    while (fabs(result * result -x) / x >= 0.0001f)
        result = (x / result  - result) / 2 + result;
    return result;
    }
}
double myCos(double x)
{
    return mySqrt(1-mySin(x)*mySin(x));
}
