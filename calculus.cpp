#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::stod;
using std::string;

double mySin(double x);
double myCos(double x);
double mySqrt(double x);
double factorial(int n);
double dealClassSinx(double x, int n);
double dealClassCosx(double x, int n);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return (n)*factorial(n - 1);
}
double dealClassSinx(double x, int n)
{
    double temp;
    temp = (pow(x, 2 * n + 1)) / factorial(2 * n + 1);
    if (n % 2 == 0)
        return temp;
    return -1 * temp;
}
double dealClassCosx(double x, int n)
{
    double temp;
    temp = (pow(x, 2 * n)) / factorial(2 * n);
    if (n % 2 == 0)
        return temp;
    return -1 * temp;
}

double myCos(double x)
{
    // x = x * M_PI / 180;
    int n = 0;
    double cosx = 0;
    while (fabs(dealClassCosx(x, n)) > 0.00001)
    {
        cosx += dealClassCosx(x, n);
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
    // x = x * M_PI / 180;
    int n = 0;
    double sinx = 0;
    while (fabs(dealClassSinx(x, n)) > 0.00001)
    {
        sinx += dealClassSinx(x, n);
        n++;
    }
    return sinx;
}

/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x)
{
    double ans = 1.0;
    if (x < 0)
    {
        cout << "Invalid argument" << endl;
    }
    else
    {
        while (fabs(ans * ans - x) / x >= 0.000001)
        {
            ans = (x / ans - ans) / 2 + ans;
        }
    }
    return ans;
}
// int main()
// {
//     double x;
//     cin >> x;

//     mySin(x);
//     myCos(x);
//     mySqrt(x);
// }