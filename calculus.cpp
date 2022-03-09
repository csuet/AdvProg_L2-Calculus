#include <iostream>
#include <string>
#include <cmath>
#define EPSILON 0.0001f

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

double myCos(double x) 
{
    while(x > 2 * M_PI) {
        x -= 2 * M_PI;
    }

    double cos = 0;
    int n = 0;
    double temp = 1;

    while(temp > 0.00001) {
        temp = 1;
        for (int i = 1; i <= 2 * n; i++) {
            temp *= x / i;
        }

        if(n % 2 == 0) {
            cos += temp;
        } else {
            cos -= temp;
        }
        n++;
    }

    return cos;
}

double mySin(double x)
{
    while(x > 2 * M_PI) {
        x -= 2 * M_PI;
    }

    double sin = 0;
    int n = 0;
    double temp = 1;

    while(temp > 0.00001) {
        temp = 1;
        for (int i = 1; i <= 2 * n + 1; i++) {
            temp *= x / i;
        }

        if(n % 2 == 0) {
            sin += temp;
        } else {
            sin -= temp;
        }
        n++;
    }
    
    return sin;
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double result = 1.0f;
    while (abs(result * result - x) / x >= EPSILON)
        result = (x / result  - result) / 2 + result;
    
    return result;
}