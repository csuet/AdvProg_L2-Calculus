#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;


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
	//return cos(x);

	//Maclaurint series							
	double m_prev=2, m=1, factorial=1, expo=1; 
	int i=1;
	const double Epsilon = 0.00001;
	while(m-m_prev > Epsilon || m-m_prev < -Epsilon) //khi do chinh xac nho hon epsilon
    {
		m_prev=m; 								
		factorial*=4*i*i-2*i; 					//tinh (2n)!
		expo*=x*x;								//tinh x^(2n)
		m+=(i%2==0?1:-1)*expo/factorial;	    
		i++;
	}
	return m;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    //return sin(x);

	//Maclaurint series
	double m_prev=x-1, m=x, factorial=1, expo=x;
	int i=1;
	const double Epsilon = 0.00001;
	while(m-m_prev > Epsilon || m-m_prev < -Epsilon)
    {
		m_prev=m;
		factorial*=4*i*i+2*i;
		expo*=x*x;
		m+=(i%2==0?1:-1)*expo/factorial;
		i++;
	}
	return m;
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
	//return sqrt(x);

	//Babylonian method
	double b_prev=x, b=1; 	
	const double Epsilon = 0.00001;
	while(b-b_prev > Epsilon || b-b_prev < -Epsilon)
    {
		b_prev = b;
		b = (b + x/b) /2;
	}
    return b;
}