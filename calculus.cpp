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
double giaithua(int n)
{
    double k=1;
    for (int i=2;i<=n;i++){
        k*=i;
    }
    return k;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    double result=0;
    for (int j=0;j<7;j++){
        result+=j%2? -pow(x,2*j)/giaithua(2*j) : pow(x,2*j)/giaithua(2*j);
    }
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
    double result=0;
    for (int j=0;j<=7;j++){
        result+=j%2? -(double)pow(x,2*j+1)/giaithua(2*j+1) : (double)pow(x,2*j+1)/giaithua(2*j+1);
    }
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

    double result=x;
    for (int i=0;i<10;i++){
        result=(result+x/result)/2;
    }
    return result;
}
