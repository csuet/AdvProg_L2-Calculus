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
double myCos(double x) 
{
    double cosx = 1;
    int n = 1;
    double temp = 1;
    while (temp > 0.0001 || temp < -0,0001)
    {
        temp = 1;
        for(int i=1; i<=2*n; i++)
        {
            temp*= (x/(1));
        }
    if(n % 2 == 0) cosx += temp;
    else cosx -= temp;
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
    double sinx = 1;
    int n = 1;
    double temp = 1;
    while (temp > 0.0001 || temp < -0,0001)
    {
       temp = 1;
        for(int i=1; i<=2*n+1; i++)
        {
            temp*= (x/(1));
        }
    if(n % 2 == 0) sinx += temp;
    else sinx -= temp;
    n++;
    }
    
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

    
    return 0;
}