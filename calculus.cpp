#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;
using namespace std;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);
const double denta=0.001;
/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double factorial=1, cosx=1, t;
    double n=1;
    bool check=true;
    while(check){
        factorial=factorial*(2*n-1)*2*n;
        t=pow(-1,n)*pow(x,2*n)/factorial;
        if(abs(t)>=denta) {cosx+=t;}
        else check=false;
        n++;
    }
    return cosx;
}
/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double factorial=1, sinx=x, t;
    double n=1;
    bool check=true;
    while(check){
        factorial=factorial*(2*n+1)*2*n;
        t=pow(-1,n)*pow(x,2*n+1)/factorial;
        if(abs(t)>=denta) sinx+=t;
        else check=false;
        n++;
    }
    return sinx;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double sqrtx=x,t=0;
    double n=1;
    bool check=true;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }else{
        while(abs(sqrtx-t)>=denta){
            t=sqrtx;
            sqrtx=(t+x/t)/2;
        }
    } 
    return sqrtx;
}