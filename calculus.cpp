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

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double s=0;
    int i=0, a=1;
    while (abs (pow (-1, i/2)*pow (x, i*1.0)/a) > 0.001)
    {
      s+=pow (-1, i/2)*pow (x, i*1.0)/a;
      a=a*(i+1)*(i+2);
      i+=2;
    }
    cout << s;
    return 0.0;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double s=0;
    int i=1, a=1;
    while (abs (pow (-1, (i-1)/2)*pow (x, i*1.0)/a) > 0.001)
    {
      s+=pow (-1, (i-1)/2)*pow (x, i*1.0)/a;
      a=a*(i+1)*(i+2);
      i+=2;
    }
    return s;
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
   else { if (x==0) cout << 0;
    else {
        double y, z=x/2;
        do {
        y=z;
        z=(y+x/y)/2;
        if (z==y) return z;
        } while (z!=y);
} }
}

    
    return 0;
}
