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
double mySin(double x)
{
  const double PI = 3.141592653589;
  x -= (int)(x / (PI * 2)) * (PI * 2);
  double res = 0.0;
  // double expo = x, factorial = 1;
  double add = x;
  int num = 1;
  for (int i = 0; i < 10; ++i) {
    res += add; add *= -1;
    add *= x * x;
    add /= ++num;  
    add /= ++num;  
  }
  return res;
}

double myCos(double x)
{
  const double PI = 3.141592653589;
  x -= (int)(x / (PI * 2)) * (PI * 2);
  double res = 0.0;
  // double expo = x, factorial = 1;
  double add = 1;
  int num = 0;
  for (int i = 0; i < 10; ++i) {
    res += add; add *= -1;
    add *= x * x;
    add /= ++num;  
    add /= ++num;  
  }
  return res;
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
    double res = 0;
    for (int i = 0; i < 10; ++i) res -= (res * res - x) / (res * 2);
    
    return res;
}
