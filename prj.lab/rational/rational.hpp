// 2023 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20231113
#define RATIONAL_RATIONAL_HPP_20231113

#include <cstdint>
#include <iostream>


class Rational {
public:
  [[nodiscard]] Rational() = default;
  [[nodiscard]] Rational(const Rational&) = default;
  [[nodiscard]] explicit Rational(const std::int64_t num) noexcept : num_(num) { }
  [[nodiscard]] Rational(const std::int64_t num, const std::int64_t den);
  ~Rational() = default;
  [[nodiscard]] Rational& operator=(const Rational&) = default;

  [[nodiscard]] std::int64_t num() const noexcept { return num_; }
  [[nodiscard]] std::int64_t den() const noexcept { return den_; }

  [[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;

  [[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }
  Rational& operator++();
  Rational & operator--();
  Rational & operator++(int);
  Rational & operator--(int);

  Rational & operator+=(const Rational& rhs) noexcept;
  Rational & operator-=(const Rational& rhs) noexcept;
  Rational& operator*=(const Rational& rhs) noexcept;
  Rational& operator/=(const Rational& rhs);

  Rational& operator+=(const int64_t rhs) noexcept;
  Rational& operator-=(const int64_t rhs) noexcept;
  Rational& operator*=(const int64_t rhs) noexcept;
  Rational& operator/=(const int64_t rhs);

  //! \brief Форматированный вывод в поток ostrm рационального числа в виде num/den.
  //!
  //! \param[in,out] ostrm - поток
  //! \retval поток
  std::ostream& WriteTo(std::ostream& ostrm) const noexcept;

  //! \brief Форматированный ввод из потока istrm комплексного числа в виде num/den.
  //!
  //! \param[in,out] istrm - поток
  //! \retval поток
  std::istream& ReadFrom(std::istream& istrm) noexcept;

private:
  std::int64_t num_ = 0; //!< числитель
  std::int64_t den_ = 1; //!< знаменатель, > 0
    static const char leftBrace{ '(' };   //!< левая скобка форматированного представления
    static const char separator{ '/' };   //!< разделитель форматированного представления
    static const char rightBrace{ ')' };  //!< правая скобка форматированного представления
};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int64_t rhs);

[[nodiscard]] Rational operator+(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int64_t lhs, const Rational& rhs);

int find_GCD(std::int64_t a, std::int64_t b);
Rational reduction(std::int64_t a, std::int64_t b);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
    return rhs.WriteTo(ostrm);

}

//! \brief Форматированный ввод из потока istrm комплексного числа \se Complex::read_from.
inline std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
    return rhs.ReadFrom(istrm);
}
#endif // !RATIONAL_RATIONAL_HPP_20231113
