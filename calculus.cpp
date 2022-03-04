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
    double res = 1;
    double old_res = 0;
    double epsilon = res - old_res;
    
    double numerator = 1;
    double denominator = 1;
    int n = 0;
    
    while(epsilon > 0.000000000001 || epsilon < -0.000000000001)
    {
        n++;
        numerator *= x * x;
        denominator *= (2 * n) * (2 * n - 1);
        
        old_res = res;
        if(n % 2 == 0)
            res += static_cast<double>(numerator) / denominator;
        else
            res -= static_cast<double>(numerator) / denominator;
            
        epsilon = res - old_res;
    }
    return res;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double res = x;
    double old_res = 0;
    double epsilon = res - old_res;
    
    double numerator = x;
    double denominator = 1;
    int n = 0;
    
    while(epsilon > 0.000000000001 || epsilon < -0.000000000001)
    {
        n++;
        numerator *= x * x;
        denominator *= (2 * n) * (2 * n + 1);
        
        old_res = res;
        if(n % 2 == 0)
            res += static_cast<double>(numerator) / denominator;
        else
            res -= static_cast<double>(numerator) / denominator;
            
        epsilon = res - old_res;
    }
    return res;
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
    if(x == 0) return 0;

    double res = 1;
    double epsilon = 1;
    double ans = x;
    while(epsilon > 0.000000000001)
    {
        res = (1.0/2.0) * (ans + (x / ans));
        epsilon = ans - res;
        ans = res;
    }

    return res;
}