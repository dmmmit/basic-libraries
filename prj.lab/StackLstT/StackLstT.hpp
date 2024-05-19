#include "iostream"


template <typename T>
class StackLstT {
public:
    StackLstT();
    ~StackLstT();
    StackLstT(const StackLstT<T>& other);
    StackLstT(StackLstT<T>&& other) noexcept;
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

    StackLstT<T>& operator=(StackLstT<T>&& other);
    StackLstT<T>& operator=(const StackLstT<T>& rhs);


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
    Node* temp = head_;
    while (temp != nullptr) {
        head_ = head_->next;
        delete temp;
        temp = head_;
    }
}


template <typename T>
StackLstT<T>::StackLstT(const StackLstT<T>& other){
    if (!other.empty()) {
        Node* temp = new Node{other.head_->value, nullptr};
        head_ = temp;
        Node* x2 = other.head_->next;
        Node* x1 = temp;
        while (x2 != nullptr) {
            temp = new Node{x2->value, nullptr};
            x1->next = temp;
            x2 = x2->next;
            x1 = temp;
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
StackLstT<T>::StackLstT(const std::initializer_list<T> &list) {
    T* mas = new T [list.size()];
    std::reverse_copy(list.begin(), list.end(), mas);
    Node* temp = new Node {mas[0], nullptr};
    head_ = temp;
    Node* x1 = temp;
    for (int i = 1; i < list.size(); i++) {
        Node* tmp = new Node {mas[i], nullptr};
        x1->next = tmp;
        x1 = tmp;
    }
}

template <typename T>
void StackLstT<T>::push(const T& value) {
    Node* new_node = new Node{value, head_};
   // new_node->next = head_;
    head_ = new_node;
}

template <typename T>
void StackLstT<T>::pop() {
    if (empty()) {
        throw std::runtime_error("Stack is empty!");
    } else {
        Node *tmp = head_;
        head_ = head_->next;
        delete tmp;
    }
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
    Node* tmp = head_;
    std::ptrdiff_t counter = 0;
    while (tmp != nullptr) {
        tmp = tmp->next;
        counter++;
    }
    return counter;
}

template<typename T>
bool StackLstT<T>::operator==(const StackLstT<T> &rhs) const {
    Node* temp1 = head_;
    Node* temp2 = rhs.head_;
    if (size() == rhs.size()) {
        while (temp2 != nullptr) {
            if (temp1->value != temp2->value) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    return false;
}

template <typename T>
StackLstT<T> &StackLstT<T>::operator=(const StackLstT<T> &rhs) {
    if (this != &rhs) {
        if (!rhs.empty()) {
            Node *tmp = new Node{rhs.head_->value, nullptr};
            head_ = tmp;
            Node *x2 = rhs.head_->next;
            Node *x1 = tmp;
            while (x2 != nullptr) {
                tmp = new Node{x2->value, nullptr};
                x1->next = tmp;
                x2 = x2->next;
                x1 = tmp;
            }
        } else {
            head_ = nullptr;
        }
    }
    return *this;
}


template <typename T>
bool StackLstT<T>::operator!=(const StackLstT<T>& rhs) const {
    return !operator==(rhs);
}


template <typename T>
void StackLstT<T>::merge(StackLstT<T>& other) {
    if (empty()) {
        this->swap(other);
    }
    else if (!other.empty()) {
        Node* tmp = other.head_;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = head_;
        head_ = other.head_;
        other.head_ = nullptr;
    }
}

