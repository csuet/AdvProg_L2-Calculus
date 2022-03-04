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

double factorial( double number ) {
    if ( number == 1 || number == 0 ) return 1;
    else return number * factorial(number - 1);
}

double myCos(double x) 
{
    double cosin = 0;
	for (int i = 0; i < 100; i++)
	{
		cosin += (pow(-1, i) * pow(x, 2 * i) / factorial(i * 2));
	}
	return cosin;
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
	for (int i = 0; i < 100; i++)
	{
		sin += (pow(-1, i) * pow(x, 2 * i + 1) / factorial(i * 2 + 1));
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
    double xx = x;
    double root = x;
	for (int i = 0; i < 100; i++)
	{
		root = 1.0 / 2 * (xx + x / xx);
		xx = root;
	}
	return root;    
}