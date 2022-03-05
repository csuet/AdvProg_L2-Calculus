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

long long factorial(int n) {
    if (n < 2) return 1;
    return n * factorial(n - 1);
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double cos = 0;
    for (int i = 0; i < 100; i++) {
        cos += pow(-1, i) * pow (x, i * 2) / factorial(i * 2);
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
    double sin = 0;
    for (int i = 0; i < 100; i++) {
        sin += pow(-1, i) * pow (x, i * 2 + 1) / factorial(i * 2 + 1);
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
    else if (x > 0) return pow(x, 0.5);
    
    return 0;
}