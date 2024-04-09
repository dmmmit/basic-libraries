#include "iostream"
#include "Dequeue/dequeue.hpp"
int main(){
    Dequeue a;
    Dequeue b = {1,2,3,4,5};
    Dequeue c = b;

    std::cout << a.empty() << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << b.getBack() << b.getFront() << b.empty() <<  b.getSize() << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << c.getBack() << c.getFront() << c.empty() << c.getSize()<< std::endl;
    std::cout << "------------------" << std::endl;
 // b = c ..   вывод :  5105

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_front(6);
// будет так a { 6,1,2,3 }
    a.getBack();
    std::cout << a.getBack() <<a.getFront() << a.getSize()<< std::endl; //364
    std::cout << "------------------" << std::endl;


    a+=1;
    a+=2;
    // будет так a { 6,1,2,3, 1,2 }
//
    std::cout << a.getBack() <<a.getFront() << a.getSize()<< std::endl; // 266
    std::cout << "------------------" << std::endl;

    //Dequeue b = {1,2,3,4,5};

    std::cout << b.pop_front() <<b.pop_back() << b.getSize()<< std::endl;

    // b = {2,3,4} и размер 3


    std::cout << "------------------" << std::endl;

    a-=100;
    std::cout << a.getFront()  << std::endl; // 100




}