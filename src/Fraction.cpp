#include "../include/Charly/Fraction.hpp"
#include <numeric>

namespace Charly{

    Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0){
            throw std::invalid_argument("Denominator cannot be zero"); // le dénominateur ne peut pas être 0
        }
    }

    Fraction Fraction::operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }
    
    Fraction Fraction::operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction Fraction::operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction Fraction::operator/(const Fraction& other) const {
        if (other.numerator == 0){
            throw std::invalid_argument("Division by zero fraction");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

    void Fraction::print() const{
        std::cout << numerator << "/" << denominator << "\n";
    }

    void Fraction::reduction(bool reduce){
        return (!reduce) ? void() : simplify();
    }

    bool operator==(const Fraction& f1, const Fraction& f2){
        return (static_cast<long long>(f1.numerator) * f2.denominator == static_cast<long long>(f2.numerator) * f1.denominator);
    }

    bool operator<(const Fraction& f1, const Fraction& f2){
        return (static_cast<long long>(f1.numerator) * f2.denominator < static_cast<long long>(f2.numerator) * f1.denominator);
    }

    bool operator!=(const Fraction& f1, const Fraction& f2){
        return !(f1 == f2);
    }
    
    bool operator<=(const Fraction& f1, const Fraction& f2){
        return (f1 < f2) || (f1 == f2);
    }

    bool operator>(const Fraction& f1, const Fraction& f2){
        return f2 < f1;
    }

    bool operator>=(const Fraction& f1, const Fraction& f2){
        return (f1 > f2) || (f1 == f2);
    }

    std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    void Fraction::simplify(){
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0){
            denominator = -denominator;
            numerator = -numerator;
        }
    }

}