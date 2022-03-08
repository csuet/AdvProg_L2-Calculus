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
    if (x < 0) x = -x;
    x = M_PI*x/180;
    double cosx = 1;
    double eps = 1e-9;
    double n = 1, t = 1;
    do {
      t=-t*x*x/n/(n+1);
      cosx=cosx+t;
      n=n+2;
    }
    while (abs(t) > eps);
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
    return myCos(M_PI/2 - x);
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
     if (x == 0) return 0;
     double result = 1.0;
     double eps = 1e-9;
     while (abs(result * result - number) / number >= eps)
         result += (number / result  - result) / 2;
     return result;

}
