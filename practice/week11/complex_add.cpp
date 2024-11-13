#include <iostream>
#include <string>
using namespace std;

class Complex
{
public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0)
    {
        real = r;
        imag = i;
        cout << "생성자 호출";
        Print();
    }
    ~Complex()
    {
        cout << "소멸자 호출";
        Print();
    }
    void Print()
    {
        cout << real << "+" << imag << "i" << endl;
    }
};

Complex Add(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main()
{
    Complex c1{1, 2}, c2{3, 4};
    Complex t;
    t = Add(c1, c2);
    t.Print();
    return 0;
}
