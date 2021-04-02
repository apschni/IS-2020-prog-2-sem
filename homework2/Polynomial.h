#ifndef HOMEWORK2_POLYNOMIAL_H
#define HOMEWORK2_POLYNOMIAL_H


#include <ostream>

class Polynomial {
public:
    int minpower;
    int maxpower;
    int n;
    int *coef;
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

    //todo $= should return this(Polynomial&)
    Polynomial operator-=(const Polynomial &) const;

    Polynomial operator+=(const Polynomial &) const;

    Polynomial operator*(const Polynomial &) const;

    friend Polynomial operator*(int, const Polynomial &);

    friend Polynomial operator*(const Polynomial &, int);

    Polynomial operator/(int) const;

    void normalize();

    int operator[](int) const;

    int &operator[](int);

    float get(float) const;

    friend std::ostream &operator<<(std::ostream &, const Polynomial &);
};


#endif
