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
    //calculate cos with Taylor series
    while (x >= 2 * M_PI) {
        x -= 2 * M_PI;
    }
    double cos = 1;
    double numerator = 1;
    double n = 1;
    double factorial = 1;
    double temp;
    do {
        numerator *= -1;
        factorial *= 2 * n;
        n++;
        temp = (numerator / factorial) * x * x;
        cos += temp;
    } while (temp > 0.000001);
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
    //calculate sin with Taylor series
    while (x >= 2 * M_PI) {
        x -= 2 * M_PI;
    }
    double sin = 1;
    double numerator = 1;
    double n = 1;
    double factorial = 1;
    double temp;
    do {
        numerator *= -1;
        factorial *= 2 * n + 1;
        n++;
        temp = (numerator / factorial) * x * x;
        sin += temp * x;
    } while (temp > 0.000001);
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

    
    return sqrt(x);
}