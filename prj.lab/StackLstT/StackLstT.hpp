#include "iostream"


template <typename T>
class StackLstT {
public:
    StackLstT();
    ~StackLstT();
    StackLstT(const StackLstT<T>& other);
    StackLstT(StackLstT<T>&& other);
    StackLstT(const std::initializer_list<T>& list);

    void push(const T& value);
    void pop();
    T& top() const;
    void swap(StackLstT<T>& other);
    void merge(StackLstT<T>& other);

    bool empty() const;
    std::ptrdiff_t size() const;

    bool operator==(const StackLstT<T>& rhs) const;
    bool operator!=(const StackLstT<T>& rhs) const;

    StackLstT<T>& operator=(const StackLstT<T>& rhs) noexcept;
    StackLstT<T>& operator=(StackLstT<T>&& other);

private:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
};


template <typename T>
StackLstT<T>::StackLstT() {
    head_ = nullptr;
}

template <typename T>
StackLstT<T>::~StackLstT() {
    while (head_) {
        Node* tmp = head_;
        head_ = head_->next;
        delete tmp;
    }
}


template <typename T>
StackLstT<T>::StackLstT(const StackLstT<T>& other) {
    if (other.head_) {
        head_ = new Node{other.top()};
        Node* tmp = other.head_->next;
        Node* curr = head_;

        while (tmp) {
            curr->next = new Node{tmp->value};
            curr = curr->next;
            tmp = tmp->next;
        }
    } else {
        head_ = nullptr;
    }
}

template <typename T>
StackLstT<T>::StackLstT(StackLstT<T>&& other) noexcept {
    head_ = other.head_;
    other.head_ = nullptr;
}

template <typename T>
StackLstT<T>::StackLstT(const std::initializer_list<T>& list) {
    for (const auto& value : list) {
        push(value);
    }
}
template <typename T>
void StackLstT<T>::push(const T& value) {
    Node* new_node = new Node{value};
    new_node->next = head_;
    head_ = new_node;
}

template <typename T>
void StackLstT<T>::pop() {
    if (empty()) {
        throw std::runtime_error("Stack is empty!");
    }

    Node* tmp = head_;
    head_ = head_->next;
    delete tmp;
}
template <typename T>
T& StackLstT<T>::top() const {
    if (empty()) {
        throw std::runtime_error("Stack is empty!");
    }

    return head_->value;
}
template <typename T>
void StackLstT<T>::swap(StackLstT<T>& other) {
    std::swap(head_, other.head_);
}


template <typename T>
bool StackLstT<T>::empty() const {
    return head_ == nullptr;
}

template <typename T>
std::ptrdiff_t StackLstT<T>::size() const {
    std::ptrdiff_t count = 0;
    for (Node* curr = head_; curr; curr = curr->next) {
        ++count;
    }
    return count;
}

template <typename T>
bool StackLstT<T>::operator==(const StackLstT<T>& rhs) const {
    if (empty() || rhs.empty()) {
        return empty() == rhs.empty();
    }

    Node* curr1 = head_;
    Node* curr2 = rhs.head_;

    while (curr1 && curr2) {
        if (curr1->value != curr2->value) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr1 == nullptr && curr2 == nullptr;
}

template <typename T>
bool StackLstT<T>::operator!=(const StackLstT<T>& rhs) const {
    return !(*this == rhs);
}


template <typename T>
void StackLstT<T>::merge(StackLstT<T>& other) {
    if (empty()) {
        head_ = other.head_;
    } else if (other.empty()) {
        return;
    }

    Node* curr = head_;
    while (curr) {
        Node* next = curr->next;
        curr->next = other.top();
        other.pop();
        curr = next;
    }
}

