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

double giaiThua(int x) {
    int kq =1;
    if (x == 0) {
        return kq;
    }
    for (int i = 1; i <=x;i++) {
        kq *= i;
    }
    return kq;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double i = 0;
    double cos = 0;
    double oldcos = -1;
    do {
        oldcos = cos;
        cos += (pow(-1,i)*pow(x,2*i))/giaiThua(2*i);
    } while (cos - oldcos > 0.001);
    
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
    double i = 0;
    double sin = 0;
    double oldsin = -1;
    do {
        oldsin = sin;
        sin += (pow(-1,i)*pow(x,2*i+1))/giaiThua(2*i+1);
    } while (sin - oldsin > 0.001);
    
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
    if (x == 1) {
        return 1;
    }
    double sqrt = 0;
    double oldsqrt = -1;
    double x0 = 10.5;
    do {
        oldsqrt = sqrt;
        sqrt += x0 - (pow(x0,2)-x)/2*x0;
        x0 = sqrt;
    } while (sqrt - oldsqrt > 0.0001);

    return sqrt;
}