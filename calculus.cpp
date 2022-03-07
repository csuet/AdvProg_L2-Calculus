#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

unsigned long long factorial(int num) {
    unsigned long long res = 1;
    for (int i = 1; i <= num; i++) {
        res *= i;
    }
    return res;
}

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
    double res = 1;
    for (int i = 1; i <= 15; i++) {
        res += pow(-1, i)*pow(x, 2*i)/factorial(2*i);
    }
    return res;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double res = 0;
    for (int i = 0; i < 20; i++) {
        res += pow(-1, i)*pow(x, 2*i + 1)/factorial(2*i + 1);
    }
    return res;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double res = 1;                          // initial guess
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    } else {
        double epsilon = 1e-4;
        for (int i = 0; i < 10; i++) {
            res = (res + x/res)/2;
        }
    }
    return res;
}
