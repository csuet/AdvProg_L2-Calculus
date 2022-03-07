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

double factorial(double number){
	if(number < 2){
		return 1;
	}else{
		return number*factorial(number-1);
	}
}

double myCos(double x){
	double cosX = 0;
	for(int i=0;i<100;i++){
		cosX += pow(-1, x) * pow(x, i*2) * 1.0 / factorial(i*2);
	}
	return cosX;
}

double mySin(double x){
	double sinX = 0;
	for(int i=0;i<100;i++){
		sinX += pow(-1, x) * pow(x, i*2) * 1.0 / factorial(i*2);
	}
	return sinX;
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }else{
    	double sqrtX = 1;
    	while(fabs(sqrtX * sqrtX -x) / x >= 0.0001){
    		sqrtX = (x / sqrtX - sqrtX) / 2 + sqrtX;
		}
		return sqrtX;
	}
}
