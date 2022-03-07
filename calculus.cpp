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

double fac(int n){
	if(n<2){
		return 1;
	}else{
		return n*fac(n-1);
	}
}

double myCos(double x){
	double cosx = 0;
	for(int i=0;i<100;i++){
		cosx += pow(-1,i) * pow(x,i*2) * 1.0 / fac(i*2);
	}
	return cosx;
}

double mySin(double x){
	double sinx = 0;
	for(int j=0;j<100;j++){
		sinx += pow(-1,j) * pow(x,j*2) * 1.0 / fac(j*2);
	}
	return sinx;
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }else{
    	double sqrtx = 1.0;
    	while(fabs(sqrtx * sqrtx -x) / x >= 0.0001){
    		sqrtx = (x / sqrtx - sqrtx) / 2 + sqrtx;
		}
		return sqrtx;
	}
}
