#ifndef HOMEWORK2_POLYNOMIAL_H
#define HOMEWORK2_POLYNOMIAL_H


#include <ostream>

class Polynomial {
public:
    int minpower = 0;
    int maxpower = 0;
    int n = abs(maxpower - minpower) + 1;
    int *coef = new int[n];
public:
    Polynomial(int, int, int *);

    Polynomial(const Polynomial &);

    Polynomial();

    Polynomial &operator=(const Polynomial &);

    bool operator==(const Polynomial &) const;
    bool operator!=(const Polynomial &) const;

    Polynomial operator-(const Polynomial &) const;
    Polynomial operator-() const;
    Polynomial operator+(const Polynomial &) const;
    Polynomial operator-=(const Polynomial &) const;
    Polynomial operator+=(const Polynomial &) const;
    Polynomial operator*(const Polynomial &) const;
    friend Polynomial operator*(int, const Polynomial &);
    friend Polynomial operator*(const Polynomial &, int);
    Polynomial operator/(int) const;
    void Format(Polynomial &);
    int operator[](int) const;
    int & operator[](int);

    float get(float) const;

    friend std::ostream &operator<<(std::ostream &, const Polynomial &);
};


#endif
