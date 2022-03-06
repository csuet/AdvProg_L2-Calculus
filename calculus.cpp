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
    	double cosx=1;
	int n=1;	
	double temp=1;
	while(temp>0.0001 || temp<-0.0001){
		temp =1;
		for(int i=1;i<=2*n;i++){
			temp*=(x/(i));
		}
		if(n%2==0) cosx+=temp;
		else cosx-=temp;
		n++;
	}
	return cosx;

}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
   	double sinx=x;
	int n=1;	
	double temp=1;
	while(temp>0.0001 || temp<-0.0001){
		temp =1;
		for(int i=1;i<=2*n+1;i++){
			temp*=(x/(i));
		}
		if(n%2==0) sinx+=temp;
		else sinx-=temp;
		n++;
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
    double n;
	for(int i=0;;i++){
		n=pow(10,2*i);
		if(x/n<1){
			n=pow(10,i-1);
			break;
		}
	}
	double x0,x1=0;
	if(x/n<10) x0=2*n;
	else x0=6*n;
	while(true){
		x1=0.5*(x0+x/x0);
		if(x1==x0) break;
		x0=x1;
	}
    
    return x0;
}

