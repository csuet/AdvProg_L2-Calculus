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
    int mau = 2;
    double mul = 1;
    double result = 1;
    double oldResult = 0;
    while(fabs(result - oldResult) > 0.00000000001) {
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
    int mau = 3;
    double mul = 1;
    double result = x;
    double oldResult = 0;
    while(fabs(result - oldResult) > 0.00000000001) {
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
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double result = 1.0;
    while(fabs(result * result - x)/ x >= 0.00000000001)
        result = (x/result - result)/2 + result;
    return result;
}
