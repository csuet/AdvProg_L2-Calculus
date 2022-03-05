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
    const double limit = 0.000000000000000001;
    double cosx = 1.0, preCosx = 0.0,element = 1.0;
    int i = 1;
    while(x<0 || x> 2*M_PI){
        x -= 2*M_PI;
    }

    do{
        preCosx = cosx;
        element *= (-x*x)/((2*i)*(2*i-1));
        cosx += element;
        i++;
    }
    while(fabs(element) >= limit);

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
    return sqrt(1-myCos(x)*myCos(x));
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
    double preS,S = 10.0;
    do{
        preS = S;
        S = (preS + x/preS)/2;
    }while(fabs(S-preS) >= 0.0001);
    
    return S;
}