#include <iostream>
#include <string>
#include <cmath>

#define EPSILON 0.0001f

using std::cout;
using std::endl;
using std::stod;
using std::string;

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
    while (x > 2 * M_PI)
    {
        x -= 2 * M_PI;
    }
    double cos = 1.00;
    int i = 1;
    double temp = 1.00;
    while (temp > 0.00001)
    {
        temp = 1.00;
        for (int j = 1; j <= 2 * i; j++)
        {
            temp *= x * 1.00 / j;
        }
        if (i % 2 == 0)
            cos += temp;
        else
            cos -= temp;
        i++;
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
    while (x > 2 * M_PI)
    {
        x -= 2 * M_PI;
    }
    double sin = x * 1.00;
    int i = 1;
    double temp = 1.00;
    while (temp > 0.00001)
    {
        temp = 1.00;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            temp *= x * 1.00 / j;
        }
        if (i % 2 == 0)
            sin += temp;
        else
            sin -= temp;
        i++;
    }
    return sin;
}

/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x)
{
    if (x < 0)
    {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double result = 1.0f;
    while (fabs(result * result - x) / x >= EPSILON)
        result = (x / result - result) / 2 + result;
    return result;
}