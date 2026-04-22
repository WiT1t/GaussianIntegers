#ifndef GAUSSINT_H
#define GAUSSINT_H

#include <bits/stdc++.h>

class GaussInt {
    public:
        int re;
        int im;

        GaussInt(int a, int b);
        int N() const;
        GaussInt conj() const; 
        bool operator==(const GaussInt& other) const;
        GaussInt operator+(const GaussInt& other) const;
        GaussInt operator*(const GaussInt& other) const;
        GaussInt operator-(const GaussInt& other) const;
        GaussInt& operator=(const GaussInt& other);
        GaussInt operator/(const GaussInt& other) const;
        GaussInt operator%(const GaussInt& other) const;
        friend GaussInt gcd(const GaussInt& x, const GaussInt& y);
        friend GaussInt gcd(const std::vector<GaussInt>& list);
        friend GaussInt lcm(const GaussInt& x, const GaussInt& y);
        friend GaussInt lcm(const std::vector<GaussInt>& list);
};

GaussInt::GaussInt(int a, int b) : re(a), im(b) {};

int GaussInt::N() const {
    return re*re + im*im;
}

GaussInt GaussInt::conj() const {
    GaussInt c(re, -im);

    return c;
}

bool GaussInt::operator==(const GaussInt& other) const {
    return (re == other.re && im == other.im);
}

GaussInt GaussInt::operator+(const GaussInt& other) const {
    GaussInt sum(re + other.re, im + other.im);

    return sum;
}

GaussInt GaussInt::operator*(const GaussInt& other) const {
    int a = re * other.re - im * other.im;
    int b = re * other.im + im * other.re;
    GaussInt prod(a, b);

    return prod;
}

GaussInt GaussInt::operator-(const GaussInt& other) const {
    GaussInt diff(re - other.re, im - other.im);

    return diff;
}

GaussInt& GaussInt::operator=(const GaussInt& other) {
    if (this == &other) {
        return *this;
    }

    re = other.re;
    im = other.im;
    
    return *this;
}

GaussInt GaussInt::operator/(const GaussInt& other) const {
    GaussInt numerator = (*this) * other.conj();
    int norm = other.N();

    int n = std::round((double)(numerator.re) / (double)(norm));
    int m = std::round((double)(numerator.im) / (double)(norm));

    numerator = GaussInt(n, m);
    return numerator;
}

GaussInt GaussInt::operator%(const GaussInt& other) const {
    GaussInt r = (*this) / other;
    r = (*this) - (other * r);

    return r;
}

GaussInt gcd(const GaussInt& x, const GaussInt& y) {
    if(x.N() < y.N()) return gcd(y, x);
    if(x == y) return x;
    if(y == GaussInt(0,0)) return x;

    return gcd(y, x%y);
}

GaussInt lcm(const GaussInt& x, const GaussInt& y) {
    return (x / gcd(x,y))*y;
}

GaussInt gcd(const std::vector<GaussInt>& list) {
    if(list.size() == 0) return GaussInt(0, 0);
    if(list.size() == 1) return list[0];

    GaussInt result = list[0];
    for(int i=1; i<list.size(); i++) {
        result = gcd(result, list[i]);
    }

    return result;
}

GaussInt lcm(const std::vector<GaussInt>& list) {
    if(list.size() == 0) return GaussInt(0, 0);
    if(list.size() == 1) return list[0];

    GaussInt result = list[0];
    for(int i=1; i<list.size(); i++) {
        result = lcm(result, list[i]);
    }

    return result;
}

#endif