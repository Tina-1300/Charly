#include <iostream>
#include "Charly/Fraction.hpp"

// g++ -O2 -Wall -Wextra -o test_fraction.exe test_fraction.cpp -lCharly

/*
Added support for fractions, whether integers, floats, etc.
Not just ints

And added real unit tests with Catch2 or other...
*/

using namespace Charly;

int main(){

    Fraction f1(1, 2); // 1/2
    Fraction f2(3, 4); // 3/4
    Fraction f3(5, 3); // 5/3
    Fraction f4(12, 7); // 12/7

    Fraction sum = f1 + f2 + f2 - f3 * f2 / f4;
    
    if(f1 == f3){
        std::cout << "vrai"<<"\n";
    }else{
        std::cout << "faux" << "\n";
    }

    if(f1 < f2){
        std::cout << "vrai" << "\n";
    }

    if(f1 != f2){
        std::cout << "vrai" << "\n";
    }

    if(f1 <= f2 && f1 <= f1){
        std::cout << "vrai" << "\n";
    }

    if(f2 > f1){
        std::cout << "vrai" << "\n";
    }

    if (f2 >= f1 && f2 >= f2){
        std::cout << "vrai" << "\n";
    }

    std::cout << f1 << "\n";

    std::cout << f1.to_decimal<double>() << "\n";

    sum.reduction(true); // reduce the fraction
    sum.print(); // show result

    std::cin.get(); // wait for a key press to exit
    
    return 0;
}