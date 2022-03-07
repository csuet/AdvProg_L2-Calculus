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
double gt(int n){
    if(n==0) return 1;
    return n*gt(n-1);
}
double myCos(double x) 
{   
    double sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += (pow(-1, i) * pow(x, 2 * i) / gt(i * 2));
	}
	return sum;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double result = 0;
    double k=1; int pos = 1;
    while (abs((1/gt(k))*pow(x,k))>0.0001)
    {
        if (pos%2!=0)
        {
            result+=(1/gt(k))*pow(x,k);
        }
        else result-=(1/gt(k))*pow(x,k);
        k+=2; pos++;
    }
    return result;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double number) {
    if (number < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    
   else {
    double result = 1.0f;
    while (fabs(result * result - number) / number >= 0.0001)
        result = (number / result  - result) / 2 + result;
    return result;
   }
}