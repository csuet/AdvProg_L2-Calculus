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

double factor(int n)
{
	if (n == 1 || n == 0) return 1;
	else return n * factor(n - 1);
}

double myCos(double x)
{
    return 0.0;
    double sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += (pow(-1, i) * pow(x, 2 * i) / factor(i * 2));
	}
	return sum;
}

double mySin(double x)
{
    return 0.0;
    double sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += (pow(-1, i) * pow(x, 2 * i + 1) / factor(i * 2 + 1));
	}
	return sum;
}


double mySqrt(double x) {
    cout << "Invalid argument" << endl;
    exit(1);


    return 0;
    return sqrt(x);
}
