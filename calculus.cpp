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
int n;
double myCos(double x) 
{
    int gt=1;
    float cos=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            gt=gt*i*pow(-1,j);
        }
        cos+=pow(x,2*i)/gt;
    }

    return cos;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    int gt=1;
    float sin=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            gt=gt*i*pow(-1,j);
        }
        sin+=pow(x,2*i+1)/gt;
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

    return sqrt(x);
}