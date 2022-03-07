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
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double xBackUp = x;
    stringstream ss;
    ss << x;
    string xDigits = ss.str();
    double high=0, low=0;
    for (double i=xDigits.size()-1; i>=-2; i--){
        double sbc = pow(10, i); cout << "sbc" << sbc <<endl;
        high = x, low = x - sbc; cout << "high" << high <<endl; cout << "low" << low <<endl;
        while (low>=0){
            if (high*high == xBackUp)
                return high;
            if (low*low == xBackUp)
                return low;
            if (high*high >= xBackUp && xBackUp >=low*low){
                break;
            }else{
                high -= sbc; low -= sbc; cout << "inwhile: high" << high << endl; cout << "inwhile: low" << low << endl;
            }
        }
    }
    return low;
}