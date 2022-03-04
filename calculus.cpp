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
{   double result = 1- (x*x)/2 + (x*x*x*x)/24 - (x*x*x*x*x*x)/720;
   // result = (roundf(result*10))/10;
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
    double result = x-(x*x*x)/6 +(x*x*x*x*x) / 120- (x*x*x*x*x*x*x)/5040;
   // result = (roundf(result*10))/10;
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
    double result = 10;
    for (int i = 1;i <= 10; i++)
       result = 1/2 *(result + x/result);
 //  result = roundf(result * 10)/10;
    return result;
}
