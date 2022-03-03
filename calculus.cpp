#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::stod;
using std::string;

double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
#define esp 1e-5
double myCos(double x)
{
    double tmp = 1;
    int cnt = 1;
    bool sign = 0;
    double ans = 1, preAns = 0;
    while (std::abs(ans - preAns) > esp)
    {
        tmp *= x * x;
        tmp /= 1.0 * (cnt * (cnt + 1));
        cnt += 2;
        preAns = ans;
        ans += ((sign == 0) ? -tmp : tmp);
        sign ^= 1;
    }
    return ans;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double tmp = x;
    int cnt = 2;
    bool sign = 0;
    double ans = x, preAns = 0;
    while (std::abs(ans - preAns) > esp)
    {
        tmp *= x * x;
        tmp /= 1.0 * (cnt * (cnt + 1));
        cnt += 2;
        preAns = ans;
        ans += ((sign == 0) ? -tmp : tmp);
        sign ^= 1;
    }
    return ans;
}

/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x)
{
    if (x < 0)
    {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    if(x == 0)
        return 0;
    double b = x / 10;
    double ans = b, preAns = 0;
    while(std::abs(ans - preAns) > esp)
    {
        preAns = ans;
        ans = 0.5 * (ans + x / ans);
    }
    return ans;
}