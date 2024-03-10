#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
#include "doctest.h"
*/

#include <rational/rational.hpp>
#include "iostream"

/*
TEST_CASE("rational ctor") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(3);
  CHECK(3 == r_int.num());
  CHECK(1 == r_int.den());

  CHECK_THROWS(void(Rational(1, 0)));
}*/


int main(){

    Rational a(5,5);
    Rational b(5,9);
    std::cout << (a+b) <<std::endl;
}