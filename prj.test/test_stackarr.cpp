#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <StackArr/stackarr.hpp>

TEST_CASE_TEMPLATE("[stackarr] - Constructor", T, int, float, double,
                   long long) {
    SUBCASE("Default constructor") {
        StackArrT<T> defCtor;
        CHECK(defCtor.empty());
    }
    SUBCASE("Copy constructor") {
        StackArrT<T> copyCtor;
        copyCtor.push(1);
        copyCtor.push(4);
        StackArrT<T> copyCtor2(copyCtor);
        CHECK(!copyCtor2.empty());
        CHECK(copyCtor2.top() == 4);
        CHECK(copyCtor2.size() == 2);
    }
    SUBCASE("Move constructor") {
        StackArrT<T> moveCtor;
        moveCtor.push(1);
        moveCtor.push(4);
        StackArrT<T> moveCtor2(std::move(moveCtor));
        CHECK(!moveCtor2.empty());
        CHECK(moveCtor2.top() == 4);
        CHECK(moveCtor2.size() == 2);
    }
    SUBCASE("Copy constructor with empty list") {
        StackArrT<T> copyCtor;
        StackArrT<T> copyCtor2(copyCtor);
        CHECK(copyCtor2.empty());
    }
    SUBCASE("Initializer list constructor") {
        StackArrT<T> initListCtor = {1, 2, 6, 4};
        CHECK(!initListCtor.empty());
        CHECK(initListCtor.top() == 4);
        CHECK(initListCtor.size() == 4);
    }
    SUBCASE("Move constructor with empty list") {
        StackArrT<T> moveCtor;
        StackArrT<T> moveCtor2(std::move(moveCtor));
        CHECK(moveCtor2.empty());
    }
    SUBCASE("Initializer list constructor with empty list") {
        StackArrT<T> initListCtor{};
        CHECK(initListCtor.empty());
    }
}

TEST_CASE_TEMPLATE("[stackarrt] - Push, Pop and Top", T, int, float, double,
                   long long) {
    SUBCASE("Push and Pop") {
        StackArrT<T> s;
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
        StackArrT<T> s;
        CHECK_THROWS_WITH(s.pop(), "Stack is empty :(((");
        CHECK_THROWS_WITH(s.top(), "Stack is empty :(((");
        s.push(1);
        CHECK(s.top() == 1);
        CHECK(!s.empty());
        s.pop();
        CHECK_THROWS_WITH(s.pop(), "Stack is empty :(((");
        CHECK_THROWS_WITH(s.top(), "Stack is empty :(((");
    }
}

TEST_CASE_TEMPLATE("[stackarrt] - Compare", T, int, float, double, long long) {
    SUBCASE("Compare with non-empty stack") {
        StackArrT<T> c1{2, 3, 1, 4};
        StackArrT<T> c2{2, 3, 1, 4};
        StackArrT<T> c3{5, 1, 2, 8};
        CHECK(c1 == c2);
        CHECK(c1 != c3);
    }
    SUBCASE("Compare with empty stack") {
        StackArrT<T> c1{2, 3, 1, 4};
        StackArrT<T> empty1;
        StackArrT<T> empty2;
        CHECK(empty1 == empty2);
        CHECK(empty1 != c1);
    }
}

TEST_CASE_TEMPLATE("[stackarrt] - Swap and merge", T, int, float, double,
                   long long) {
    SUBCASE("Swap") {
        StackArrT<T> s1{2, 3, 1, 4};
        StackArrT<T> s1Cp{2, 3, 1, 4};
        StackArrT<T> s2{5, 1, 2, 8};
        StackArrT<T> s2Cp{5, 1, 2, 8};
        StackArrT<T> s3;
        s1.swap(s2);
        CHECK(s1 == s2Cp);
        CHECK(s2 == s1Cp);
        s1.swap(s3);
        CHECK(s1.empty());
        CHECK(s3 == s2Cp);
    }
    SUBCASE("Merge") {
        StackArrT<T> s1{1, 2, 3, 4};
        StackArrT<T> s2{5, 6, 7, 8};
        StackArrT<T> merged{1, 2, 3, 4, 5, 6, 7, 8};
        s1.merge(s2);
        CHECK(s1 == merged);
    }
    SUBCASE("Merge with empty stack") {
        StackArrT<T> s1{1, 2, 3, 4};
        StackArrT<T> s1Copy{1, 2, 3, 4};
        StackArrT<T> s2;
        s1.merge(s2);
        CHECK(s1 == s1Copy);

        StackArrT<T> s3;
        StackArrT<T> s4 = {5, 6, 7, 8};
        StackArrT<T> s3merged = {5, 6, 7, 8};
        s3.merge(s4);
        CHECK(s3 == s3merged);
    }

}

TEST_CASE_TEMPLATE("[stackarrt] - Assignment", T, int, float, double,
                   long long) {
    StackArrT<T> s1{2, 3, 1, 4};
    StackArrT<T> s2{5, 1, 2, 8};
    s1 = s2;
    CHECK(s1 == s2);
    StackArrT<T> s3;
    StackArrT<T> s4 = {5, 1, 2, 8};
    s4 = s3;
    CHECK(s4.empty());
}
