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
double giaiThuaCos(double i){
    if(i==0 || i==1)
        return 1;
    else{
        i=2*i;
        int temp=i;
        for(int j=i-1; j>0; j--){
            temp*=j;
        }
        return temp;
    }
}
double giaiThuaSin(double i){
    if(i==0)
        return 1;
    else{
        i=2*i+1;
        int temp=i;
        for(int j=i-1; j>0; j--){
            temp*=j;
        }
        return temp;
    }
}
double myCos(double x) 
{
    double result=0;
    for(int i=0; i<100; i++){
        result+=(pow((-1),i)*pow(x,2*i)/giaiThuaCos(i));
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double result=0;
    for(int i=0; i<100; i++){
        result+=(pow((-1),i)*pow(x,2*i+1)/giaiThuaSin(i));
    }
    return result;
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
    else{
        double root=x;
        for(int i=0; i<100; i++){
            root=1.0/2*(root+x/root);
        }
        return root;
    }
}