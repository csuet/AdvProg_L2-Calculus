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
    while (x > 2 * M_PI) {
        x -= 2 * M_PI;
    }
    double result = 1, temp = 1;
    int n = 1;
    while (temp > 0.00001) {
        temp = 1;
        for (int j = 1; j <= 2 * n; j++)
            temp = temp * x / j;
        if (n % 2 == 0) result += temp;
        else result -= temp;
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
double mySin(double x)
{
    while (x > 2 * M_PI) {
        x -= 2 * M_PI;
    }
    double result = x, temp = 1;
    int n = 1;
    while (temp > 0.00001) {
        temp = 1;
        for (int j = 1; j <= 2 * n + 1; j++)
            temp = temp * x / j;
        if (n % 2 == 0) result += temp;
        else result -= temp;
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
    else {
        double previousNumber = x;
        double afterNumber = x;
	    for (int i = 0; i < 100; i++) {
		    afterNumber = 1.0 / 2 * (previousNumber + x / previousNumber);
		    previousNumber = afterNumber;
	    }
	    return afterNumber;
    }
}