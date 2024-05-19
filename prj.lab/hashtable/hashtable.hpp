// Copyright 2024, zxcry. None of rights reserved.
#pragma once

#include <stdexcept>
#include <utility>
#include <vector>

template <typename KeyType, typename ValueType>
class hashTable {
private:
    struct Node {
        KeyType key;
        ValueType value;
        Node* next;

        Node(const KeyType& k, const ValueType& v): key(k), value(v), next(nullptr) {}
    };

    size_t size_;
    std::vector<Node*> table;
    std::hash<KeyType> hash_function;

    void delNode(Node* node);

public:


    void insert(const KeyType& key, const ValueType& value);
    bool contains(const KeyType& key) const;
    ValueType& operator[](const KeyType& key);


    hashTable();
    ~hashTable();
    explicit hashTable(size_t size);

    class Iterator {
    private:
        size_t index;
        Node* current;
        const std::vector<Node*>& table;

    public:
        size_t getIndex() {
            return index;
        }


        Iterator(size_t i, Node* node, const std::vector<Node*>& tbl) {
            index = i;
            current = node;
            table = tbl;
        }

        Iterator& operator++() {
            if (current == nullptr || current->next == nullptr) {
                index++;
                current = table[index];
                while (current == nullptr && index < table.size()) {
                    index++;
                    current = table[index];
                }
            } else {
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return (index != other.index || current != other.current);
        }
        std::pair<const KeyType&, ValueType&> operator*() const {
            if (current != nullptr) {
                return std::pair<const KeyType&, ValueType&>(current->key, current->value);
            }
        }

    };
    Iterator begin() const {
        if (table[0] != nullptr) {
            return Iterator(0, table[0], table);
        } else {
            Iterator it(0, table[0], table);
            ++it;
            return it;
        }
    }

    Iterator end() const {
        return Iterator(table.size(), nullptr, table);
    }
};
