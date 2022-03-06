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
    double temp1 = -x * x/2;
    double cosx = 1;
    for (int i = 3; i < 20; i += 2) {
        cosx += temp1;
        temp1 = -temp1 * x * x / i / (i+1);
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
    double temp2 = x;
    double sinx = 0;
    for (int i = 2; i < 20; i += 2) {
        sinx += temp2;
        temp2 = -temp2 * x * x / i / (i+1);
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
    double sqrtx = x;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else {
        for (int i = 0; i < 10; i++) {
            sqrtx = 0.5 * sqrtx + 0.5 * x / sqrtx;
        }
    }

    return sqrtx;
}
