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
    double factorial = 1;
    double term = 1;
    for (int i = 1; i <= 10; i++) {
        factorial *= i;
        term *= -1 * x * x;
        term /= 2 * i + 1;
        cos += term / factorial;
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
    //calculate sin with Taylor series
    while (x >= 2 * M_PI) {
        x -= 2 * M_PI;
    }
    double sin = 0;
    double factorial = 1;
    double term = 1;
    for (int i = 1; i <= 10; i++) {
        factorial *= i;
        term *= -1 * x * x;
        term /= 2 * i + 1;
        sin += term / factorial;
    }
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