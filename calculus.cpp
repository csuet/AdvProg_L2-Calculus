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
    int n = 0;
    double cos = 0;
    double x_n;
    int giaithua = 1;
    do
    {
        x_n = pow(-1,n)*double(pow(x,2*n))/giaithua;
        cos = cos + x_n;    
        n++;
        giaithua = giaithua*2*n*(2*n - 1);
    } while (abs(x_n) > 0.0000001);
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
    int giaithua = 1;
    do
    {
        x_n = pow(-1,n)*double(pow(x,2*n+1))/giaithua;
        sin = sin + x_n;
        n++;
        giaithua = giaithua*2*n*(2*n + 1);
    } while (abs(x_n) > 0.0000001);
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
    double x_moi = x/2 , x_cu;
    do{
        x_cu = x_moi;
        x_moi = x_cu - (x_cu * x_cu - x)/(2 * x_cu);
        cout << x_cu << " " << x_moi << endl;
    }while(abs(x_cu - x_moi) > 0.0000001);
    return x_moi;
}