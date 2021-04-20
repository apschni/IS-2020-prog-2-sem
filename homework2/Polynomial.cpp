#include <cmath>
#include "Polynomial.h"

//fixed int* should copy
Polynomial::Polynomial(int minpower, int maxpower, const int *coef_)
        : minpower(minpower), maxpower(maxpower), n(abs(maxpower - minpower) + 1) {
    this->coef = new int[n];
    for (int i = 0; i < n; i++) {
        this->coef[i] = coef_[i];
    }
}

Polynomial::Polynomial(const Polynomial &other)
: minpower(other.minpower), maxpower(other.maxpower), n(abs(other.maxpower - other.minpower) + 1) {
    this->coef = new int[other.n];
    for (int i = 0; i < other.n; i++) {
        this->coef[i] = other.coef[i];
    }
}

Polynomial::Polynomial() : minpower(0), maxpower(0), n(1), coef(new int[1]()) {}

Polynomial &Polynomial::operator=(const Polynomial &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete[] this->coef;
    this->n = rhs.n;
    this->maxpower = rhs.maxpower;
    this->minpower = rhs.minpower;
    this->coef = new int[rhs.n];
    for (int i = 0; i < rhs.n; i++) {
        this->coef[i] = rhs.coef[i];
    }
    return *this;
}

Polynomial Polynomial::operator-(const Polynomial &rhs) const {
    Polynomial poly = *this;
    poly -= rhs;
    return poly;
}

Polynomial Polynomial::operator-() const {
    Polynomial poly = *this;
    for (int i = 0; i < n; ++i) {
        poly.coef[i] = -1 * coef[i];
    }
    return poly;
}

Polynomial Polynomial::operator/(const int x) const {
    Polynomial poly = *this;
    for (int i = 0; i < n; ++i) {
        poly.coef[i] = coef[i] / x;
    }
    return poly;
}

Polynomial &Polynomial::operator-=(const Polynomial &rhs) {
    *this = sign(*this, rhs, -1);
    return *this;
}

//fixed + from += (not opposite way)
Polynomial &Polynomial::operator+=(const Polynomial &rhs) {
    *this = sign(*this, rhs, 1);
    return *this;
}

Polynomial &Polynomial::sign(Polynomial &lhs, const Polynomial &rhs, int prefix) {
    int maxdegree_ = std::max(rhs.maxpower, lhs.maxpower);
    int mindegree_ = std::min(rhs.minpower, lhs.minpower);

    int *newcoef = new int[abs(maxdegree_ - mindegree_) + 1]();
    int newmin = abs(rhs.minpower - lhs.minpower);

    if (mindegree_ == rhs.minpower) {
        for (int i = 0; i < rhs.n; i++) {
            newcoef[i] += prefix * rhs.coef[i];
        }

        for (int i = newmin; i < lhs.n + newmin; i++) {
            newcoef[i] += prefix * lhs.coef[i - newmin];
        }

    } else {
        for (int i = 0; i < lhs.n; i++) {
            newcoef[i] += prefix * lhs.coef[i];
        }
        for (int i = newmin; i < rhs.n + newmin; i++) {
            newcoef[i] += prefix * rhs.coef[i - newmin];
        }
    }
    lhs = Polynomial(mindegree_, maxdegree_, newcoef);
    delete[] newcoef;
    return lhs;
}

Polynomial &Polynomial::operator*=(const Polynomial &rhs) {
    *this = (*this) * rhs;
    return *this;
}

Polynomial &Polynomial::operator*=(const int i) {
    *this = (*this) * i;
    return *this;
}

Polynomial &Polynomial::operator/=(const int i) {
    *this = (*this) / i;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
    if (polynomial.n == 1) {
        os << 0;
        return os;
    }
    for (int i = polynomial.n - 1; i >= 0; --i) {
        if (polynomial.coef[i] == 0) {
            continue;
        }

        if (polynomial.coef[i] < 0) {
            os << "-";
        } else {
            if (i != polynomial.n - 1) {
                os << "+";
            }
        }

        if (polynomial.minpower + i == 0) {
            os << abs(polynomial.coef[i]);
        } else {
            if (abs(polynomial.coef[i]) == 1) {
                if (polynomial.minpower + i == 1) {
                    os << "x";
                    continue;
                } else {
                    os << "x^" << polynomial.minpower + i;
                }
            } else {
                if (polynomial.minpower + i == 1) {
                    os << abs(polynomial.coef[i]) << "x";
                    continue;
                }
                os << abs(polynomial.coef[i]) << "x^" << polynomial.minpower + i;
            }
        }
    }
    return os;
}

Polynomial Polynomial::operator*(const Polynomial &rhs) const {
    int maxdeg = rhs.maxpower + maxpower;
    int mindeg = rhs.minpower + minpower;
    //fixed there will be memory leak
    int *newcoef = new int[abs(maxdeg - mindeg) + 1]();
    if (mindeg == rhs.minpower) {
        for (int i = 0; i < rhs.n; i++) {
            for (int j = 0; j < n; j++) {
                newcoef[i + j] += rhs.coef[i] * coef[j];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rhs.n; j++) {
                newcoef[j + i] += coef[i] * rhs.coef[j];
            }
        }
    }
    Polynomial tmp = Polynomial(mindeg, maxdeg, newcoef);
    tmp.normalize();
    delete[] newcoef;
    return tmp;
}

Polynomial operator*(const Polynomial &rhs, const int v) {
    Polynomial poly = rhs;
    for (int i = 0; i < rhs.n; i++) {
        poly.coef[i] = v * rhs[i];
    }
    return poly;
}

Polynomial operator*(const int v, const Polynomial &rhs) {
    Polynomial poly = rhs;
    for (int i = 0; i < rhs.n; i++) {
        poly.coef[i] = v * rhs[i];
    }
    return poly;
}

Polynomial Polynomial::operator+(const Polynomial &rhs) const {
    Polynomial poly = *this;
    poly += rhs;
    return poly;
}

void Polynomial::normalize() {
    while (coef[n - 1] == 0 && n != 1) {
        maxpower--;
        n--;
    }

    while (coef[0] == 0 && n != 1) {
        for (int i = 0; i < n - 1; i++) {
            coef[i] = coef[i + 1];
        }
        minpower++;
        n--;
    }
}

int &Polynomial::operator[](const int v) {
    int tmp = this->n;
    if (v > this->maxpower)
        this->maxpower = v;
    if (v < this->minpower)
        this->minpower = v;
    this->n = abs(maxpower - minpower) + 1;
    int *newcoef = new int[this->n]();
    for (int i = 0; i < tmp; i++)
        newcoef[i] = this->coef[i];
    Polynomial temp = Polynomial(minpower, maxpower, newcoef);
    *this = temp;
    delete [] newcoef;
    return this->coef[v - this->minpower];
}

int Polynomial::operator[](const int v) const {
    if (v > maxpower || v < minpower)
        return 0;
    return coef[v + minpower];
}

float Polynomial::get(float v) {
    normalize();
    float f = coef[0] * powf(v, minpower);
    float result = f;
    for (int i = 1; i < n; i++) {
        f *= v;
        result += f * coef[i];
    }
    return result;
}

bool Polynomial::operator==(const Polynomial &rhs) const {
    Polynomial other = rhs;
    Polynomial ths = *this;
    other.normalize();
    ths.normalize();

    if (other.minpower != ths.minpower || other.maxpower != ths.maxpower) {
        return false;
    }
    for (int i = 0; i < ths.n; ++i) {
        if (other.coef[i] != ths.coef[i]) {
            return false;
        }
    }
    return true;
}

bool Polynomial::operator!=(const Polynomial &rhs) const {
    return !(rhs == *this);
}

