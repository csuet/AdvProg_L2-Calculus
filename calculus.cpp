#include <iostream>
#include <string>
#include <cmath>
#include<math.h>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x)
{
    return sin(x);
}
double myCos(double x)
{
    return cos(x);
}
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    return sqrt(x);
}

