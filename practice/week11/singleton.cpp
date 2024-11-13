#include <iostream>
using namespace std;
class Camera
{
private:
    Camera() {}
    static Camera *instance;

public:
    int photos = 0;
    static Camera *GetInstance();
    void Capture()
    {
        cout << "사진 촬영이 수행되었음!" << endl;
        photos += 1;
    }
};
Camera *Camera::instance = new Camera();
Camera *Camera::GetInstance()
{
    if (!instance)
    {
        instance = new Camera();
        cout << "첫번째 객체 생성됨" << endl;
        return instance;
    }
    else
    {
        cout << "이전 객체를 반환함" << endl;
        return instance;
    }
}
int main()
{
    Camera *c1 = Camera::GetInstance();
    Camera *c2 = Camera::GetInstance();
    Camera *c3 = Camera::GetInstance();
    c1->Capture();
    c2->Capture();
    cout << c1->photos;
    return 0;
}