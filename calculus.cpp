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
    x = fabs(x);
    double addition = 1;
    double res = 0;
    double br = 0.000000001;
    for (int i = 0; fabs(addition) >= br;i+=2) {
        res += addition;
        addition *= -(x*x/(i+1)/(i+2));
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
    return myCos(M_PI/2-x);
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
    if(x == 0) return 0;
    if(x == 1) return 1;
    double preNum = x;
    double afterNum = x;
	for (int i = 0; i < 100; i++)
	{
		afterNum = 1.0 / 2 * (preNum + x / preNum);
		preNum = afterNum;
	}
    return afterNum;
}

int Sum(int a, int b) {
	return a + b;
}
