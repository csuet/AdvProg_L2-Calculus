#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using std::string;
using std::cout;
using std::endl;
using std::stod;
using std::cin;

double mySin(double x);
double myCos(double x);
double mySqrt(double x);
double factorial(double x);

int main()
{
    double x;
    cin >> x;
    cout << mySqrt(x) << endl;
}
double factorial(double x)
{
    double factorial = 1;
    for(int i = 1; i <= x; i ++)
    {
        factorial *= i;
    }
    return factorial;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double newX = x;
    while(newX > 2 * M_PI)
    {
        newX -= 2 * M_PI;
    }
    double n = 1;
    double myCos = 1; 
    long double tmp = 1;
    while(tmp < -0.0001 || tmp > 0.0001)
    {
        tmp = pow(-1, n) * (pow(newX, 2 * n) / factorial(2 * n));
        myCos += tmp;
        n ++;
    }
    return myCos;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double newX = x;
    while(newX > 2 * M_PI)
    {
        newX -= 2 * M_PI;
    }
    double n = 1;
    double mySin = newX; 
    long double tmp = 1;
     while(tmp < -0.0001 || tmp > 0.0001)
    {
        tmp = pow(-1, n) * (pow(newX, (2 * n + 1)) / factorial(2 * n + 1));
        mySin += tmp;
        n ++;
    }
    return mySin;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) 
    {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else 
    {
        double mySqrt = 1;
        double myOldSqrt = 0; 
        while(abs(mySqrt - myOldSqrt) > 0.0001)
        {
            myOldSqrt = mySqrt;
            mySqrt = mySqrt - ((pow(mySqrt, 2) - x) / (2 * mySqrt));
        }
        return mySqrt; 
    }
    
}