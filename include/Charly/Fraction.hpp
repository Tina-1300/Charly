#pragma once

namespace Charly{

    class Fraction{

        public:
            Fraction(int num, int den);

            // addition
            Fraction operator+(const Fraction& other) const;

            // soustraction
            Fraction operator-(const Fraction& other) const;

            // multiplication
            Fraction operator*(const Fraction& other) const ;

            // division
            Fraction operator/(const Fraction& other) const ;

            void print() const;

            void reduction(bool reduce);

        private:
            int numerator;
            int denominator;

            // simplification de la fraction via PGCD (askip ça va plus vite que la decomposition en nombre premiers)
            void simplify();

    };

}

