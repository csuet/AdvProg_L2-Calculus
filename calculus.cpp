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
    double cosX = 1;
    double temp = 1;
    int i = 0;
    while (temp > 0.000001 || temp < -0.000001) {
        ++i;
        temp = temp * x / (2 * i) * x / (2 * i - 1);
        if (i & 1)
            cosX -= temp;
        else
            cosX += temp;
    }
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
    double temp = x;
    int i = 0;
    while (temp > 0.000001 || temp < -0.000001) {
        ++i;
        temp = temp * x / (2 * i + 1) * x / (2 * i);
        if (i & 1)
            sinX -= temp;
        else
            sinX += temp;
    }
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
    double result = 1.0;
    while (fabs(result * result - x) / x >= 0.0001)
        result = (x / result  - result) / 2 + result;
    return result;
}