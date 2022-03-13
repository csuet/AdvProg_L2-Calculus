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
double factorial(double x){
    if (x==0||x==1) return 1;
    return x*factorial(x-1);
}
double myCos(double x){
    double sum=1; double oldsum=0;
    int i=0;
    while(fabs(sum-oldsum)>0.00001){
        oldsum=sum; i++;
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
     double sum=x; double oldsum=0;
    int i=0;
    while(fabs(sum-oldsum)>0.00001){
        oldsum=sum; i++;
        sum+=(pow(-1,i)(pow(x,2i+1))/factorial(2*i+1));
    }
    return sum;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
#define EPSILON 0.0001f
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double result = 1.0f;
    while (fabs(result * result - x) / x >= EPSILON)
        result = (x / result  - result) / 2 + result;
    return result;
}