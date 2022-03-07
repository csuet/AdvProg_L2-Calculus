#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;
const double epsilon = 0.000001;
double factorial(double number)
{
    if (number<=1)
    {
        return 1;
    }
    else return number*factorial(number-1);
}

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
    double result = 0;
    double k = 0;
    while (abs(((1/factorial(2*k))*pow(-1,k)*pow(x,2*k))) > epsilon)
    {
        result += ((1/factorial(2*k))*pow(-1,k)*pow(x,2*k));
        k++;
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
    double result = 0;
    double k=1; int pos = 1;
    while (abs((1/factorial(k))*pow(x,k))>epsilon)
    {
        if (pos%2!=0)
        {
            result+=(1/factorial(k))*pow(x,k);
        }
        else result-=(1/factorial(k))*pow(x,k);
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
double mySqrt(double x) {
    double initialGuess = x/2;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else
    {
        while (abs(( (initialGuess*initialGuess - x) / (2*initialGuess) )) > epsilon)
        {
            /* code */
            initialGuess = initialGuess - ((initialGuess*initialGuess - x)/(2*initialGuess));
        }
    }
    return initialGuess;
}