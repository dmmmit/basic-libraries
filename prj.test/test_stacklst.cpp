#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <StackLstT/stackLstT.hpp>

TEST_CASE_TEMPLATE("[stacklstt] - Constructor", T, int, float, double,
                   long long) {
    SUBCASE("Default constructor") {
        StackLstT<T> defCtor;
        CHECK(defCtor.empty());
    }
    SUBCASE("Copy constructor") {
        StackLstT<T> copyCtor;
        copyCtor.push(1);
        copyCtor.push(4);
        StackLstT<T> copyCtor2(copyCtor);
        CHECK(!copyCtor2.empty());
        CHECK(copyCtor2.top() == 4);
        CHECK(copyCtor2.size() == 2);
    }
    SUBCASE("Move constructor") {
        StackLstT<T> moveCtor;
        moveCtor.push(1);
        moveCtor.push(4);
        StackLstT<T> moveCtor2(std::move(moveCtor));
        CHECK(!moveCtor2.empty());
        CHECK(moveCtor2.top() == 4);
        CHECK(moveCtor2.size() == 2);
    }
    SUBCASE("Copy constructor with empty list") {
        StackLstT<T> copyCtor;
        StackLstT<T> copyCtor2(copyCtor);
        CHECK(copyCtor2.empty());
    }
    SUBCASE("Initializer list constructor") {
        StackLstT<T> initListCtor = {1, 2, 6, 4};
        CHECK(!initListCtor.empty());
        CHECK(initListCtor.top() == 4);
        CHECK(initListCtor.size() == 4);
    }
    SUBCASE("Move constructor with empty list") {
        StackLstT<T> moveCtor;
        StackLstT<T> moveCtor2(std::move(moveCtor));
        CHECK(moveCtor2.empty());
    }
    SUBCASE("Initializer list constructor with empty list") {
        StackLstT<T> initListCtor{};
        CHECK(initListCtor.empty());
    }
}

TEST_CASE_TEMPLATE("[stacklstt] - Push, Pop and Top", T, int, float, double,
                   long long) {
    SUBCASE("Push and Pop") {
        StackLstT<T> s;
        s.push(3);
        s.push(1);
        s.push(2);
        CHECK(s.top() == 2);
        CHECK(s.size() == 3);
        s.pop();
        s.pop();
        CHECK(s.top() == 3);
        CHECK(s.size() == 1);
    }
    SUBCASE("Top and Pop with empty stack") {
        StackLstT<T> s;
        CHECK_THROWS_WITH(s.pop(), "StackLstT - try pop from empty stack.");
        CHECK_THROWS_WITH(s.top(), "StackLstT - try get top from empty stack.");
        s.push(1);
        CHECK(s.top() == 1);
        CHECK(!s.empty());
        s.pop();
        CHECK_THROWS_WITH(s.pop(), "StackLstT - try pop from empty stack.");
        CHECK_THROWS_WITH(s.top(), "StackLstT - try get top from empty stack.");
    }
}

TEST_CASE_TEMPLATE("[stacklstt] - Compare", T, int, float, double, long long) {
    SUBCASE("Compare with non-empty stack") {
        StackLstT<T> c1{2, 3, 1, 4};
        StackLstT<T> c2{2, 3, 1, 4};
        StackLstT<T> c3{5, 1, 2, 8};
        CHECK(c1 == c2);
        CHECK(c1 != c3);
    }
    SUBCASE("Compare with empty stack") {
        StackLstT<T> c1{2, 3, 1, 4};
        StackLstT<T> empty1;
        StackLstT<T> empty2;
        CHECK(empty1 == empty2);
        CHECK(empty1 != c1);
    }
}

TEST_CASE_TEMPLATE("[stackarrt] - Swap and merge", T, int, float, double,
                   long long) {
    SUBCASE("Swap") {
        StackLstT<T> s1{2, 3, 1, 4};
        StackLstT<T> s1Cp{2, 3, 1, 4};
        StackLstT<T> s2{5, 1, 2, 8};
        StackLstT<T> s2Cp{5, 1, 2, 8};
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
    SUBCASE("Merge with empty stack") {
        StackLstT<T> s1{1, 2, 3, 4};
        StackLstT<T> s1Copy{1, 2, 3, 4};
        StackLstT<T> s2;
        s1.merge(s2);
        CHECK(s1 == s1Copy);

        StackLstT<T> s3;
        StackLstT<T> s4 = {5, 6, 7, 8};
        StackLstT<T> s3merged = {5, 6, 7, 8};
        s3.merge(s4);
        CHECK(s3 == s3merged);
    }
}

TEST_CASE_TEMPLATE("[stacklstt] - Assignment", T, int, float, double,
                   long long) {
    StackLstT<T> s1{2, 3, 1, 4};
    StackLstT<T> s2{5, 1, 2, 8};
    s1 = s2;
    CHECK(s1 == s2);
    StackLstT<T> s3;
    StackLstT<T> s4 = {5, 1, 2, 8};
    s4 = s3;
    CHECK(s4.empty());
}
