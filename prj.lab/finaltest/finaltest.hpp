#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class IContainerBase {
public:
    virtual void add(int item) = 0;

    virtual void remove(int item) = 0;

    virtual bool contains(int item) = 0;

    virtual ~IContainerBase() = default;

};


struct Node {
    int *data;
    size_t size;
    Node *next;
    Node *prev;

    Node(int capacity) {
        size = 0;
        next = nullptr;
        prev = nullptr;
        data = new int[capacity];
    }

    ~Node() {
        delete[] data;
    }
};


class CustomContainer : public IContainerBase {
public:
    CustomContainer(size_t nodeCapacity_) {
        head = nullptr;
        tail = nullptr;
        nodeCapacity = nodeCapacity_;
    }

    ~CustomContainer() {
        // делитед сначала внутри ноды, потом ноду
        Node *main = head;
        while (main != nullptr) {
            Node *next = main->next;
            delete[] main->data;
            delete main;
            main = next;

        }
    }

    void add(int item) override {
        if (!head) {  // нода путсая
            head = tail = new Node(nodeCapacity);
        } else if (tail->size == nodeCapacity) {  // пласт нода полная
            tail->next = new Node(nodeCapacity);
            tail->next->prev = tail;
            tail = tail->next;
        }
        tail->data[tail->size++] = item;
    }


    void remove(int item) override {
        Node *main = head;
        while (main != nullptr) {
            for (size_t i = 0; i < main->size; i++) {
                if (main->data[i] == item) {
                    for (size_t j = i; j < main->size - 1; j++) {

                        main->data[j] = main->data[j + 1];
                    }
                    main->size--;
                    return;
                }
            }
            main = main->next;
        }
    }

    bool contains(int item) override {
        for (Node* main = head; main != nullptr; main = main->next) {

            for (size_t i = 0; i < main->size; i++) {

                if (main->data[i] == item) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    Node *head;
    Node *tail;
    size_t nodeCapacity;

};

