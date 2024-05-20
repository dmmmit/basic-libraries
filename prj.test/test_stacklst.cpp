#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <StackLstT/stackLstT.hpp>

TEST_CASE_TEMPLATE("Constructor", T, int, float, double,
                   long long) {
    SUBCASE("Constructor") {
        StackLstT<T> constr;
        CHECK(constr.empty());
    }
    SUBCASE("Copy constructor") {
        StackLstT<T> copyconstr;
        copyconstr.push(1);
        copyconstr.push(10);
        StackLstT<T> copyconstr2(copyconstr);
        CHECK(!copyconstr2.empty());
        CHECK(copyconstr2.top() == 10);
        CHECK(copyconstr2.size() == 2);
    }
    SUBCASE("Move constructor") {
        StackLstT<T> moveconstr;
        moveconstr.push(1);
        moveconstr.push(10);
        StackLstT<T> moveconstr2(std::move(moveconstr));
        CHECK(!moveconstr2.empty());
        CHECK(moveconstr2.top() == 10);
        CHECK(moveconstr2.size() == 2);
    }
    SUBCASE("Copy constructor") {
        StackLstT<T> copyconstr;
        StackLstT<T> copyconstr2(copyconstr);
        CHECK(copyconstr2.empty());
    }
    SUBCASE("Initializer") {
        StackLstT<T> initlistconstruc = {1, 2, 4, 4};
        CHECK(!initlistconstruc.empty());
        CHECK(initlistconstruc.top() == 4);
        CHECK(initlistconstruc.size() == 4);
    }
    SUBCASE("Move constructor with empty list") {
        StackLstT<T> moveconstr;
        StackLstT<T> moveconstr2(std::move(moveconstr));
        CHECK(moveconstr2.empty());
    }
    SUBCASE("Initializer list constructor") {
        StackLstT<T> initlistconstruc{};
        CHECK(initlistconstruc.empty());
    }
}

TEST_CASE_TEMPLATE("Push, Pop and Top", T, int, float, double,
                   long long) {
    SUBCASE("Push and Pop") {
        StackLstT<T> sp;
        sp.push(1);
        sp.push(2);
        sp.push(3);
        CHECK(sp.top() == 3);
        CHECK(sp.size() == 3);
        sp.pop();
        sp.pop();
        CHECK(sp.top() == 1);
        CHECK(sp.size() == 1);
    }
    SUBCASE("Top and Pop with empstack") {
        StackLstT<T> sp;
        CHECK_THROWS_WITH(sp.pop(), "Stack is empty!");
        CHECK_THROWS_WITH(sp.top(), "Stack is empty!");
        sp.push(1);
        CHECK(sp.top() == 1);
        CHECK(!sp.empty());
        sp.pop();
        CHECK_THROWS_WITH(sp.pop(), "Stack is empty!");
        CHECK_THROWS_WITH(sp.top(), "Stack is empty!");
    }
}

TEST_CASE_TEMPLATE("Compare", T, int, float, double, long long) {
    SUBCASE("Compare with stack") {
        StackLstT<T> sp1{1, 2, 3, 4};
        StackLstT<T> sp2{1, 2, 3, 4};
        StackLstT<T> sp3{5, 6, 7, 8};
        CHECK(sp1 == sp2);
        CHECK(sp1 != sp3);
    }
    SUBCASE("Compare with empstack") {
        StackLstT<T> sp1{1, 2, 3, 4};
        StackLstT<T> empty1;
        StackLstT<T> empty2;
        CHECK(empty1 == empty2);
        CHECK(empty1 != sp1);
    }
}

TEST_CASE_TEMPLATE("Swap and merge", T, int, float, double,
                   long long) {
    SUBCASE("Swap") {
        StackLstT<T> s1{1, 2, 3, 4};
        StackLstT<T> s1Cp{1, 2, 3, 4};
        StackLstT<T> s2{5, 6, 7, 8};
        StackLstT<T> s2Cp{5, 6, 7, 8};
        StackLstT<T> s3;
        s1.swap(s2);
        CHECK(s1 == s2Cp);
        CHECK(s2 == s1Cp);
        s1.swap(s3);
        CHECK(s1.empty());
        CHECK(s3 == s2Cp);
    }
    SUBCASE("Merge") {
        StackLstT<T> s1{1, 2, 3, 4};
        StackLstT<T> s2{5, 6, 7, 8};
        StackLstT<T> merged{1, 2, 3, 4, 5, 6, 7, 8};
        s1.merge(s2);
        CHECK(s1 == merged);
    }
    SUBCASE("Merge with empstack") {
        StackLstT<T> s1{1, 2, 3, 4};
        StackLstT<T> s1Copy{1, 2, 3, 4};
        StackLstT<T> s2;
        s1.merge(s2);
        CHECK(s1 == s1Copy);

        StackLstT<T> s3;
        StackLstT<T> s4 = {1, 2, 3, 4};
        StackLstT<T> s3merged = {1, 2, 3, 4};
        s3.merge(s4);
        CHECK(s3 == s3merged);
    }
}

TEST_CASE_TEMPLATE("[stacklstt] - Assignment", T, int, float, double,
                   long long) {
    StackLstT<T> s1{11, 12, 13, 14};
    StackLstT<T> s2{8, 9, 10, 11};
    s1 = s2;
    CHECK(s1 == s2);
    StackLstT<T> s3;
    StackLstT<T> s4 = {1, 2, 3, 4};
    s4 = s3;
    CHECK(s4.empty());
}
