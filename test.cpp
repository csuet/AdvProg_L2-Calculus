#include <iostream>
#include <string>
#include <cmath>
#include "calculus.h"

int main(){
    double x = 10;
    std::cout << mySqrt(x) << std::endl;
    std::cout << mySqrt(x) - sqrt(x) << std::endl;

    std::cout << myCos(x) << std::endl;
    std::cout << myCos(x) - cos(x) << std::endl;

    std::cout << mySin(x) << std::endl;
    std::cout << mySin(x) - sin(x) << std::endl;
}