#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    string address;
};

class Student : public Person
{
public:
    void SetAddress(string add)
    {
        address = add;
    }

    string GetAddress()
    {
        return address;
    }

    void SetName(string n)
    {
        name = n;
    }

    string GetName()
    {
        return name;
    }
};

int main()
{
    Student obj;
    obj.SetName("미수");
    obj.SetAddress("서울시 종로구 1번지");

    cout << obj.GetName() << endl;
    cout << obj.GetAddress() << endl;

    return 0;
}