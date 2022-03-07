#include <iostream>
#include <string>
#include <cmath>
#include <array>

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
    double result = x - std::floor(x / TWO_PI) * TWO_PI;
    if (result < 0) result += TWO_PI;
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
    if (x == 0) return 1;
    x = bringTo2Pi(x);
    if (x > PI) x = TWO_PI - x;
    bool negated = false;
    if (x > HALF_PI) {
        x = PI - x;
        negated = true;
    }
    ///now x is in [0, PI/2]
    static const int ITERATIONS = 9;
    static const std::array<double, ITERATIONS> COEFICIENT_TABLE = [] {
        std::array<double, ITERATIONS> result{};
        for (int i = 0; i < ITERATIONS; ++i)
            result[i] = -1.0 / ((2 * i + 1) * (2 * i + 2));
        return result;
    }();
    double x_squared = x * x;
    double result = 1;
    double term = 1;
    for (int i = 0; i < ITERATIONS; ++i) {
        term *= x_squared * COEFICIENT_TABLE[i];
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
    return current - (current - x / current) / 2;
}
/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) 
{
    /// I'd prefer throwing to exiting the program, but anyway
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