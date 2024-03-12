// 2023 by Polevoi Dmitry under Unlicense
#include <rational/rational.hpp>
#include <iostream>

#include <stdexcept>

Rational::Rational(const std::int64_t num, const std::int64_t den)
  : num_(num), den_(den) {
  if (0 == den_) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
}

Rational& Rational::operator++(){
    num_ += den_;
    return *this;
}

Rational& Rational::operator--(){
    num_ -= den_;
    return *this;
}

Rational& Rational::operator++(int){
    Rational t(*this);
    num_ += den_;
    return t;
}

Rational& Rational::operator--(int){
    Rational t(*this);
    num_ -= den_;
    return t;
}


int find_GCD(std::int64_t a, std::int64_t b){
    return b ? find_GCD (b, a % b) : a;
}

Rational & reduction(const Rational& rhs) {
    int a = rhs.num(), b = rhs.den();
    int a_max = std::max(abs(a) , abs(b)), b_min =  std::min(abs(a) , abs(b));
    int sgn = 1;
    if (a * b < 0){ sgn = -1;}
    int delit = find_GCD(a_max, b_min);
    return Rational(sgn * (a / delit), b/delit);
}

bool Rational::operator==(const Rational& rhs) const noexcept {
    auto g = num() * rhs.den_;
    auto v = rhs.num_ * den();
    if (g == v) { return true; }
    else { return false; }
}

bool Rational::operator!=(const Rational& rhs) const noexcept {
    auto g = num() * rhs.den_;
    auto v = rhs.num_ * den();
    if (g != v) { return true; }
    else { return false; }
}

bool Rational::operator<(const Rational& rhs) const noexcept {
    auto g = num() * rhs.den_;
    auto v = rhs.num_ * den();
    if (g < v) { return true; }
    else { return false; }
}
bool Rational::operator<=(const Rational& rhs) const noexcept {
    auto g = num() * rhs.den_;
    auto v = rhs.num_ * den();
    if (g <= v) { return true; }
    else { return false; }
}
bool Rational::operator>(const Rational& rhs) const noexcept {
    auto g = num() * rhs.den_;
    auto v = rhs.num_ * den();
    if (g > v) { return true; }
    else { return false; }
}
bool Rational::operator>=(const Rational& rhs) const noexcept {
    auto g = num() * rhs.den_;
    auto v = rhs.num_ * den();
    if (g >= v) { return true; }
    else { return false; }
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {

    num_ = (num_ * rhs.den_ + den_ * rhs.num_);
    den_ = (den_ * rhs.den_);
    auto t = *this;
    return reduction();
}
Rational& Rational::operator-=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.den_ - den_ * rhs.num_;
    den_ = den_ * rhs.den_;

    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.num_;
    den_ = den_ * rhs.den_;
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    num_ = num_ * rhs.den_;
    den_=den_ * rhs.num_;
    return *this; };

Rational& Rational::operator+=(const int64_t rhs) noexcept {return operator+=(Rational(rhs)); };
Rational& Rational::operator-=(const int64_t rhs) noexcept { return operator-=(Rational(rhs)); };
Rational& Rational::operator*=(const int64_t rhs) noexcept { return operator*=(Rational(rhs)); };
Rational& Rational::operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); };


Rational operator+(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational{lhs} /= rhs; }

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } -= rhs; };
Rational operator*(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } *= rhs; };
Rational operator/(const Rational& lhs, const int64_t rhs) { return Rational{ lhs } /= rhs; }

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator-(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator*(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator/(const int64_t lhs, const Rational& rhs) { return operator+(rhs, lhs); }


/*std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
    ostrm << '(' << re << separator << den << ')');
    return ostrm;
 }

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept { return istrm; }*/

std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << '(' << num_ << ',' << den_ << ')';
    return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
    char leftBrace(0);
    char separator(0);
    char rightBrace(0);
    std::int64_t num(0);
    std::int64_t den(0);
    istrm >> leftBrace >> num >> separator >> den >> rightBrace;
    if (istrm.good()) {
        if ((Rational::leftBrace == leftBrace) && (Rational::separator == separator) && (Rational::rightBrace == rightBrace)) {
            if (den != 0) {
                num_ = num;
                den_ = den;
            }
            else {
                istrm.setstate(std::ios_base::failbit);
            }
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}