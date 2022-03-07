#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using std::string;
using std::cout;
using std::endl;
using std::stod;

double mySin(double x);
double myCos(double x);
double mySqrt(double x);

const double PI = 3.14159265359;

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double esp = 0.00001;

double myCos(double x) 
{
    double res = 1;
    double sign = 1, fact = 1, POW = 1;
    for(int i = 1; i <= 5; i++) {
        sign = sign * -1;
        fact = fact * (2 * i - 1) * (2 * i);
        POW = POW * x * x;
        res = res + sign * POW / fact;
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
    double tmp = x, res = x, fact;
    for(int i = 1; i <= 5; i++) {
        fact = 2 * i * (2 * i + 1);
        tmp = -tmp * x * x / fact;
        res = res + tmp;
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
    double previousNumber = x;
    double afterNumber = x;
	for (int i = 0; i < 100; i++)
	{

		afterNumber = 1.0 / 2 * (previousNumber + x / previousNumber);
		previousNumber = afterNumber;
	}
	return afterNumber;    
} 
