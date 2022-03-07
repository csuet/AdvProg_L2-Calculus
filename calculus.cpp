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
long long giaiThua(double n);

long long giaiThua(double n){
	long long ans=1;
	for(int i=1;i<=n;i++) ans*=i;
	return ans;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double cos=0,preCos=0,j=0;
	do{
		preCos=cos;
		cos += pow(-1,j)*pow(x,2*j)/giaiThua(2*j);
		j++;
	}while( fabs(cos-preCos) > 0.0000001);
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
    double sin=0,preSin=0,j=0;
	do{
		preSin=sin;
		sin += pow(-1,j)*pow(x,2*j)/giaiThua(2*j+1);
		j++;
	}while( fabs(sin-preSin) > 0.0000001);
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
    }else{
    	double result = 1;
    	while (fabs(result * result - x) / x >= 0.0001){
        	result = (x / result  - result) / 2 + result;
        }
    	return result;
	}

    
    return 0;
}
