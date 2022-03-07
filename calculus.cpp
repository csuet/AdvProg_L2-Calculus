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
    double cosin = 0;
    double F = 1.0;
    int i = 1;
    while(fabs(F) >= 1e-6){
        cosin +=F ;
        F *= (-1)*(x*x)/(i*(i+1));
        i = i+ 2;
    }
    return cosin;
    
    
    
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sine = 0;
    double F = x;
    int i = 2;
    while(fabs(F) >= 1e-6){
        sine += F;
        F = (-1)*F*(x*x)/(i*(i+1));
        i += 2;
    }
    return sine;
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
    } else {
        double a_0 = 1;
        double a = 1.0f;
        while(fabs(a*a - x) >= 1e-6){
            a= 1.0/2 * (a_0+ x /a_0);
            a_0 = a;
        }
    return a;
    }

    
    return 0;
}