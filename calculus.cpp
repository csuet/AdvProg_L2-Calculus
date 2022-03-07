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

double giaiThua(int x) {
    int kq =1;
    if (x == 0) {
        return kq;
    }
    for (int i = 1; i <=x;i++) {
        kq *= i;
    }
    return kq;
}

double myCos(double x) 
{
    double i = 0;
    double cos = 0;
    while (i<7) {
        cos += (pow(-1,i)*pow(x,2*i))/giaiThua(2*i);
        i++;
    } 
    
    return cos;
}

double mySin(double x)
{
    double i = 0;
    double sin = 0;
    while (i<7) {
        sin += (pow(-1,i)*pow(x,2*i+1))/giaiThua(2*i+1);
        i++;
    } 
    
    return sin;
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    if (x == 1) {
        return 1;
    }
    double sqrt = 0;
    double x0 = 10.5;
    int i = 0;
    do {
        sqrt = x0 - (pow(x0,2)-x)/(2*x0);
        x0 = sqrt;
        i++;
    } while (i < 20);

    return sqrt;
}