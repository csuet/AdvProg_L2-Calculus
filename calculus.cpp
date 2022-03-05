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
    x -= 2*M_PI*((int)(x/(2*M_PI)));
    double res = 1;
    double first = 1;
    int i = 1;
    while (i != 100) {
        first *= (x/i);
        if (i % 2 == 1) {
            i++;
            continue;
        }
        if (i % 4 == 0) res += first;
        else res -= first;
        i++;
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
    x -= 2*M_PI*((int)(x/(2*M_PI)));
    double res = 0;
    double first = 1;
    int i = 1;
    while (i != 100) {
        first *= (x/i);
        if (i % 2 == 0) {
            i++;
            continue;
        }
        if (i % 4 == 1) res += first;
        else res -= first;
        i++;
    }
    return res;
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
    double res = x/2;
    int i = 1;
    while (i != 20) {
        res = (res + x/res)/2;
        i++;
    }
    return res;
}