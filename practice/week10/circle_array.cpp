#include <iostream>
using namespace std;
class Circle
{
public:
    int x, y;
    int radius;
    Circle()
    {
        x = 0;
        y = 0;
        radius = 0;
    }
    Circle(int x, int y, int r)
    {
        this->x = x;
        this->y = y;
        this->radius = r;
    }
    void Print() { cout << "반지름: " << radius << " @(" << x << ", " << y << ")" << endl; }
};
int main(void)
{
    Circle objArray[10];
    for (Circle &c : objArray)
    {
        c.x = rand() % 500;
        c.y = rand() % 300;
        c.radius = rand() % 100;
    }
    for (Circle c : objArray)
        c.Print();
    return 0;
}