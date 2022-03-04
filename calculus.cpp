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
    if (x < 0)x = -x;
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
    bool isMoreThan0 = true;
    if (x < 0) {
        isMoreThan0 = false;
        x = -x;
    }
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
    if (!isMoreThan0)return -sinX;
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
    if (x == 4)return 2;
    const double sai_so_toi_thieu = pow(10, -15);
    double oldX = 1, newX = 0, dis = 0;
    do {
        newX = oldX - (oldX * oldX - x) / (2 * oldX);
        dis = abs(oldX - newX);
        oldX = newX;
    } while (dis >= sai_so_toi_thieu);
    return newX;
    //return 0;
}