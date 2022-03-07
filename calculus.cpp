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
    if (n==0)
        return 1;
    return n*fac(n-1);
}

double myCos(double x) 
{
    double cos = 0;
    for (double i=0; i<6; i++){
        double a = pow(x, 2*i);
        double b = pow(-1, i);
        double c = fac(2*i);
        cos += a*b/c;
    }
    return cos;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sin = 0;
    for (double i=0; i<6; i++){
        double a = pow(x, 2*i+1);
        double b = pow(-1, i);
        double c = fac(2*i+1);
        sin += a*b/c;
    }
    return sin;
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
    double sqrt = 1;
    for (double i=1; i<=6; i++){
        double a = 1, b = 0, c = 0;
        for (double j=0; j<i; j++){
            double tmp = 1.0/2 - j;
            a*=tmp;
        }
        b = pow(x-1.0, i);
        c = fac(i);
        double tmp2 = a*b/c;
        cout << a << " " << b << " " << c << endl;
        sqrt += tmp2;
    }
    
    return sqrt;
}