#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

double factorial(int n){
    if(n==0 || n==1) return 1;
    return n*factorial(n-1);
}
/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    x= x * M_PI/180.0;
    int n=0;
    double s=0,s1=0,s2=0;//s1 tong cac ptu tai vtri thu i, s2 tong cac ptu tai vtri i-1;
    do{
        s1=s2;
        s+=(pow(-1,n)*pow(x,2*n))/(factorial(2*n));
        s2=s;
        n++;
    }while(abs(s2-s1)>0.00001);
    return s2;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    x= x* M_PI/180.0;
    int n=0;
    double s=0,s1=0,s2=0;
    do{
        s1=s2;
        s+=(pow(-1,n)*pow(x,2*n+1))/(factorial(2*n+1));
        s2=s;
        n++;
    }while(abs(s2-s1)>0.00001);
    return s2;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double ans=1.0;
    if (x < 0) {
        cout << "Invalid argument" << endl;
    }else{
        while(fabs(ans * ans - x ) / x >= 0.000001){
            ans=( x / ans - ans)/ 2 + ans;
        }
    }
    return ans;
}
/*int main(){
    double x;
    cin>>x;
   // x= x * M_PI/180;
    cout<<myCos(x)<<endl;
    cout<<mySin(x)<<endl;
    cout<<mySqrt(x)<<endl;
}*/
