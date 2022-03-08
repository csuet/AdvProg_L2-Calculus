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

double myCos(double x){
    double result=1;
    double temp=1;
    int i = 0;
    while (temp>0.00001||temp<-0.00001)
    {
        i++;
        temp=(temp*x/(2*i))*(x/(2*i-1));
        if (i%2==0) result=result+temp;
        else result=result-temp;
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x){
    double result=x;
    double temp=x;
    int i = 0;
    while (temp>0.00001||temp<-0.00001)
    {
        i++;
        temp=(temp*x/(2*i+1))*(x/(2*i));
        if (i%2==0) result=result+temp;
        else result=result-temp;
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
#define EPSILON 0.0001
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else
        double result = 1.0;
        while (fabs(result * result - number) / number >= EPSILON) {
            result = (number / result - result) / 2 + result;
        }
        return result;
}