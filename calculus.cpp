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


double myCos(double x) 
{
    double myCos;
    myCos=cos(x);
    return myCos;
}


double mySin(double x)
{
    double mySin;
    my=cos(x);
    return myCos;
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    
    return 0;
}