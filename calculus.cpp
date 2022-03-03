#include <iostream>
#include <string>
#include <cmath>
#include <math.h>

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
    double sum=1.000000;
    double oldsum=0.000000;
    double i=0;
    double lt=1;
    double mu=1;
    double positive=1;
    while (abs(sum-oldsum)>1e-9)
    {
        i=i+2;
        mu=mu*x*x;
        lt= lt*(i)*(i-1);
        positive =-positive;
        oldsum=sum;
        sum+=mu/lt*positive;

    }
    return sum;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sum=x;
    double oldsum=-0.1000000;
    double i=1;
    double lt=1;
    double mu=x;
    double positive=1;
    while (abs(sum-oldsum)>1e-9)
    {
        i=i+2;
        mu=mu*x*x;
        lt= lt*(i)*(i-1);
        positive =-positive;
        oldsum=sum;
        sum+=mu/lt*positive;

    }
    return sum;
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

    double xn,xn_1;
    xn=0;
    xn_1=sqrt(x);
    while (abs(xn-xn_1)>1e-9)
    {
        xn=xn_1;
        xn_1=0.500*(xn+x/xn);
    }


    return xn_1;
}

