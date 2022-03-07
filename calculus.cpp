#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

const double EPSILON = 0.000001;

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
    int n = 0;
    double cos = 0;
    double x_n;
    double giaithua = 1;
    double x_thaythe = 1;
    do
    {
        int a = (n%2 == 0) ? 1 : -1;
        x_n = a * x_thaythe/giaithua;
        cos = cos + x_n;
        x_thaythe = x_thaythe * x * x;   // tinh x mu 2n 
        n++;
        giaithua = giaithua*2*n*(2*n - 1);
    } while (x_n > EPSILON or x_n < -EPSILON);
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
    int n = 0;
    double sin = 0;
    double x_n;
    double giaithua = 1;
    double x_thaythe = x;
    do
    {
        int a = (n%2 == 0) ? 1 : -1;
        x_n = a * x_thaythe/giaithua;
        sin = sin + x_n;
        x_thaythe = x_thaythe * x * x;
        n++;
        giaithua = giaithua*2*n*(2*n + 1);
    } while (x_n > EPSILON || x_n < -EPSILON);
    return sin;
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
	//return sqrt(x);

	//Babylonian method
	double b_prev=x, b=1; 	//day vo han nhung chi can dung cai truoc tinh cai sau
	const double Epsilon = 0.00001;
	while(b-b_prev > Epsilon || b-b_prev < -Epsilon)
    {
		b_prev = b;
		b = (b + x/b) /2;
	}
    return b;
}