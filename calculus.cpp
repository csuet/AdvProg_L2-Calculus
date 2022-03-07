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


//Function to calculate the abstract value of the n-element from the Maclaurin expansion of cosine
double absCosMaclaurin(double x, int n){ 
    if (n==0){
        cosineElement[0] = 1;
        return 1;
    }
    else {
        if (cosineElement[n]){
            return cosineElement[n];
        } 
        else {
            cosineElement[n] = absCosMaclaurin(x,n-1)*x*x/(2*n*(2*n-1));
            return cosineElement[n];
        }
    }
}

//Function to calculate the sign of n-element from the Maclaurin expansion of cosine 
double cosineSign(int n){
    double sign;
    if (n%2==0){
        sign = 1;
    }
    else {
        sign = -1;
    }
    return sign;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double cos = 0;
    for (int i=0; i<1000; i++){
        if (absCosMaclaurin(x,i)>1.7e-308){
            double cosSign = cosineSign(i); 
            cos += cosSign*absCosMaclaurin(x,i);
        }
        else {
            break;
        }
    }
    return cos;
}

//Function to calculate the abstract value of the n-element from the Maclaurin expansion of cosine
double absSineMaclaurin(double x, int n){
    if (n==0){
        sineElement[0] = x;
        return 1;
    }
    else {
        if (sineElement[n]){
            return sineElement[n];
        } 
        else {
            sineElement[n] = absCosMaclaurin(x,n-1)*x*x*x/(2*n*(2*n-1)*(2*n+1));
            return sineElement[n];
        }
    }
} 


/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/

double mySin(double x){
    double sin = 0;
    for (int i=0; i<1000; i++){
        if (absCosMaclaurin(x,i)>1.7e-308){
            double sign = cosineSign(i);
            sin += sign*absCosMaclaurin(x,i)*x/(2*i+1);
        }
        else {
            break;
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
    return x;
    
    return 0;
}

