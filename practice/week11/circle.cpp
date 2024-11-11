#include <iostream>
using namespace std;
class Circle
{
private:
    int radius;

public:
    Circle() { radius = 10; }
    ~Circle() {}
    void SetRadius(int radius) { this->radius = radius; }
    int GetRadius() const { return radius; }
};
int main()
{
    Circle *p = new Circle();
    const Circle *pConstObj = new Circle();
    Circle *const pConstPtr = new Circle();
    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl
         << endl;
    p->SetRadius(30);
    // pConstObj->SetRadius(30);
    pConstPtr->SetRadius(30);
    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl;
    return 0;
}