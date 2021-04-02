#include <cmath>
#include "Polynomial.h"

Polynomial::Polynomial(int minpower, int maxpower, int *coef)
        : minpower(minpower), maxpower(maxpower), n(abs(maxpower - minpower) + 1), coef(coef) {}

Polynomial::Polynomial(const Polynomial &other)
        : minpower(other.minpower), maxpower(other.maxpower),
          n(abs(other.maxpower - other.minpower) + 1), coef(other.coef) {}

Polynomial::Polynomial() : minpower(0), maxpower(0), n(0), coef(new int[1]()) {}

Polynomial &Polynomial::operator=(const Polynomial &rhs) {
    if (this == &rhs) {
        return *this;
    }
    minpower = rhs.minpower;
    maxpower = rhs.maxpower;
    n = rhs.n;
    coef = rhs.coef;
    return *this;
}

Polynomial Polynomial::operator-(const Polynomial &rhs) const {
    Polynomial polynomial = Polynomial(rhs.minpower, rhs.maxpower, coef);
    for (int i = 0; i < polynomial.n; ++i) {
        polynomial.coef[i] *= -1;
    }
    return *this + polynomial;
}

Polynomial Polynomial::operator-() const {
    int *p = new int[n];
    for (int i = 0; i < n; ++i) {
        p[i] = -1 * coef[i];
    }
    return Polynomial(minpower, maxpower, p);
}

Polynomial Polynomial::operator/(const int x) const {
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = coef[i] / x;
    }
    return Polynomial(minpower, maxpower, a);
}

Polynomial Polynomial::operator-=(const Polynomial &rhs) const {
    return *this - rhs;
}

Polynomial Polynomial::operator+=(const Polynomial &rhs) const {
    return *this + rhs;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
    if (polynomial.n == 0) {
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
    return tmp;
}

Polynomial operator*(const Polynomial &rhs, const int v) {
    int *a = new int[rhs.n];
    for (int i = 0; i < rhs.n; i++) {
        a[i] = v * rhs[i];
    }
    return Polynomial(rhs.minpower, rhs.maxpower, a);
}

Polynomial operator*(const int v, const Polynomial &rhs) {
    int *a = new int[rhs.n];
    for (int i = 0; i < rhs.n; i++) {
        a[i] = v * rhs[i];
    }
    return Polynomial(rhs.minpower, rhs.maxpower, a);
}

Polynomial Polynomial::operator+(const Polynomial &rhs) const {
    int newmax = std::max(rhs.maxpower, maxpower);
    int newmin = std::min(rhs.minpower, minpower);
    int *result = new int[abs(newmax - newmin) + 1]();
    int newn = abs(minpower - rhs.minpower);

    if (newmin == rhs.minpower) {
        for (int i = 0; i < rhs.n; i++) {
            result[i] += rhs.coef[i];
        }
        for (int i = newn; i < n + newn; i++) {
            result[i] += coef[i - newn];
        }
    } else {
        for (int i = 0; i < n; i++) {
            result[i] += coef[i];
        }
        for (int i = newn; i < rhs.n + newn; i++) {
            result[i] += rhs.coef[i - newn];
        }
    }
    return Polynomial(newmin, newmax, result);
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
    if (v >= minpower && v <= maxpower){
        return coef[v - minpower];
    }
    int minpower_ = minpower;
    int maxpower_ = maxpower;
    if (v > maxpower) {
        maxpower_ = v;
    }
    if (v < minpower) {
        minpower_ = v;
    }
    int newn = abs(maxpower_ - minpower_) + 1;
    int *newcoef = new int[newn]();

    for (int i = minpower_; i <= maxpower_; ++i) {
        if (v >= minpower && i <= maxpower){
            newcoef[i - minpower_] = coef[i - minpower];
        }
    }
    minpower = minpower_;
    maxpower = maxpower_;
    coef = newcoef;
    n = newn;
    return coef[v - minpower];
}

int Polynomial::operator[](const int v) const {
    if (v > maxpower || v < minpower)
        return 0;
    return coef[v + minpower];
}

float Polynomial::get(float v) const {
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

