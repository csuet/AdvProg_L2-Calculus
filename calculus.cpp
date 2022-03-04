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
    while(x>2*M_PI){
		x-=2*M_PI;
	}
    double cos=1.00;
	int i=1;
	double a=1.00;
	while(a>0.00001){
		a=1.00;
		for(int j =1;j<=2*i;j++){
			a*=x*1.00/j;
		}
		if(i%2==0) cos+=a;
		else cos-=a;
		i++;
	}
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
    return 0.0;
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

    
    return 0;
}