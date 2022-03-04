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
    double sum = 1;
    int i = 2;
    double k = x*x*(-1)/i;
    sum += k;
    i++;
    do
    {
        k = k*x/i;
        if (i % 2 == 0) {
            k = k *(-1);
            sum += k;
        }
        i++;
    }
    while (fabs(k) > 0.001);
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
    double sum = x;
    int i = 3;
    double k = x*x*x*(-1)/i;
    k/=2;
    sum += k;
    i++;
    do
    {
        k = k*x/i;
        if (i % 2 != 0) {
            k = k *(-1);
            sum += k;
        }
        i++;
    }
    while (fabs(k) > 0.001);
    return sum;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double sum = 10;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else {
        double k = double(sum * sum - x) / (2 * sum);
        sum -= k;
        do {
            k = double(sum * sum - x) / (2 * sum);
            sum -= k;
        } while (fabs(k) > 0.001);
    }
    return sum;
}