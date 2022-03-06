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
int factorial(int x);

const double e = 0.0001;

int factorial(int x){
    if (x == 0 || x == 1) return 1;
    else return x*factorial(x-1);
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double E = 1, cosx = 0;
    int n = 0;
    while(E > e){
        E = pow(x, 2*n) / factorial(2*n);
        if(n % 2 == 0){
            cosx += E;
        }else{
            cosx -= E;
        }
        n++;
    }
    return cosx;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sinx = 0, E = 1;
    int n = 0;
    while(E > e){
        E = pow(x, 2*n+1) / factorial(2*n+1);
        if(n % 2 == 0){
            sinx += E;
        }else{
            sinx -= E;
        }
    }
    return sinx;
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
        double result = 1;
        if (x == 0) result = 0;
        else{
        	while(fabs(result*result - x) / x > e){
            result = (x/result - result)/2 + result;
            }
		}
        return result;
    }
}