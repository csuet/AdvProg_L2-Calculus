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

long long int factorial( long long int number ) {
    if ( number == 1 || number == 0 ) return 1;
    else return number * factorial(number - 1);
}
/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double sum = 0;
	for (long long int i = 0; i < 100; i++)
	{
		sum += (pow(-1, i) * pow(x, 2 * i) / factorial(i * 2));
	}
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
    double sum = 0;
	for (long long int i = 0; i < 100; i++)
	{
		sum += (pow(-1, i) * pow(x, 2 * i + 1) / factorial(i * 2 + 1));
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

    double sqrtOld = x;
    double sqrtNew = x;
	for (int i = 0; i < 100; i++)
	{
		sqrtNew = 1.0 / 2 * (sqrtOld + x / sqrtOld);
		sqrtOld = sqrtNew;
	}
	return sqrtNew;    
}