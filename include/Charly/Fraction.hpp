#pragma once

#include <iostream>

namespace Charly{

    class Fraction{

        public:
            Fraction(int num, int den);

            Fraction operator+(const Fraction& other) const; // addition

            Fraction operator-(const Fraction& other) const; // soustraction

            Fraction operator*(const Fraction& other) const; // multiplication

            Fraction operator/(const Fraction& other) const; // division

            friend bool operator==(const Fraction& f1, const Fraction& f2); // operator ==

            friend bool operator<(const Fraction& f1, const Fraction& f2); // operator <

            friend bool operator!=(const Fraction& f1, const Fraction& f2); // operator !=

            friend bool operator<=(const Fraction& f1, const Fraction& f2); // operator <=

            friend bool operator>(const Fraction& f1, const Fraction& f2); // operator >

            friend bool operator>=(const Fraction& f1, const Fraction& f2); // operator >=

            friend std::ostream& operator<<(std::ostream& os, const Fraction& f); // operator <<

            void print() const;

            void reduction(bool reduce); // reduction of the fraction

            template <typename T>
            T to_decimal(){
                return static_cast<T>(numerator) / static_cast<T>(denominator);
            }

        private:
            int numerator;
            int denominator;

            void simplify();
    };

}

