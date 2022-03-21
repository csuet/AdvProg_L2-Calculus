#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using std::string;
using std::cout;
using std::endl;
using std::stod;
using namespace std;

const int n=10;
long long GT(int N)
{
    long long s=1;
    for (int i=1;i<=N;i++)
    {
        s=s*i;
    }
    return s;
}
double POW(double A, int N)
{
    double s=1;
    if (N == 0) return 1;
    for (int i=1;i<=N;i++)
    {
        s=s*A;
    }
    return s;
}
double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    double s = 0;
    for (int i=0; i<=10; i++)
    {
        s += (double) POW(-1,i)*POW(x,2*i)/GT(2*i);
    }

    return s;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/

double mySin(double x)
{
    double s = 0;
    for (int i=0; i<=10; i++)
    {
        s += (double) POW(-1,i)*POW(x,2*i+1)/GT(2*i+1);
    }

    return s;
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


    return sqrt(x);
}

