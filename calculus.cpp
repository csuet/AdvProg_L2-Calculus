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
const double PI = 3.14159265359;
/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{   
    
    
    while(x>PI){ 
        x-=2*PI;
    }
    while(x<-PI){
        x+=2*PI;
    }
    double sum1=1, old_sum1=0;
    long long factorial=1;
    double exponential=1;
    int i=1;
    while(fabs(sum1-old_sum1)>=0.000001){
        old_sum1=sum1;
        exponential=exponential*(x*x);
        factorial=factorial*(2*i)*(2*i-1);
        sum1+=(pow(-1,i)/(factorial))*exponential;
        i++;
    }
    return sum1;
    //  return cos(x);
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
    
double mySin(double x)
{   
    while(x>PI){
        x-=2*PI;
    }
    while(x<-PI){
        x+=2*PI;
    }
    double sum2=x, old_sum2=0;
    long long factorial=1;
    double exponential=x;
    int i=1;
    while(fabs(sum2-old_sum2)>=0.000001){
        old_sum2=sum2;
        exponential=exponential*(x*x);
        factorial=factorial*(2*i)*(2*i+1);
        sum2+=(pow(-1,i)/(factorial))*exponential;
        i++;
    }
    return sum2;
    //  return sin(x);
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double sum3=10, old_sum3=0;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else {
        while(fabs(sum3-old_sum3)>=0.000001){
        old_sum3=sum3;
        sum3=(sum3+x/sum3)/2;
           }   
    }
    return sum3;
    //  return sqrt(x);
}