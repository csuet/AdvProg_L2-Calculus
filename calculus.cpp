#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::pow;

using std::string;

const double EPSILON = 0.00001;

double mySin(double x);
double myCos(double x);
double mySqrt(double x);
double gt(int n);
double myAbs(double x);

double gt(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * gt(n - 1);
}

double myAbs(double x)
{
    if (x < 0)
        return -x;
    return x;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    double epsilon = EPSILON;
    double cos = 1;
    double prev_cos = 0;
    int index = 2;
    bool sign = false;

    while (myAbs(cos - prev_cos) >= epsilon)
    {
        prev_cos = cos;
        cos = (sign) ? cos + pow(x, index) / gt(index)
                     : cos - pow(x, index) / gt(index);

        index += 2;
        sign = !sign;
    }
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
    double epsilon = EPSILON;
    double sin = x;
    double prev_sin = 0;
    int index = 3;
    bool sign = false;

    while (myAbs(sin - prev_sin) >= epsilon)
    {
        prev_sin = sin;
        sin = (sign) ? sin + pow(x, index) / gt(index)
                     : sin - pow(x, index) / gt(index);

        index += 2;
        sign = !sign;
    }
    return sin;
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

    double initialGuess = 1.0;
    double epsilon = EPSILON;
    double guess = initialGuess;
    double prev_guess = 0.0;

    while (myAbs(guess - prev_guess) >= epsilon)
    {
        prev_guess = guess;
        guess = guess - (guess * guess - x) / (2 * guess);
    }

    return guess;
}