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
double mulFac(int n)
{
    double num = 1;
    for(int i = 0; i < n; i++)
    {
        num*=i;
    }
    return num;
}
/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double a = -1;
    int i = 1;
    double sum = 1,oldsum = 0;
    double factor = 1;
    while(sum - oldsum > 0.00001)
    {
        i+=2;
        oldsum = sum;
        factor = factor*a*x*x/mulFac(i);
        sum+=factor;
    }
    return sum;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    return sqrt(1 - mySin(x)*mySin(x));
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