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


const double PI = 3.14159265358979323846;
const double TWO_PI = 2 * PI;
const double HALF_PI = PI / 2;

/// return such a number a that x = a + 2 * k * PI and 0 <= a < 2 * PI
/// it makes calculation of sin(x) and cos(x) faster and more accurate
double bringTo2Pi(double x)
{

    bool is_negative = false;
    if (x < 0) {
        is_negative = true;
        x = -x;
    }

    double result;
    if (x < TWO_PI) result = x;
    else {
        ///find a maximum exp such that 2PI * 2^exp <= x
        int exp;
        std::frexp(x / TWO_PI, &exp);
        --exp;
        double multiple_of_pi = std::ldexp(TWO_PI, exp);
        for (int i = 0; i <= exp; ++i) {
            if (multiple_of_pi <= x) x -= multiple_of_pi;
            multiple_of_pi /= 2;
        }
        result = x;
    }

    if (is_negative) result = TWO_PI - result;
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    x = bringTo2Pi(x);
    if (x > PI) x = TWO_PI - x;
    bool negated = false;
    if (x > HALF_PI) {
        x = PI - x;
        negated = true;
    }
    ///now x is in [0, PI/2]
    static const int ITERATIONS = 10;
    double x_squared = x * x;
    double result = 1;
    double term = 1;
    int order = 0;

    for (int i = 0; i < ITERATIONS; ++i) {
        term *= -x_squared;
        order += 2;
        term /= (order - 1) * (order);
        result += term;
    }
    if (negated) result = -result;
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    /// myCos may not return exactly 0 for x = -Pi / 2
    if (x == 0) return 0;
    return myCos(x - PI / 2);
}


double newtonsMethodSqrtIteration(double current, double x)
{
    ///sqrt(x) = u -> u * u - x = 0
    ///let f(u) = u * u - x
    ///then f'(u) = 2 * u
    return current - (current * current - x) / (2 * current);
}
/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) 
{
    /// I'd prefer throwing to exit the program, but anyway
    if (x < 0) {
        std::cout << "Invalid argument" << std::endl;
        exit(1);
    }
    if (x == 0) return 0;
    static const int ITERATIONS = 20;
    double result = x;
    for (int i = 0; i < ITERATIONS; ++i) 
        result = newtonsMethodSqrtIteration(result, x);
    return result;
}