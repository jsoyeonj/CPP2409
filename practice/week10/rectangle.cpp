#include <iostream>
using namespace std;
class Rectangle
{
    int width, height;

public:
    Rectangle(int w, int h);
    int CalcArea();
};
Rectangle::Rectangle(int w = 0, int h = 0)
{
    width = w;
    height = h;
}
int Rectangle::CalcArea()
{
    return width * height;
}
int main()
{
    Rectangle r{3, 4};

    cout << "사각형의 넓이: " << r.CalcArea() << '\n';
}