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
long long factorial(long n);
/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/

double factorial(int n)
{
    double ans = 1;
    for(int i=1; i<=n; i++){
        ans *= i;
    }
    return ans;
}

double myCos(double x) 
{
	while (x > 2*PI_TEST){
		x -= 2*PI_TEST;
	}
	while (x < -2*PI_TEST){
		x += 2*PI_TEST;
	}
    double cos = 1;
    int i = 1;
    double temp = 1;
    while(temp > 0.00000000001){
        temp = pow(x,2*i)/factorial(2*i);
        if (i % 2 == 0){
            cos += temp;
        }else{
            cos -= temp;
        }
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
    while (x > 2*PI_TEST){
		x -= 2*PI_TEST;
	}
	while (x < -2*PI_TEST){
		x += 2*PI_TEST;
	}
    double sin = 0;
    int i = 0;
    double temp = 1;
    while(temp > 0.0000000000001){
        temp = pow(x,2*i+1) / factorial(2*i+1);
        if (i % 2 == 0){
            sin += temp;
        }else{
            sin -= temp;
        }
        i++;
    }
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
        double sqrt[100];
		sqrt[0] = 1.00;
		int i = 1;
		while (sqrt[i-1] - sqrt[i] > 0.000001){
			sqrt[i] = 0.5 * (sqrt[i-1] + x/sqrt[i-1]);
			i++;
		}
		return sqrt[i-1];
    }
}
