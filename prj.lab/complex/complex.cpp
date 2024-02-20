// 2022 by Polevoi Dmitry under Unlicense
#include <complex/complex.hpp>

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

bool Complex::operator==(const Complex &rhs) const noexcept {
    if (re == rhs.re && im == rhs.im) {
        return true;
    } else {
        return false;
    }
}

bool Complex::operator!=(const Complex &rhs) const noexcept {
    if (re == rhs.re && im == rhs.im) {
        return false;
    } else {
        return true;
    }
}

Complex &Complex::operator+=(const Complex &rhs) noexcept {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex &Complex::operator+=(const double rhs) noexcept {
    re += rhs;
    return *this;
}

Complex &Complex::operator-=(const Complex &rhs) noexcept {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex &Complex::operator-=(const double rhs) noexcept {
    re -= rhs;
    return *this;
}

Complex &Complex::operator*=(const Complex &rhs) noexcept {
    double res_Re = re * rhs.re - im * rhs.im;
    double res_Im = im * rhs.re + re * rhs.im;
    re = res_Re;
    im = res_Im;
    return *this;
}

Complex &Complex::operator*=(const double rhs) noexcept {
    re *= rhs;
    im *= rhs;

    return *this;
}

Complex &Complex::operator/=(const Complex &rhs) {
    double d = rhs.re * rhs.re + rhs.im * rhs.im;
    double res_re = (re * rhs.re + im * rhs.im) / d;
    double res_im = (im * rhs.re - re * rhs.im) / d;
    re = res_re;
    im = res_im;
    return *this;
}

Complex &Complex::operator/=(const double rhs) {
    re /= rhs;
    im /= rhs;

    return *this;
}

std::ostream &Complex::WriteTo(std::ostream &ostrm) const noexcept {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream &Complex::ReadFrom(std::istream &istrm) noexcept {
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

Complex operator+(const Complex &lhs, const Complex &rhs) noexcept {
    return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator+(const Complex &lhs, const double rhs) noexcept {
    return Complex(lhs.re + rhs, lhs.im);
}

Complex operator+(const double lhs, const Complex &rhs) noexcept {
    return Complex(lhs + rhs.re, rhs.im);
}

Complex operator-(const Complex &lhs, const Complex &rhs) noexcept {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator-(const Complex &lhs, const double rhs) noexcept {
    return Complex(lhs.re - rhs, lhs.im);
}

Complex operator-(const double lhs, const Complex &rhs) noexcept {
    return Complex(lhs - rhs.re, rhs.im);
}

Complex operator*(const Complex &lhs, const Complex &rhs) noexcept {
    double res_re = lhs.re * rhs.re - lhs.im * rhs.im;
    double res_im = lhs.im * rhs.re + lhs.re * rhs.im;
    return Complex(res_re, res_im);
}

Complex operator*(const Complex &lhs, const double rhs) noexcept {
    double res_re = lhs.re * rhs;
    double res_im = lhs.im * rhs;
    return Complex(res_re, res_im);
}

Complex operator*(const double lhs, const Complex &rhs) noexcept {
    double res_re = rhs.re * lhs;
    double res_im = rhs.im * lhs;
    return Complex(res_re, res_im);
}

Complex operator/(const Complex &lhs, const Complex &rhs) {

    double d = rhs.re * rhs.re + rhs.im * rhs.im;
    double res_re = (lhs.re * rhs.re + lhs.im * rhs.im) / d;
    double res_im = (lhs.im * rhs.re - lhs.re * rhs.im) / d;

    return Complex(res_re, res_im);
}

Complex operator/(const Complex &lhs, const double rhs) {
    double res_re = lhs.re / rhs;
    double res_im = lhs.im / rhs;

    return Complex(res_re, res_im);
}

Complex operator/(const double lhs, const Complex &rhs) {
    double res_re = rhs.re / lhs;
    double res_im = rhs.im / lhs;
    return Complex(res_re, res_im);
}


