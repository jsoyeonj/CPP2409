#include <iostream>
#include <string>
using namespace std;
class Dog
{
private:
    int *pWeight;
    int *pAge;

public:
    Dog()
    {
        pAge = new int(1);
        pWeight = new int(10);
    }
    ~Dog()
    {
        delete pAge;
        delete pWeight;
    }
    int GetAge() { return *pAge; }
    void SetAge(int age) { *pAge = age; }
    int GetWeight() { return *pWeight; }
    void SetWeight(int weight) { *pWeight = weight; }
};
int main()
{
    Dog *pDog = new Dog;
    cout << "강아지의 나이:" << pDog->GetAge() << endl;
    pDog->SetAge(5);
    cout << "강아지의 나이:" << pDog->GetAge() << endl;
    delete pDog;
    return 0;
}