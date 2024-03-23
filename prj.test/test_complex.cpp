#include <iostream>
#include <complex/complex.hpp>
#include <sstream>

void constructor()
{
    std::cout << "\n1) Constructor checking\n";
    Complex a;
    std::cout << "Complex() -> " << a << "\n";
    a = Complex(1);
    std::cout << "Complex(1) -> " << a << "\n";
    a = Complex(2, 2);
    std::cout << "Complex(2, 2) -> " << a << "\n";
    Complex b = Complex(a);
    std::cout << "Complex(a) -> " << b << "\n\n";
}

void input(){
    std::cout << "2) Input checking\n";

    {
        std::istringstream inp("(1.2,1)");
        Complex a;
        inp >> a;
        std::cout << "Input -> (1.2,1) -> a = " << a << "\n";
    }
    {
        std::istringstream inp("(1.2, 1)");
        Complex a;
        inp >> a;
        std::cout << "Input -> (1.2, 1) -> a = " << a << "\n";
    }
    {
        std::istringstream inp("(1,2,1)");
        Complex a;
        inp >> a;
        std::cout << "Input -> (1,2,1) -> a = " << a << "\n";
    }
    {
        std::istringstream inp("1.2, 1");
        Complex a;
        inp >> a;
        std::cout << "Input -> 1.2, 1 -> a = " << a << "\n";
    }
    {
        std::istringstream inp("{1.2 1}");
        Complex a;
        inp >> a;
        std::cout << "Input -> {1.2 1} -> a = " << a << "\n";
    }
    {
        std::istringstream inp("[1.2,1]");
        Complex a;
        inp >> a;
        std::cout << "Input -> [1.2,1] -> a = " << a << "\n";
    }
    {
        std::istringstream inp("(1,2, 1)");
        Complex a;
        inp >> a;
        std::cout << "Input -> (1,2, 1) -> a = " << a << "\n\n";
    }
}

void appch(){
    std::cout << "Appch" << "\n";
    Complex a = Complex(1,1);
    a = Complex(2, 2);
    std::cout << "a(1, 1) = Complex(2, 2)  ->  " << a << "\n\n";

}
void summ(){
    std::cout << "3) Sum checking\n";
    Complex a = {1.2, 3}, b = {2, 4.5};
    std::cout << "a = " << a << " " << "b = " << b << "\n";
    double c = 2;
    std::cout << "a + b = " << a + b << "\n";
    std::cout << "c = " << c << ", a + c = " << a + c << "\n";
    a += b;
    std::cout << "a += b -> " << a << "\n\n";
}

void dif(){
    std::cout << "4) Dif test\n";
    Complex a = {1.5, 3}, b = {1, 4.5};
    std::cout << "a = " << a << " " << "b = " << b << "\n";
    double c = 2;
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "c = " << c << ", a - c = " << a - c << "\n";
    a -= b;
    std::cout << "a -= b -> " << a << "\n\n";
}

void multiply(){
    std::cout << "5) Multiply test\n";
    Complex a = {1.2, 3}, b = {2, 5};
    std::cout << "a = " << a << " " << "b = " << b << "\n";
    double c = 2;
    std::cout << "a * b = " << a * b << "\n";
    std::cout << "c = " << c << ", a * c = " << a * c << "\n";
    a *= b;
    std::cout << "a *= b -> " << a << "\n\n";
}

void div(){
    std::cout << "6) Div test\n";
    {
        Complex a = {2, 3}, b = {2, 3};
        std::cout << "a = " << a << " " << "b = " << b << "\n";
        double c = 2;
        std::cout << "a / b = " << a / b << "\n";
        std::cout << "c = " << c << ", a / c = " << a / c << "\n";
        a /= b;
        std::cout << "a /= b -> " << a << "\n\n";
    }

}

void equal(){
    std::cout << "7) equality check\n";
    bool c = Complex(1, 1) == Complex(1, 1);
    std::cout << "Complex(1, 1) == Complex(1, 1) -> " << c << "\n";
    c = Complex(1, 1) == Complex(1, 2);
    std::cout << "Complex(1, 1) == Complex(1, 2) -> " << c << "\n";
    c = Complex(1, 1) == Complex(2, 1);
    std::cout << "Complex(1, 1) == Complex(2, 1) -> " << c << "\n";
    c = Complex(1, 1) == Complex(2, 2);
    std::cout << "Complex(1, 1) == Complex(2, 2) -> " << c << "\n";
    c = Complex(1, 0) == double(1);
    std::cout << "Complex(1, 0) == double(1) -> " << c << "\n";
    c = Complex(1, 1) == double(1);
    std::cout << "Complex(1, 1) == double(1) -> " << c << "\n";
    c = Complex(2, 0) == double(1);
    std::cout << "Complex(2, 0) == double(1) -> " << c << "\n";
    c = Complex(1, 0) == double(2);
    std::cout << "Complex(1, 0) == double(2) -> " << c << "\n";
    c = Complex(1, 1) != Complex(1, 1);
    std::cout << "Complex(1, 1) != Complex(1, 1) -> " << c << "\n";
    c = Complex(1, 1) != Complex(1, 2);
    std::cout << "Complex(1, 1) != Complex(1, 2) -> " << c << "\n";
    c = Complex(1, 1) != Complex(2, 1);
    std::cout << "Complex(1, 1) != Complex(2, 1) -> " << c << "\n";
    c = Complex(1, 1) != Complex(2, 2);
    std::cout << "Complex(1, 1) != Complex(2, 2) -> " << c << "\n";

    c = Complex(1, 0) != double(1);
    std::cout << "Complex(1, 0) != double(1) -> " << c << "\n";
    c = Complex(1, 1) != double(1);
    std::cout << "Complex(1, 1) != double(1) -> " << c << "\n";
    c = Complex(2, 0) != double(1);
    std::cout << "Complex(2, 0) != double(1) -> " << c << "\n";
    c = Complex(1, 0) != double(2);
    std::cout << "Complex(1, 0) != double(2) -> " << c << "\n";
}

int main()
{
    constructor();
    input();
    appch();
    summ();
    dif();
    multiply();
    div();
    equal();
    return 0;
}