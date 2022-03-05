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
    double rs = 1;
	double denominator = 1;
	for (int i = 1; i < 10;i++){
		denominator *= 2*i*(2*i-1);
		rs = rs + (pow(-1,i)*pow(x,2*i))/denominator;
	}
	
	return rs;

}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double rs = x;
	double denominator = 1;
	for (int i = 1; i < 10;i++){
		denominator *= 2*i*(2*i+1);
		rs = rs + (pow(-1,i)*pow(x,2*i+1))/denominator;
	}
	
	return rs;
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
	
	double result = 10;
	for (int i = 0; i <10; i++){
		result =  result - (result*result-x)/(2*result);
	}
    
    return result;
}
