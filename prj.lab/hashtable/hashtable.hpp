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
        const std::vector<Node *> table;

    public:
        size_t index_get() {
            return index;
        }


        Iterator(size_t i, Node* node, const std::vector<Node*>& tbl)
                : index(i), current(node), table(tbl) {}

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
            return (current != other.current || index != other.index );
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

template <typename KeyType, typename ValueType>
hashTable<KeyType, ValueType>::hashTable() {
    size_ = 60;
    table = std::vector<Node*>(size_, nullptr);
}

template <typename KeyType, typename ValueType>
hashTable<KeyType, ValueType>::hashTable(size_t size) {
    size_ = size;
    table = std::vector<Node*>(size, nullptr);
}


template <typename KeyType, typename ValueType>
hashTable<KeyType, ValueType>::~hashTable() {
    for (Node* node : table) {
        if (node != nullptr) {
            delNode(node);
        }
    }
}

template <typename KeyType, typename ValueType>
void hashTable<KeyType, ValueType>::delNode(Node* node) {
    Node* current = node;
    Node* prev = nullptr;
    while (current != nullptr) {
        prev = current;
        current = current->next;
        delete prev;
    }
}


template <typename KeyType, typename ValueType>
void hashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    size_t hash = hash_function(key) % size_;
    Node* current = table[hash];
    Node* prev = nullptr;

    while (current != nullptr && current->key != key) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        Node* newNode = new Node(key, value);
        if (prev != nullptr) {
            prev->next = newNode;
        } else {
            table[hash] = newNode;
        }
    } else {
        throw std::invalid_argument("Key error");
    }
}


template <typename KeyType, typename ValueType>
bool hashTable<KeyType, ValueType>::contains(const KeyType& key) const {
    size_t hash = hash_function(key) % size_;
    Node* current = table[hash];

    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }

    return false;
}

template <typename KeyType, typename ValueType>
ValueType& hashTable<KeyType, ValueType>::operator[](const KeyType& key) {
    size_t hash = hash_function(key) % size_;
    Node* current = table[hash];
    Node* prev = nullptr;

    while (current != nullptr && current->key != key) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        Node* newNode = new Node(key, ValueType());
        if (prev != nullptr) {
            prev->next = newNode;
        } else {
            table[hash] = newNode;
        }
        return newNode->value;
    }

    return current->value;
}