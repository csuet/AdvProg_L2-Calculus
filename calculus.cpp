#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

int giaiThua(int a);
double mySin(double x);
double myCos(double x);
double mySqrt(double x);

int giaiThua(int a)
{
    if(a <= 1) return 1;
    else return giaiThua(a - 1) * a;
}
/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    int sum  = 0;
    for(int i = 0; i < 100; i += 2){
        sum += -pow(-1,2) * pow(x,i) * 1.0 / giaiThua(i);
    }
    return sum ;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    int sum = 0;
    for(int i = 1; i < 100; i += 2){
        sum += -pow(-1, 2) * pow(x, i) * 1.0 / giaiThua(i);
    }
    return sum;
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


    return pow(x, 0.5);
}
