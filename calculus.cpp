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
    double cosine = 1;
    double temp = 1;
    int i = 0;
    do {
        i += 2;
        temp = temp * x * x / (i * (i - 1));
        temp *= -1;
        cosine += temp;
    } while (abs(temp) >= 0.001);

    return cosine;

}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sin = x;
    double temp = x;
    int i = 1;
    do {
        i += 2;
        temp = temp * x * x / (i * (i - 1));
        temp *= -1;
        sin += temp;
    } while (abs(temp) >= 0.001);
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
    double kq = x / 2;
    double temp = (kq * kq - x) / (2 * kq);
    do {
        kq = kq - temp;
        temp = (kq * kq - x) / (2 * kq);
    } while (abs(temp) >= 0.001);
    return kq;
}