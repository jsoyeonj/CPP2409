#include <iostream>
using namespace std;
// 리모컨 인터페이스 정의
class RemoteControl
{
public:
    // 순수 가상 함수 정의
    virtual void TurnON() = 0;  // 가전 제품을 켠다.
    virtual void TurnOFF() = 0; // 가전 제품을 끈다.
    virtual ~RemoteControl() = default;
};
// TV 클래스 정의
class Television : public RemoteControl
{
public:
    void TurnON() override
    {
        cout << "TV를 켭니다" << endl;
    }
    void TurnOFF() override
    {
        cout << "TV를 끕니다" << endl;
    }
};
// 냉장고 클래스 정의
class Refrigerator : public RemoteControl
{
public:
    void TurnON() override
    {
        cout << "냉장고를 켭니다." << endl;
    }
    void TurnOFF() override
    {
        cout << "냉장고를 끕니다." << endl;
    }
};
int main()
{
    // TV를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl *remoteTV = new Television();
    remoteTV->TurnON();  // TV를 켬
    remoteTV->TurnOFF(); // TV를 끔
    // 냉장고를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl *remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnON();  // 냉장고를 켬
    remoteRefrigerator->TurnOFF(); // 냉장고를 끔
    delete remoteTV, remoteRefrigerator;
    return 0;
}