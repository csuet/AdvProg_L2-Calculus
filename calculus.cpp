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
double FCos(double x. int n)
{
    int a;
    if (n%2==0)
    a=1;
    else
    a=-1;
    float temp=1;
    for (int i=1; i<=2*n; i++)
    temp=temp*x/i;
    return a*temp;
}
double myCos(double x)
{
    double result=0;
    int n=0;
    while (abs(FCos(x, n))>0.00001) {
        result += FCos(x, n);
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
double FSin (double x, int n)
{
    int a;
    if (n%2==0)
        a=1;
    else
        a=-1;
    float temp=1;
    for (int i=1; i<=2*n+1; i++)
        temp=temp*x/i;
    return a*temp;
}
double mySin(double x)
{
    double result=0;
    int n=0;
    while (abs(FSin(x, n))>0.00001) {
        result += FSin(x, n);
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
    else
        return sqrt(x);

}