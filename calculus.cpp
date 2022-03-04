#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x)
{
    return x-(1/6)*x*x*x+(1/120)*x*x*x*x*x;
}
double myCos(double x);
{
    return 1-(1/2)*x*x+(1/24)*x*x*x*x;
}
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    return sqrt(x);
}

