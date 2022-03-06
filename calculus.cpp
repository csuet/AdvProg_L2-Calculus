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
    double temp = -x * x/2;
    double cosx = 1;
    for (int i = 3; i < 10; i += 2) {
        cosx += temp;
        temp = -temp * x * x / i / (i+1);
    }
    return cosx;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double temp = x;
    double sinx = 0;
    for (int i = 2; i < 10; i += 2) {
        sinx += temp;
        temp = -temp * x * x / i / (i+1);
    }
    return sinx;
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
        double temp = x;
        for (int i = 0; i < 5; i++) {
            temp = 0.5 * temp + 0.5 * x / temp;
        }
    }

    return temp;
}
