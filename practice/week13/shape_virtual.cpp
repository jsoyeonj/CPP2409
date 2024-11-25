#include <iostream>
using namespace std;
class Shape
{
protected:
    int x, y;

public:
    Shape(int x, int y) : x(x), y(y) {}
    virtual void Draw()
    {
        cout << "Shape Draw" << endl;
    }
};
class Rect : public Shape
{
private:
    int width, height;

public:
    Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h)
    {
    }
    void Draw()
    {
        cout << "Rectangle Draw" << endl;
    }
};
int main()
{
    Shape *ps = new Rect(0, 0, 100, 100); // OK!
    ps->Draw();
    delete ps;
    return 0;
}
