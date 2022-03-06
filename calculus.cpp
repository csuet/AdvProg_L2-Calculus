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
long long factorial(int x);

long long factorial(int x){
    long long ans=1;
    for (int i=1;i<=x;i++) ans=ans*i;
    return ans;
}

double myCos(double x) 
{
     double cos=0,precos; int m=0;
     do{
        precos=cos;
        cos+=pow(-1,m)*pow(x,2*m)/factorial(2*m);
        m++;
     } while (abs(precos-cos)>=0.0001);
     return cos;
}

double mySin(double x)
{
    double sin=0,presin; int m=0;
    do{
        presin=sin;
        sin+=pow(-1,m)*pow(x,2*m+1)/factorial(2*m+1);
        m++;
    } while (abs(presin-sin)>=0.0001);
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double sqrt=x/2,preSqrt; 
    do{
        preSqrt=sqrt;
        sqrt=(sqrt+x/sqrt)/2;
    } while (abs(preSqrt-sqrt)>=0.000000001);
    return sqrt;
}