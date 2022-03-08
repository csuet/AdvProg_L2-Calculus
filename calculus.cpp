#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

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

double fac(double n){
    if (n==0)
        return 1;
    return n*fac(n-1);
}

double myCos(double x) 
{
    double cos = 0;
    for (double i=0; i<6; i++){
        double a = pow(x, 2*i);
        double b = pow(-1, i);
        double c = fac(2*i);
        cos += a*b/c;
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
    double sin = 0;
    for (double i=0; i<6; i++){
        double a = pow(x, 2*i+1);
        double b = pow(-1, i);
        double c = fac(2*i+1);
        sin += a*b/c;
    }
    return sin;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
const int digitsAfterComma = 4;

double sqrtCalculator(double x, double high, double low, double kbc){
    if (high == 0)
        return 0;
    if (kbc <= pow(10, -(digitsAfterComma+1))){
        return high;
    }
    if (high*high == x){
        return high;
    }
    if (low*low == x){
        return low;
    }
    if (high*high >= x && x >=low*low){
        return sqrtCalculator(x, high, high-kbc/10, kbc/10);
    }
    return sqrtCalculator(x, high-kbc, low-kbc, kbc);
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    std::stringstream ss;
    ss << x;
    string xDigits = ss.str();
    double kbc = pow(10, xDigits.size()-1);
    double high=x, low=x-kbc;
    return sqrtCalculator(x, high, low, kbc);
}