#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

double myCos(double x)
{
    double res = cos(x);
    return res;
}

double mySin(double x)
{
    double res = sin(x);
    return res;
}

double mySqrt(double x)
{
    if (x < 0)
    {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double res = sqrt(x);
    return res;
}
