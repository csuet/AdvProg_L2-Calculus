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

double F(double x, int n){
	int a;
	if(n%2==0) a = 1;
	else a = -1;
	double temp = 1;
	for(int i=1;i<=2*n+1;i++){
		temp = temp * x / i;
	}
	return a * temp;
}

double mySin(double x){
	double sinX = 0;
	int n = 0;
	while(abs(F(x,n)) > 0.00001){
		sinX = sinX + F(x,n);
		n++;
	}
	return sinX;
}

double myCos(double x){
	return sqrt(1-sinX*sinX);
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }else{
    	double result = 1.0;
    	while (abs(result * result - x) / x >= 0.00001)
        	result = (x / result  - result) / 2 + result;
    	return result;
	}
}
