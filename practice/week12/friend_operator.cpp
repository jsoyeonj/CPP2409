#include <iostream>
using namespace std;
class MyVector
{
private:
    double x, y;

public:
    MyVector(double xvalue = 0.0, double yvalue = 0.0) : x(xvalue), y(yvalue) {}
    friend ostream &operator<<(ostream &os, const MyVector &v)
    { // 멤버함수 불가능
        os << "(" << v.x << "," << v.y << ")" << endl;
        return os;
    }
};
int main()
{
    MyVector v1(1.0, 2.0), v2(3.0, 4.0), v3;
    cout << v1 << v2 << v3;
    return 0;
}
