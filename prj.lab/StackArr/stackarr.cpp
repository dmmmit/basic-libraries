//
// Created by dimau on 26.03.2024.
//

#include <iostream>
#include <algorithm>

template <typename T>
class StackArrT {
public:
    StackArrT() = default;

    ~StackArrT(){
        if (data_ != nullptr){
            delete [] data_;
        }
    }

    StackArrT(const StackArrT<T>& other) {
        // Копируем элементы из другого стека
        for (const auto& item : other) {
            push(item);
        }
    }
    StackArrT(StackArrT<T>&& other)  noexcept {
        // Перемещаем элементы из другого стека
        swap(*this, other);
    }

    StackArrT(const std::initializer_list<T>& list) {
        for (const auto& item : list) {
            push(item);
        }
    }


    void push(const T& value){
        if (data_ == nullptr){ // если стэк еще не создан, создаем
            size_ = 8;
            data_ = new T[size_];
        }
        else if(size_ = i_top_ + 1 ){ // если есть стек, но в нем закончилось место для элемента. умножаем сайз на 2
            auto new_data_ = new T [size_ * 2];
            std::copy(data_, data_+size_, new_data_);
            size_ *=2;
            std::swap(new_data_, data_);
            delete [] new_data_;
        }
    data_[i_top_] = value; // если место есть в стеке, то закидываем просто элемент
    ++i_top_;

    }
    void pop() {
        if (i_top_ != -1) {
            data_[i_top_] = NULL;
            i_top_ -= 1;
        } else {
            std::cout << "Stack is empty :(((" << std::endl;
        }
    }

    T& top() const{
        if (i_top_ != -1){
            return data_[i_top_];
        }
        else {
            std::cout << "Stack is empty :(((" << std::endl;
        }

    }

    void swap(StackArrT<T>& other){
        std::swap(other.data_, this->data_);

    }

    void merge(StackArrT<T>& other){ // просто склейка двух стэков, без сортировки.
        // если нужно с сотрировкой то сначал сортируем std::sort каждый стэк
    if (other.empty()){
        return;
    }
        auto new_data_ = new T[this->size_ + other.size_];
        std::copy(data_, data_+size_, new_data_);
        std::copy(other.data_, other.data_ + other.size_, new_data_ + size_);
        i_top_ = i_top_ + size(other.data_);
        std::swap (new_data_, data_);
        delete [] new_data_;
        size_ = size(data_);


    }

    bool empty() const{
        return (i_top_ == -1 && size_ == 0);
    }

    std::ptrdiff_t size() const{
        return std::size(data_);
    }

    bool operator==(const StackArrT<T>& rhs) const;
    bool operator!=(const StackArrT<T>& rhs) const;

    StackArrT<T>& operator=(const StackArrT<T>& rhs) noexcept;
    StackArrT<T>& operator=(StackArrT<T>&& other);



private:
    std::ptrdiff_t size_ = 0;   //!< число элементов в буфере ( не количество выделенной памяти.)
    std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
    T* data_ = nullptr;   //!< элементы стека
};




