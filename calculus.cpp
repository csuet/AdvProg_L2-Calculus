#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::endl;
using std::stod;
using std::string;

const double EPSILON = 1e-5;
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
    // Maclaurin series
    double numerator = 1, res = 0;
    unsigned long long denominator = 1;
    int count = 2;
    while (fabs(numerator) / denominator > EPSILON)
    {
        res += numerator / denominator;
        numerator *= -x * x;
        denominator *= (count - 1) * count;
        count += 2;
    }
    return res;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    // Maclaurin series
    double numerator = x, res = 0;
    unsigned long long denominator = 1;
    int count = 3;
    while (fabs(numerator) / denominator > EPSILON)
    {
        res += numerator / denominator;
        numerator *= -x * x;
        denominator *= (count - 1) * count;
        count += 2;
    }
    return res;
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
    if (x == 0)
        return 0;

    // Newton's method
    double oldX = 0, newX = x;
    while (fabs(oldX - newX) > EPSILON)
    {
        oldX = newX;
        newX = (oldX + x / oldX) / 2;
    }
    return newX;
}
