#include <iostream>
#include <string>
using namespace std;

class Date
{
    int year, month, day;

public:
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void Print()
    {
        cout << year << "." << month << "." << day << endl;
    }
};

class Person
{
    string name;
    Date birth;

public:
    Person(string n, Date d) : name(n), birth(d) {}
    void Print()
    {
        cout << name << ":";
        birth.Print();
        cout << endl;
    }
};

int main()
{
    Date d{1998, 3, 1};
    Person p{"김철수", d};
    p.Print();
    return 0;
}