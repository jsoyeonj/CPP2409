#include <iostream>
#include <string>
using namespace std;
class Circle
{
    int x, y;
    int radius;

public:
    static int count; // 정적 변수
    Circle(int x = 0, int y = 0, int radius = 0)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;
        count++;
    }
    // 정적 멤버 함수
    static int getCount()
    {
        return count;
    }
};
int Circle::count = 0;
int main()
{
    cout << "지금까지 생성된 원의 개수 = " << Circle::getCount() << endl;
    Circle c1;
    cout << "지금까지 생성된 원의 개수 = " << Circle::count << endl;
    cout << "지금까지 생성된 원의 개수 = " << c1.count << endl;
    cout << "지금까지 생성된 원의 개수 = " << Circle::getCount() << endl;
    cout << "지금까지 생성된 원의 개수 = " << c1.getCount() << endl;
    Circle c2(100, 100, 30);
    cout << "지금까지 생성된 원의 개수 = " << Circle::count << endl;
    cout << "지금까지 생성된 원의 개수 = " << c2.count << endl;
    cout << "지금까지 생성된 원의 개수 = " << Circle::getCount() << endl;
    cout << "지금까지 생성된 원의 개수 = " << c2.getCount() << endl;
    return 0;
}