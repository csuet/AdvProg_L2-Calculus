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

const double e = 0.00001;

double factorial(double x){
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
    double cosx = 0;
    for (int i = 0; i < 100; i++){
        cosx += double(pow(-1, i)*pow(x, 2*i)) / factorial(2*i);
    }
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sinx = 0;
    for (int i = 0; i < 100; i++){
        sinx += double(pow(-1, i)*pow(x, 2*i+1))/ factorial(2*i+1);
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
        	while(fabs(result*result - x) > e){
            result = (x/result - result)/2 + result;
        	}
		}
		return result;
    }
}