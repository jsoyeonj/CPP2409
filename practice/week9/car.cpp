#include <iostream>
#include <string>
using namespace std;
class Car
{
public:
    // 멤버 변수 선언
    int speed;    // 속도
    int gear;     // 기어
    string color; // 색상

    // 멤버 함수 선언
    void SpeedUp()
    { // 속도 증가 멤버 함수
        speed += 10;
    }
    void SpeedDown()
    { // 속도 감소 멤버 함수
        speed -= 10;
    }
};
int main()
{
    Car myCar;
    myCar.speed = 100;
    myCar.gear = 3;
    myCar.color = "red";
    cout << "1st speed: " << myCar.speed << endl;
    myCar.SpeedUp();
    cout << "2nd speed: " << myCar.speed << endl;
    myCar.SpeedDown();
    cout << "3rd speed: " << myCar.speed << endl;
    return 0;
}