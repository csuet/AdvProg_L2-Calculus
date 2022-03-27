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

double factorial( double number ) {
    if ( number == 1 || number == 0 ) return 1;
    else return number * factorial(number - 1);
}

double myCos(double x) 
{
    double sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += (pow(-1, i) * pow(x, 2 * i) / factorial(i * 2));
	}
	return sum;
}

double mySin(double x)
{
    double sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += (pow(-1, i) * pow(x, 2 * i + 1) / factorial(i * 2 + 1));
	}
	return sum;
    
}
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double previousNumber = x;
    double afterNumber = x;
	for (int i = 0; i < 100; i++)
	{
		afterNumber = 1.0 / 2 * (previousNumber + x / previousNumber);
		previousNumber = afterNumber;
	}

	return afterNumber;    
}