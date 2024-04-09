#include "iostream"

class Dequeue {
public:
    Dequeue();
    ~Dequeue();
    Dequeue(const Dequeue &other);
    Dequeue(Dequeue &&other);
    Dequeue(const std::initializer_list<int> &list);

    void push_back(const int &value);
    void push_front(const int &value);

    int pop_front();
    int pop_back();

    int getFront() const;
    int getBack() const;


    std::ptrdiff_t getSize() const;
    bool empty() const;

    void operator +=(const int &value); // добавляет в стэк число value в back;
    void operator -=(const int &value); // добавляет в стэк число value в front;

    bool operator >(const int &value); // ; проверяет больше ли первое число чем value  (не робит вроде)
    bool operator <(const int &value); // ; проверяет меньше ли первое число чем value  (не робит вроде)


private:
    std::ptrdiff_t size = 0; // кол-во элементов
    std::ptrdiff_t capacity = 8;// ячеек памяти для него
    std::ptrdiff_t tail = 0; // попа дэка
    std::ptrdiff_t head = 0;// голова начало дэка
    int* data = nullptr;
};


Dequeue::Dequeue() {
    data = new int[capacity];

}

Dequeue::~Dequeue() {
//    size = 0;
//    capacity = 8;
//    tail = 7;
//    head = 8;
    delete[] data;
    data = nullptr;
}


Dequeue::Dequeue(const Dequeue &other) {
    capacity = other.capacity;
    size = other.size;
    tail = other.tail;
    head = other.head;
    data = new int[capacity];
    std::copy(other.data, other.data + capacity, data);

}
Dequeue::Dequeue(Dequeue &&other) {
    capacity = other.capacity;
    size = other.size;
    tail = other.tail;
    head = other.head;
    data = other.data;
    other.capacity = 0;
    other.size = 0;
    other.tail = 0;
    other.head = 0;
    other.data = nullptr;

}

Dequeue::Dequeue(const std::initializer_list<int> &list) {
    size = list.size();
    capacity = size;
    tail = size -1;
    head = 0;
    data = new int[capacity];
    std::copy(list.begin(), list.end(), data);


}

void Dequeue::push_back(const int &value) {
    if (size == capacity){
        throw std::out_of_range("Dequeue is full");
    }
    else{
        tail = (tail + 1) % capacity;

        data[tail] = value;
        size++;
    }
}

void Dequeue::push_front(const int &value) {
    if (size == capacity){
        throw std::out_of_range("Dequeue is full");
    }
    else{
        head = (head - 1 + capacity) % capacity;

        data[head] = value;
        size++;
    }
}



int Dequeue::pop_front() {
    if (empty()){
        throw std::out_of_range("Dequeue is empty");
    }
    else{
        auto value = data[head];
        head = (head + 1) % capacity;
        size--;
        return value;

    }
}

int Dequeue::pop_back() {
    if (empty()){
        throw std::out_of_range("Dequeue is empty");
    }
    else{
        size--;
        auto value = data[tail];
        tail = (tail - 1 + capacity) % capacity;
        return value;

    }
}


int Dequeue::getFront() const{
    if (empty()){
        throw std::out_of_range("Dequeue is empty");
    }
    else{
        return data[head];

    }
}

int Dequeue::getBack() const{
    if (empty()){
        throw std::out_of_range("Dequeue is empty");
    }
    else{
        return data[tail];

    }}

std::ptrdiff_t Dequeue::getSize() const{
    return size;
}

bool Dequeue::empty() const{
    return(size ==0);
}


void Dequeue::operator +=(const int &value){
    push_back(value);
}
void Dequeue::operator -=(const int &value){
    push_front(value);
}

bool Dequeue::operator >(const int &value){
    return (Dequeue::getFront() > value);
}

bool Dequeue::operator <(const int &value){
    return (Dequeue::getFront() < value);

}

