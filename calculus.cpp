#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

const double pi = 3.14159265359;

double mySin(double x);
double myCos(double x);
double mySqrt(double x);

double F(double x, int n) {
    int a;
    if (n % 2 == 0)
        a = 1;
    else
        a = -1;
    double temp = 1;
    for (int i = 1; i <= 2*n+1; i++)
        temp = temp * x / i;
    return a * temp;
}

double f(double x, int n) {
    int a;
    if (n % 2 == 0)
        a = 1;
    else
        a = -1;
    double temp = 1;
    for (int i = 1; i <= 2*n; i++)
        temp = temp * x / i;
    return a * temp;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    while (x > 2*pi) {
        x -= 2*pi;
    }
    while (x < -2*pi) {
        x += 2*pi;
    }
    double cos = 0;
    int n = 0;
    while (abs(f(x, n)) > 0.0000001) {
        cos += f(x, n);
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
    while (x > 2*pi) {
        x -= 2*pi;
    }
    while (x < -2*pi) {
        x += 2*pi;
    }
    double sin = 0;
    int n = 0;
    while (abs(F(x, n)) > 0.0000001) {
        sin += F(x, n);
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
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    const double EPSILON = 0.0000001;
    double result = 1.0;
    while (abs(result * result - x) / x >= EPSILON)
        result = (x / result  - result) / 2 + result;
    return result;
}