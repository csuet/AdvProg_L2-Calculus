#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

#define EPSILON 0.0001f
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
    int mau = 2;
    double mul = 1;
    double result = 1;
    double oldResult = 0;
    while(fabs(result - oldResult) >= 0.0000000001) {
        oldResult = result;
        mul *= -1*(x*x)/(mau*(mau-1));
        result += mul;
        mau += 2;
    }
    return result;
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
    long long mau = 3;
    double mul = x;
    double result = x;
    double oldResult = 0;
    while(fabs(result - oldResult) > 0.000000000001) {
        oldResult = result;
        mul *= -1*(x*x)/(mau*(mau-1));
        cout << mul << endl;
        result += mul;
        cout << result << endl;
        mau += 2;
    }
    return result;
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
    double result = 1.0f;
    while (fabs(result * result - x) / x >= EPSILON)
        result = (x / result - result) / 2 + result;
    return result;
}
