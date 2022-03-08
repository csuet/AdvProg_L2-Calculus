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

double cosineElement[1000]; // Array contains elements from Maclaurin formula for cosine //
double sineElement[1000]; // Array contains elements from Maclaurin formula for sine //

//Function to return the angle in the range from -PI to PI
double smallAngle(double x){
    while (x>M_PI){
        x = x-M_PI;
    }
    while (x<-M_PI){
        x = x+M_PI;
    }
    return x;
}

//Function to calculate the n-element from the Maclaurin expansion of cosine
double CosMaclaurin(double x, int n){ 
    if (n==0){
        cosineElement[0] = 1;
        return 1.00;
    }
    else {
        if (cosineElement[n]){
            return cosineElement[n];
        } 
        else {
            cosineElement[n] = -CosMaclaurin(x,n-1)*x*x/(2*n*(2*n-1));
            return cosineElement[n];
        }
    }
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x){
    x = smallAngle(x);
    double cos = 0;
    int i=0;
    while (abs(CosMaclaurin(x,i)) > 0.0000001){
        cos += CosMaclaurin(x,i);
        i = i+1;
    }
    return cos;
}

//Function to calculate the n-element from the Maclaurin expansion of cosine
double SinMaclaurin(double x, int n){ 
    if (n==0){
        sineElement[0] = x;
        return x;
    }
    else {
        sineElement[n] = x*CosMaclaurin(x,n)/(2*n+1);
        return sineElement[n];
    }
}


/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/

double mySin(double x){
    x = smallAngle(x);
    double sin = 0;
    int i=0;
    while (abs(CosMaclaurin(x,i)) > 0.0000001){
        sin += SinMaclaurin(x,i);
        i = i+1;
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

    double m = x;
    double n = 1;
 
    while (m > n) {
        m = (m + n) / 2;
        n = x / m;
    }
    return m;
}

