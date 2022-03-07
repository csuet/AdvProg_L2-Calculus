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

double Factorial( double n ) {
    if ( n == 1 || n == 0 ) return 1;
    else 
	return n * Factorial(n - 1);
}

double myCos(double x) 
{
    double sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += (pow(-1, i) * pow(x, 2 * i) / Factorial(i * 2));
	}

	return sum;
}

double mySin(double x)
{
    double sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += (pow(-1, i) * pow(x, 2 * i + 1) / Factorial(i * 2 + 1));
	}

	return sum;
}
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double preNum = x;
    double afterNum = x;
	for (int i = 0; i < 100; i++)
	{
		afterNum = 1.0 / 2 * (preNum + x / preNum);
		preNum = afterNum;
	}

	return afterNum;    
}