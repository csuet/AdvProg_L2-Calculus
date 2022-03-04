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

double factorial(double n){
    if (n == 0) return 1;
    return factorial(n - 1) * n;
}

double myCos(double x) 
{
    double cosin = 0;
    for (int i = 0; i < 100; i++){
        cosin += (pow(x, i * 2) * pow(-1, i)) / factorial(i * 2);
    }
    return cosin;
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
    for (int i = 0; i < 100; i++){
        sin += (pow(x, i * 2 + 1) * pow(-1, i + 1)) / factorial(i * 2 + 1);
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
    else{
        double root;
        double xx = x;
        for (long long  i = 0; i < 100; i++){
            root =  0.5 * (xx + (x / xx));
            xx = root;
        }
    }
    return root;
}