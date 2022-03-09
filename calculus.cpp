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
double mySin(double x)
{
    return sin(x);
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double a) {
    if (a < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double x,t;x=a/2;
    do
    {
        t=x;
        x=x-(x*x-a)/2/x;
    }
    while (t-x>0.0000000000000001);
        
    return x;
}
