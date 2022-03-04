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
    double Sum=1,oldSum=0;
    double n=1;
    while(abs(Sum-oldSum)>0.00001){
        oldSum=Sum;
        double factorial=1;
        for(int i=1;i<=2*n;i++){
            factorial*=i;
        }

        Sum = Sum + pow(-1,n)*pow(x,2*n)/factorial;
        n++;
    }

    return Sum;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double Sum=x,oldSum=x-1;
    int n=1;
    while(abs(Sum-oldSum)>0.001){
        oldSum=Sum;
        double factorial=1;
        for(int i=1;i<=2*n+1;i++){
            factorial*=i;
        }
        Sum+=pow(-1,n)*pow(x,2*n+1)/factorial;
        n++;
    }
    return Sum;
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
    double Sum=35.6,oldSum=10;
    while(abs(Sum-oldSum)>0.001){
        oldSum=Sum;
        Sum=oldSum-(oldSum*oldSum-x)/(2*oldSum);

    }
    return Sum;
}
