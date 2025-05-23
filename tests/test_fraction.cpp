#include <iostream>
#include "Charly/Fraction.hpp"

// g++ -O2 -Wall -Wextra -o test_fraction.exe test_fraction.cpp -lCharly

using namespace Charly;


int main(){

    Fraction f1(1, 2); // 1/2
    Fraction f2(3, 4); // 3/4
    Fraction f3(5, 3); // 5/3
    Fraction f4(12, 7); // 12/7


    Fraction sum = f1 + f2 + f2 - f3 * f2 / f4;
    

    sum.reduction(true); // réduire la fraction 
    sum.print(); // afficher le résultat

    std::cin.get(); // attendre une touche presser pour quitter 
    

    return 0;
}