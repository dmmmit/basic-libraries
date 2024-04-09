#include "iostream"

template<typename T>
class StackArrT {
public:
    StackArrT();

    ~StackArrT();

    StackArrT(const StackArrT<T> &other);

    StackArrT(StackArrT<T> &&other);

    StackArrT(const std::initializer_list<T> &list);

    void push(const T &value);

    void pop();

    T &top() const;

    void swap(StackArrT<T> &other);

    void merge(StackArrT<T> &other);

    bool empty() const;

    std::ptrdiff_t size() const;

    bool operator==(const StackArrT<T> &rhs) const;

    bool operator!=(const StackArrT<T> &rhs) const;

    StackArrT<T> &operator=(const StackArrT<T> &rhs) noexcept;

    StackArrT<T> &operator=(StackArrT<T> &&other);

private:
    std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
    std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
    T *data_ = nullptr;   //!< элементы стека
};


template<typename T>
StackArrT<T>::StackArrT() = default;

template<typename T>
StackArrT<T>::~StackArrT() {
    size_ = 0;
    i_top_ = -1;
    delete[] data_;
    data_ = nullptr;
}

template<typename T>
StackArrT<T>::StackArrT(const StackArrT<T> &other) {
    data_ = new T[other.size_];
    i_top_ = other.i_top_;
    size_ = other.size_;
    std::copy(other.data_, other.data_ + other.size_, data_);

}

template<typename T>
StackArrT<T>::StackArrT(StackArrT<T> &&other) {
    data_ = other.data_;
    i_top_ = other.i_top_;
    size_ = other.size_;

    other.data_ = nullptr;
    other.i_top_ = -1;
    other.size_ = 0;
   // StackArrT<T>::swap(*this, other);

}

template<typename T>
StackArrT<T>::StackArrT(const std::initializer_list<T> &list) {
    size_ = list.size();
    i_top_ = size_ - 1;
    data_ = new T[size_];
    std::copy(list.begin(), list.end(), data_);
}

template<typename T>
void StackArrT<T>::push(const T &value) {
    if (data_ == nullptr) { // если стэк еще не создан, создаем
        size_ = 8;
        data_ = new T[size_];
    } else if (size_ == i_top_ + 1) { // если есть стек, но в нем закончилось место для элемента. умножаем сайз на 2
        T *new_data_ = new T[size_ * 2];
        std::copy(data_, data_ + size_, new_data_);
        size_ *= 2;
        std::swap(new_data_, data_);
        delete[] new_data_;
    }
    ++i_top_;

    data_[i_top_] = value; // если место есть в стеке, то закидываем просто элемент

}


template<typename T>
void StackArrT<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Stack is empty :(((");
    } else {
        i_top_--;
    }
}

template<typename T>
T &StackArrT<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty :(((");
    } else {
        return data_[i_top_];

    }
}

template<typename T>
void StackArrT<T>::swap(StackArrT<T> &other) {
    std::swap(other.data_, data_);
    std::swap(other.size_, size_);
    std::swap(other.i_top_, i_top_);
}

template<typename T>
void StackArrT<T>::merge(StackArrT<T> &other) { // просто склейка двух стэков, без сортировки.
    // если нужно с сотрировкой то сначал сортируем std::sort каждый стэк
    if (empty()) {
        this->swap(other);
    }
    else {
        auto new_data_ = new T[size_ + other.size_];
        std::copy(data_, data_ + this->size(), new_data_);
        std::copy(other.data_, other.data_ + other.size(), new_data_ + this->size());
w        i_top_ += other.i_top_ + 1;
        std::swap(new_data_, data_);
        delete[] new_data_;
        //delete [] other.data_;
        size_ += other.size_;
    }
}

template<typename T>
bool StackArrT<T>::empty() const {
    return (i_top_ == -1);
}

template<typename T>
std::ptrdiff_t StackArrT<T>::size() const {
    return i_top_ + 1;
}

template<typename T>
StackArrT<T> &StackArrT<T>::operator=(const StackArrT<T> &rhs) noexcept {
    data_ = new T[rhs.size_];
    i_top_ = rhs.i_top_;
    size_ = rhs.size_;
    std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
return *this;
}


template<typename T>
StackArrT<T> &StackArrT<T>::operator=(StackArrT<T> &&other) {
    data_ = other.data_;
    i_top_ = other.i_top_;
    size_ = other.size_;

    other.data_ = nullptr;
    other.i_top_ = -1;
    other.size_ = 0;
    return *this;
    // StackArrT<T>::swap(*this, other);

}

template<typename T>
bool StackArrT<T>::operator==(const StackArrT<T> &rhs) const {
    if (i_top_ != rhs.i_top_){
        return false;
    }
    for (size_t i = 0; i < rhs.size(); ++i) {
        if (data_[i] != rhs.data_[i]) {
            return false;
        }
    }
    return true;
}


template<typename T>
bool StackArrT<T>::operator!=(const StackArrT<T> &rhs) const {
    return !(this->operator==(rhs));
}
