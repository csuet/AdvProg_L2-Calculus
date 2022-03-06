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
double tichCos(double x);
double tichSin(double x);

double tichCos(double x, int n) {
    int dau;
    if(n%2==0) {
        dau=1;
    }
    else {
        dau=-1;
    }
    double tmp=1;
    for(int i=1;i<=2*n;i++) {
        tmp=tmp*x/i;
    }
    return dau*tmp;
}

double tichSin(double x, int n) {
    int dau;
    if(n%2==0) {
        dau=1;
    }
    else {
        dau=-1;
    }
    double tmp=1;
    for(int i=1;i<=2*n+1;i++) {
        tmp=tmp*x/i; 
    }
    return dau*tmp;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double cos=0;
    int n=0;
    while(fabs(tichCos(x, n))>0.00000001) {
        cos+=tichCos(x, n);
        n++;
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
    int n=0;
    double sin=0;
    while(fabs(tichSin(x, n))>0.00000001) {
        sin+=tichSin(x, n);
        n++;
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
    double sqrt=1;
    while(fabs(sqrt*sqrt-x)/x>=0.0001) {
        sqrt=(x/sqrt-sqrt)/2+sqrt;
    }
    return sqrt;
}