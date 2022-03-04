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
   //return 0.0;
    double cosX = 1, f = 1; int i = 1;
    do {
        f = f * x / i;
        if (i % 4 == 2) {
            cosX -= f;
        }if (i % 4 == 0) {
            cosX += f;
        }
        i++;
    } while (f >= 0.000001);
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
   // return 0.0;
    double sinX = 0, f = 1; int i = 1;
    do {
        f = f * x / i;
        if (i % 4 == 1) {
            sinX += f;
        }
        if (i % 4 == 3) {
            sinX -= f;
        }
        i++;
    } while (f >= 0.000001);
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

    double oldX = 1, newX = 0, dis = 0;
    do {
        newX = oldX - (oldX * oldX - x) / (2 * oldX);
        dis = abs(oldX - newX);
        oldX = newX;
    } while (dis >= 0.000001);
    return newX;
    //return 0;
}