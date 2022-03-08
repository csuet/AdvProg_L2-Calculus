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

//Function to return the angle in the range from -2*PI -> 2*PI
double smallAngle(double x){
    if (x>2*M_PI){
        x = x-2*M_PI;
    }
    if (x<-2*M_PI){
        x = x+2*M_PI;
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
    for (int i=0; i<1000; i++){
        if (abs(CosMaclaurin(x,i))>0.0000001){
            cos += CosMaclaurin(x,i);
        }
        else {
            continue;
        }
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
    for (int i=0; i<1000; i++){
        if (abs(SinMaclaurin(x,i))>0.0000001){
            sin += SinMaclaurin(x,i);
        }
        else {
            continue;
        }
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

