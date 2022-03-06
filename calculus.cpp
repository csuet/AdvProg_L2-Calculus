#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
double myCos(double x);
double mySin(double x);
double mySqrt(double x);
const double epsilon=0.00001;
const double pi = 3.14159265359;
int main(){
double x;
cin>>x;
cout<<fixed<<setprecision(5)<<myCos(x)<<endl;
cout<<fixed<<setprecision(5)<<mySin(x)<<endl;

cout<<fixed<<setprecision(5)<<mySqrt(x)<<endl;
}
double mySin(double x){
	double sinx,temp;
	int i=0;
	bool check=true;
	if(x<0) {
	x=abs(x);
	check=false;}
		
while(x>2*pi){
    x=x-2*pi;
  }
	sinx=x;	
	do{
		i++;
		temp=1;
		
		for(int j=1;j<=2*i+1;j++) {
			
		temp=temp*x/j;
	}
		if(i%2==0) sinx=sinx+ temp;
		else sinx=sinx-temp;
	}while(temp>0.0001||temp<-0.0001);
	if(check)return sinx;
	else  return -sinx;

}
double myCos(double x){
	double cosx,temp;
	int i=0;
	x=abs(x);
	while(x>2*pi) x-=2*pi;
	cosx=1;
	do{
		i++;
		temp=1;
		for(int j=1;j<=2*i;j++){
			temp=temp*x/j;
		}
		if(i%2==0) cosx=cosx+temp;
		else cosx=cosx-temp;
	} while(temp>0.0001||temp<-0.0001);
	return cosx;
}
double mySqrt(double x){
	double result=1;
	if(x<0) cout<<"Invalid argument"<<endl;
	else{
		while(abs((result*result-x)/x)>=epsilon){
			result=(x/result-result)/2+result;
		}
		return result;
	}
}
