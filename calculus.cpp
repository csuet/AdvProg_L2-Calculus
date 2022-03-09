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
    const double limit = 0.00000000000000000001;
    double cosx = 1.0, preCosx = 0.0, exp_x = 1.0, factorial = 1.0;
    int i = 1;
    while(x > M_PI) x -= 2 * M_PI;

    while(x < -M_PI) x += 2 * M_PI;

    
    do{
        preCosx = cosx;
        factorial = factorial * (2*i-1) * (2*i);
        exp_x *= (x*x);
        cosx += (pow(-1,i)/ factorial)*exp_x;
        i++;
    }
    while(fabs(cosx - preCosx) >= limit);

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
    return mySqrt(1-myCos(x)*myCos(x));
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
    
    //baybylon algorithm
    double preS,S = 5.0;
    do{
        preS = S;
        S = (preS + x/preS)/2;
    }while(fabs(S-preS) >= 0.000001);
    
    return S;
}