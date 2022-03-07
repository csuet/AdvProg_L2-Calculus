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
double mySin(double x) {
    double cur = 1;
    double res = 0;
    for (int i = 1; cur >= 1e-6; ++i) {
        cur *= x / i;
        if (i % 4 == 1) {
            res += cur;
        } else if (i % 4 == 3) {
            res -= cur;
        }
    }

    return res;
}

double myCos(double x) {
    double cur = 1;
    double res = 1;
    for (int i = 1; cur >= 1e-6; ++i) {
        cur *= x / i;
        if (i % 4 == 2) {
            res -= cur;
        } else if (i % 4 == 0) {
            res += cur;
        }
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
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

        double l = 0, r = x;

    while (r - l > 1e-6) {
        double m = (l + r) / 2;
        if (m * m > x) {
            r = m;
        } else {
            l = m;
        }
    }

    return l;
}
