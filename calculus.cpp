#include <iostream>
#include <string>
#include <cmath>
#include<math.h>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);
long fact(int n)
{
    if(n==1|| n==0) return 1;
    else return n*fact(n-1);
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double result=0;
    int n=0;
    while((double)abs((double)(pow(-1,n)*pow(x,2*n))/fact(2*n)) >= 0.00001)
    {
        result += (double)(pow(-1,n)*pow(x,2*n))/fact(2*n);
        n++;
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double result=0;
    int n=0;
    while((double)abs((double)(pow(-1,n)*pow(x,2*n+1))/fact(2*n+1)) >= 0.00001)
    {
        result += (double)(pow(-1,n)*pow(x,2*n+1))/fact(2*n+1);
        n++;
    }
    return result;
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