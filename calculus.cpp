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
    
    const double PI = 3.14159265359;
    while(x>PI){
        x-=2*PI;
    }
    double sum=1, old_sum=0;
    long long factorial=1;
    double exponential=1;
    int i=1;
    while(abs(sum-old_sum)>0.0001){
        old_sum=sum;
        exponential=exponential*(x*x);
        factorial=factorial*(2*i)*(2*i-1);
        sum+=(pow(-1,i)/(factorial))*exponential;
        i++;
    }
    return sum;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{   
    const double PI = 3.14159265359;
    while(x>PI){
        x-=2*PI;
    }
    double sum=x, old_sum=0;
    long long factorial=1;
    double exponential=x;
    int i=1;
    while(abs(sum-old_sum)>0.0001){
        old_sum=sum;
        exponential=exponential*(x*x);
        factorial=factorial*(2*i)*(2*i+1);
        sum+=(pow(-1,i)/(factorial))*exponential;
        i++;
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

    
    return sqrt(x);
}