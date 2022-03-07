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

double fac(double n){
    if (n==1)
        return 1;
    return n*fac(n-1);
}

double myCos(double x) 
{
    double sin = 0;
    for (double i=0; i<6; i++){
        double a = pow(x, 2*i);
        double b = pow(-1, i);
        double c = fac(2*i);
        sin += a*b/c;
    }
    return sin;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double cos = 0;
    for (double i=0; i<6; i++){
        double a = pow(x, 2*i+1);
        double b = pow(-1, i);
        double c = fac(2*i+1);
        cos += a*b/c;
    }
    return cos;
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

    
    return sqrt(x);
}