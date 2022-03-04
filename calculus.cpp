#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;
using std::abs;


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
    double cosin = 1;
    double oldCosin = 2;
    double factorial = 1;
    double count=0;
    do
    {
        count++;
        factorial *= count;
        count++;
        factorial*=count;
        oldCosin = cosin;
        cosin = cosin - double(1)/factorial * pow(x,count) * pow(-1,count/2+1); 
    } while (abs(oldCosin-cosin) >= 0.001);

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
    double sin1 = x;
    double oldSin = 2;
    double factorial = 1;
    double count=1;
    do
    {
        count++;
        factorial *= count;
        count++;
        factorial*=count;

        oldSin=sin1;
        sin1 = sin1 - double(1)/factorial * pow(x,count) * pow(-1,(count-1)/2+1); 
    } while (abs(oldSin- sin1) >= 0.001);
    return sin1;
    
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
    
    double sqrt=10;
    double oldSqrt=0;

    do
    {
        oldSqrt=sqrt;
        sqrt=sqrt - (pow(sqrt,2) - x)  / (2*sqrt); 
    } while (abs(sqrt-oldSqrt)>=0.001);
    
    return sqrt;

}