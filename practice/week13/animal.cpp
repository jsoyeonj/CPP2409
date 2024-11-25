#include <iostream>
using namespace std;
class Animal
{
public:
    void Speak() { cout << "Animal speak()" << endl; }
};
class Dog : public Animal
{
public:
    int age;
    void Speak() { cout << "멍멍" << endl; }
};
class Cat : public Animal
{
public:
    void Speak() { cout << "야옹" << endl; }
};
int main()
{
    // new를 통해 동적 객체를
    // 생성했으므로 포인터로 받음
    Animal *a1 = new Dog();
    a1->Speak();
    // 오류!! 상향 형변환 시
    // Dog 복사되서 Animal에 전달되며 정보 잘림
    // 객체 슬라이싱 (slicing) 이라고 함.
    // a1->age = 10;
    Animal a2 = Cat();
    // a2->speak(); // 오류! 포인터가 아니니까
    a2.Speak();
    delete a1;
    return 0;
}