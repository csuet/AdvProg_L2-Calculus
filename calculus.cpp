#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

const double PI_TEST = 3.14159265359;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);
int giaiThua(int n);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
int giaiThua(int n)
{
    int giai_thua = 1;
    for (int i = 1; i <= n; i++)
        giai_thua *= i;
    return giai_thua;
} 

double myCos(double x) 
{
    double xcos = (x*180)/PI_TEST;
    double cosx = 1.0;
    int n = 2, count = 1;
    while (fabs((pow(xcos,n)/giaiThua(n)))>0.001)
    {
        cosx = 1 + (pow(-1,count))*(pow(xcos,n)/giaiThua(n));
        n = n + 2;
        count++;
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
    double xsin = (x*180)/PI_TEST;
    double sinx = x;
    int n = 3, count = 1;
    while (fabs((pow(xsin,n)/giaiThua(n)))>0.001)
    {
        sinx = 1 + (pow(-1,count))*(pow(xsin,n)/giaiThua(n));
        n = n + 2;
        count++;
    }
    return sinx;
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
    else {
        double result = 1.0;
        while (fabs((result*result - x)/(2*result)) > 0.001)
        {
            result = result - (result*result - x)/(2*result);
        }
        return result;
    }
}
