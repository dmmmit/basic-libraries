
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <HashTable/hashtable.hpp>
#include <vector>

#include "doctest.h"

TEST_CASE_TEMPLATE("[HashTable] numeric keys", T, int, float, double,
                   long long) {
    SUBCASE("[HashTable] - Constructor") {
        hashTable<T, T> h;
        hashTable<T, T> h2(100);
    }

    SUBCASE("[HashTable] - Insert & Contains") {
        hashTable<T, T> h;
        h.insert(1, 1);
        h.insert(2, 2);
        h.insert(13, 31);
        CHECK(h.contains(1));
        CHECK(h.contains(2));
        CHECK(!h.contains(3));
    }

    SUBCASE("[HashTable] - Operator[]") {
        hashTable<T, T> h;
        h[1] = 1;
        h[2] = 2;
        CHECK(h.contains(1));
        CHECK(h.contains(2));
        CHECK(!h.contains(3));
        CHECK(h[1] == 1);
        h[1]++;
        CHECK(h[1] == 2);
    }

    SUBCASE("[HashTable] - Iterator") {
        hashTable<T, T> h(30);
        h.insert(1, 1);
        h.insert(2, 6);
        h.insert(3, 9);
        auto it = h.begin();
        auto it2 = h.end();
        CHECK(it != it2);
        std::vector<T> v = {9, 1, 6};
        for (auto el : h) {
            CHECK(v.end() != std::find(v.begin(), v.end(), el.second));
        }
    }
}
TEST_CASE_TEMPLATE("[HashTable] string keys", T, std::string) {
    SUBCASE("[HashTable] - Constructor") {
        hashTable<T, T> h;
        hashTable<T, T> h2(100);
    }

    SUBCASE("[HashTable] - Insert & Contains") {
        hashTable<T, T> h;
        h.insert("Key1", "Value1");
        h.insert("Key2", "Value2");
        h.insert("Key3", "Value3");
        CHECK(h.contains("Key1"));
        CHECK(h.contains("Key2"));
        CHECK(!h.contains("Lol"));
    }

    SUBCASE("[HashTable] - Operator[]") {
        hashTable<T, T> h;
        h["Key"] = "some value";
        h["Defenitely key"] = "some value too";
        CHECK(h.contains("Key"));
        CHECK(h.contains("Defenitely key"));
        CHECK(!h.contains("Something else"));
        CHECK(h["Key"] == "some value");
        h["Key"] = "New value";
        CHECK(h["Key"] == "New value");
    }

    SUBCASE("[HashTable] - Iterator") {
        hashTable<T, T> h(30);
        h.insert("Key1", "Value1");
        h.insert("Key2", "Value2");
        h.insert("Key3", "Value3");

        auto it = h.begin();
        auto it2 = h.end();
        CHECK(it != it2);

        bool allContains = true;
        std::vector<T> v = {"Value1", "Value2", "Value3"};
        for (auto el : h) {
            if (v.end() == std::find(v.begin(), v.end(), el.second)) {
                allContains = false;
            }
        }
        CHECK(allContains);

        h.insert("Key", "Value");
        for (auto el : h) {
            if (v.end() == std::find(v.begin(), v.end(), el.second)) {
                allContains = false;
            }
        }
        CHECK(!allContains);
    }
}
