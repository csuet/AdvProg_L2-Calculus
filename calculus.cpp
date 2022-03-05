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
double factorial(double n);

double factorial(double n)
{
    if (n == 1) return 1;
    else return n*factorial(n-1);
}
/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    int n;
    double cosx = 0;
    for (int i = 0; i < 100; i++)
    {
        if (i % 2 == 0) n = 1;
        else n = -1;
        cosx += n*pow(x,2*i)/factorial(2*i);
    }
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
    int n, sinx = 0;
    for (int i = 0; i < 100; i++)
    {
        if (i % 2 == 0) n = 1;
        else n = -1;
        sinx += n*pow(x,2*n+1)/factorial(2*n+1);
    }
    return sinx;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) 
{
    if (x < 0) 
    {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else
    {
        double error = 0.0000001;
        double result = 1.0;
        while (abs(result * result - x) / x >= error)
        result = (x / result  - result) / 2 + result;
        return result;
    }
    return 0;
}