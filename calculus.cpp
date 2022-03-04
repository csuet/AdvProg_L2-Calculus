#include <iostream>
#include <string>
#include <cmath>
#define EPSILON 0.0001
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

    return (double) sqrt(1.0-sin(x*180/3.14)*sin(x*180/3.14));
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    return sin(x*180/3.14);
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
    else{
        double result = 1.0;
        while (fabs(result * result - x) / x >= EPSILON)
            result = (x / result  - result) / 2 + result;
            return result;
    }
}