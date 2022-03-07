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

double gt(int n){
	if(n==1){
		return 1;
	}else{
		return n*gt(n-1);
	}
} 

double mySin(double x){
	int i = 0;
	double s = 0;
	double s1 = 0;
	double s2 = 0;
	do{
		s1 = s2;
		s = s + (pow(-1,i)*pow(x,2*i+1))/(gt(2*i+1));
		s2 = s;
		i++;
	}while(abs(s2-s1)>0.00001);
	return s2;
}

double myCos(double x){
	return sqrt(1-(mySin(x)*mySin(x)));
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
