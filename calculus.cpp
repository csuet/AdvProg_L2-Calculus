#include <iostream>
#include <string>
#include <cmath>
#define EPSILON 0.0001
using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

double gt(int n){
    if(n==0) return 1;
    else return (double) n*gt(n);
}

double lt(double a, int b){
    if(b==0) return 1;
    else return (double) a*lt(a, b-1);
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{

    return (double) sqrt(1.0-mySin(x)*mySin(x));
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{   

    double result = 0, old = 0;
    int i=0;
    do{
        old = result;
        result = lt(x, 2*i+1)*lt(-1, i)/gt(2*i+1) + result;
        i++;
    }
    while(result - old > EPSILON);
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
    else{
        double result = 1.0;
        while (fabs(result * result - x) / x >= EPSILON)
            result = (x / result  - result) / 2 + result;
        return result;
    }
}