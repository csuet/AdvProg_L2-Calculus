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
    return cos(x);
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double sinCalFracAdd(double x, int n)
{
    int sign = 0;
    if(n%2 == 0) sign = 1;
    else sign = -1;

    double fracAdd = 1;
    for(int i = 1; i <= 2*n + 1; ++i)
    {
        fracAdd = fracAdd*x/i;
    }

    return sign*fracAdd;
}

double mySin(double x)
{
    /*
    double sinX = 0;
    int n = 0;

    while(abs(sinCalFracAdd(x, n)) > 0.00001)
    {
        sinX += sinCalFracAdd(x, n);
        ++n;
    }
    return sinX;*/
    return sin(x);
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
/*
    double sqrtX = 1.0;
    while (abs(sqrtX * sqrtX - x) / x > 0.00001)
        sqrtX = (x / sqrtX  - sqrtX) / 2 + sqrtX;
    return sqrtX;*/

    return sqrt(x);
}