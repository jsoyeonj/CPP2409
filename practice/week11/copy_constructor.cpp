#include <iostream>
#include <string>
using namespace std;

class MyArray
{
public:
    int size;
    int *data;
    MyArray(int size);
    MyArray(const MyArray &other);
    ~MyArray();
};
MyArray::MyArray(int size)
{
    this->size = size;
    data = new int[size];
}
MyArray::MyArray(const MyArray &other)
{
    this->size = other.size;
    this->data = new int[other.size];
    for (int i = 0; i < size; i++)
        this->data[i] = other.data[i];
    cout << "복사생성자 호출!" << endl;
}

MyArray::~MyArray()
{
    if (data != nullptr)
        delete[] this->data;
    data = nullptr;
}
int main()
{
    MyArray buffer(10);
    buffer.data[0] = 1;
    {
        MyArray clone = buffer; // buffer가 clone에 복사됨
    } // 블록이 끝나면서 clone이 사용했던 data만 사라짐
    buffer.data[0] = 2;
    return 0;
}