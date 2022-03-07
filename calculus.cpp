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
double factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

double myCos(double x)
{
    int i = 1;
    double sum = 1;
    do {
        sum += (pow(-1, i) * pow(x, 2 * i) / factorial(i * 2));

        ++i;
    } while (i < 100);
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
    int i = 0;
    double sum = 0;
    while (i < 100) {
        sum += (pow(-1, i) * pow(x, 2 * i + 1) / factorial(i * 2 + 1));

        ++i;
    }
    return sum;
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
    double sum = 1, oldSum = 0;
    for(int i = 0; i < 1000; i++) {
        oldSum = sum;
        sum += (((double) x / sum - sum) / 2);
        ++i;
    }
    return sum;
}