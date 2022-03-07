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
    double cosx = 1.0;
    int n = 2, count = 1;
    while ((pow(x,n)/giaiThua(n))>0.001)
    {
        cosx = 1 + (pow(-1,count))*(pow(x,n)/giaiThua(n));
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
    double sinx = x;
    int n = 3, count = 1;
    while ((pow(x,n)/giaiThua(n))>0.001)
    {
        sinx = 1 + (pow(-1,count))*(pow(x,n)/giaiThua(n));
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
        while (fabs((result*result - x)/(2*result) > 0.001))
        {
            result = result - (result*result - x)/(2*result);
        }
        return result;
    }
}
