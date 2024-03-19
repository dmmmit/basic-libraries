#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <rational/rational.hpp>

TEST_CASE("RATIONAL reduce") {
    Rational r1;
    CHECK(0 == r1.num());
    CHECK(1 == r1.den());

    Rational r_int(3, -1);
    CHECK(-3 == r_int.num());
    CHECK(1 == r_int.den());

    Rational r_sokr(10, 8);
    CHECK(5 == r_sokr.num());
    CHECK(4 == r_sokr.den());

    CHECK(-Rational(5, 4) == Rational(-5, 4));

    CHECK_THROWS(void(Rational(1, 0)),"Zero denumenator in Rational ctor");


}

TEST_CASE("RATIONAL math") {
    Rational a(3, 4);
    Rational b(2, 4);

    CHECK((a + b) == Rational(5, 4));
    CHECK((a - b) == Rational(1, 4));
    CHECK((a * b) == Rational(3, 8));
    CHECK((a / b) == Rational(3, 2));

    CHECK((a + 5) == Rational(23, 4));
    CHECK((a - 5) == Rational(-17, 4));
    CHECK((a * 5) == Rational(15, 4));
    CHECK((a / 5) == Rational(3, 20));

    CHECK((6 + b) == Rational(13, 2));
    CHECK((6 - b) == Rational(-11, 2));
    CHECK((6 * b) == Rational(3, 1));
    CHECK((6 / b) == Rational(1, 12));


}




TEST_CASE("RATIONAL bool") {
    Rational a(3, 4);
    Rational b(2, 4);

    CHECK((a > b) == true);
    CHECK((a >= b) == true);

    CHECK((a < b) == false);
    CHECK((a <= b) == false);

    CHECK((a == b) == false);
    CHECK((a != b) == true);


    Rational c(1, 2);
    Rational d(2, 4);

    CHECK((c == d) == true);
    CHECK((c != d) == false);
    CHECK((c <= d) == true);
    CHECK((c >= d) == true);


}

TEST_CASE("RATIONAL ++ --") {
    Rational v(3, 4);
    Rational w(2, 4);

    CHECK((++v) == Rational(7, 4));
    CHECK((--v) == Rational(3, 4));


}


TEST_CASE("Rational input/output") {
    Rational t(1, 2);
    std::ostringstream output;
    output << t;
    CHECK(output.str() == "1/2");
    Rational m;
    std::istringstream input("5/3");
    input >> m;
    CHECK(m == Rational(5, 3));
}
/*
 *     CHECK((w++) == Rational(1, 2));

    CHECK((w--) == Rational(3, 2));



}




}



*/