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
    //cos(x) = sin(x + pi/2)
    const double PI = 3.14159265358979323846;
    return mySin(x + PI/2);
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    //sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
    double result = x;
    double term = x;
    int n = 1;
    while (abs(term) > 0.000001)
    {
        term *= -1 * x * x * x / (2 * n * (2 * n + 1) * (2 * n + 2));
        result += term;
        n += 2;
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
    // sqrt(x) = x / 2 * (x / 2 + 1)
    double result = x / 2;
    double term = x / 2;
    int n = 0;
    while (abs(term) > 0.000001)
    {
        term = result;
        result = (result + x / result) / 2;
        n++;
    }
    return result;
}