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
double myCos(double x) 
{
    double cosX = 1;
    double factorial = 1;
    double oldcosX = 0;
    double n = 0;
    do
    {
        ++n;
        factorial = factorial * n * (n + 1);
        ++n;
        oldcosX = cosX;
        cosX = cosX - 1.0/factorial * pow(x, n) * pow(-1, n/2 + 1);
    } while (abs(cosX - oldcosX) > 0.001);
    return cosX;
}


/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sinX = x;
    double factorial = 1;
    double oldsinX = 0;
    double n = 1;
    do
    {
        ++n;
        factorial = factorial * n * (n + 1);
        ++n;
        oldsinX = sinX;
        sinX = sinX - 1.0/factorial * pow(x, n) * pow(-1, (n-1)/2 + 1);
    } while (abs(sinX - oldsinX) > 0.001);
    return sinX;
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