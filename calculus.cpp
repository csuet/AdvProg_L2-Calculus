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
	int n =1;
	double s=0,t=1.0;
	while(fabs(t)>=1e-6){
		s+=t;
		t*=(-1)*x*x/(n*(n+1));
		n=n+2;
	}
    return s;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
	double sinx, temp;
	int i=0;
	sinx=temp=x;
	while(temp > 0.00001 || temp < -0.00001){
		i++;
		temp = temp*x/(2*i+1)*x/(2*i);
		if(i%2 == 0) sinx = sinx + temp;
		else sinx = sinx -temp;
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
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
	
    double result= 1.0f;
	while(fabs(result*result-x) >= 0.00001){
		result =(x/result-result)/2 +result;
	}
    
    return result;
}
