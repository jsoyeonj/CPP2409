#include <iostream>
#include <string>
using namespace std;
class Shape
{
protected:
    int x, y;

public:
    Shape(int x, int y) : x(x), y(y) {}
    virtual void draw() = 0;
};
class Rect : public Shape
{
private:
    int width, height;

public:
    Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {}
    void draw()
    { // 없으면 에러
        cout << "Rectangle Draw" << endl;
    }
};
int main()
{
    Shape *ps = new Rect(0, 0, 100, 100); // OK!
    ps->draw();                           // Rectangle의 draw()가 호출된다.
    delete ps;
    return 0;
}
