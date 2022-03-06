#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using namespace std;


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
    double res = cos(x);
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
    double res = sin(x);
    return res;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double res;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else
    {
        res = (double)sqrt(x);
    }
    return res;
}