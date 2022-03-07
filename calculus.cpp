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

double mySin(double x)
{
    double sinx, temp;
    int i = 0;
    sinx = temp = x;
    while (temp > 0.00001 || temp < -0.00001)
    {
        i++;
        temp = temp*x/(2*i+1)*x/(2*i);
        if (i%2==0) sinx = sinx + temp;
        else sinx = sinx - temp;
    }
    return sinx;
}

double myCos(double x)
{
    return mySin(1.5707963327-x);
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double temp = 1.0f;
    while (fabs(temp * temp - x) / x >= 0.00001)
        temp = (x / temp  - temp) / 2 + temp;
    return temp;
}
