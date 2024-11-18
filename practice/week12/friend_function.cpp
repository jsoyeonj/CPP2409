#include <iostream>
using namespace std;
class Box
{
    double length, width, height;

public:
    Box(double l, double w, double h) : length{l}, width{w}, height{h} {}
    friend void printBox(Box box);
};

void printBox(Box box)
{
    cout << "Box( " << box.length << ", " << box.width << ", " << box.height << ") " << endl;
}
int main()
{
    Box box(10, 20, 30);
    printBox(box);
    return 0;
}
