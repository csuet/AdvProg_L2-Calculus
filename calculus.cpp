#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

double fac(double number)
{
    if (number<=1)
    {
        return 1;
    }
    else return number*fac(number-1);
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
    double cosx = 0;
	for (int i = 0; i < 100; i++)
	{
		cosx += (pow(-1, i) * pow(x, 2 * i) / fac(i * 2));
	}
	return cosx;
   
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sinx = 0;
    for (int i = 0; i < 100; i++){
        sinx += double(pow(-1, i)*pow(x, 2*i+1))/ fac(2*i+1);
    }
    return sinx;
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
    else double result = 1.0f;
    while (fabs(result * result - x) / x >= 0.00000001)
        result = (x / result  - result) / 2 + result;
    return result;
}