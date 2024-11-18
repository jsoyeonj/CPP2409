#ifndef USER_H
#define USER_H

#include <iostream>

class User
{
private:
    int hp;
    int itemCnt; // 아이템 개수를 저장하는 새로운 멤버 변수

public:
    User(); // 체력을 20으로, itemCnt를 0으로 설정하는 생성자

    // 기존 멤버 함수들
    void DecreaseHP(int dec_hp); // 체력을 감소시키는 함수
    void IncreaseHP(int inc_hp); // 체력을 증가시키는 함수
    int GetHP() const;           // 현재 체력을 반환하는 함수

    // 새로 추가되는 멤버 함수들
    int GetItemCnt() const; // 현재 아이템 개수를 반환하는 함수
    void IncreaseItemCnt(); // 아이템 개수를 증가시키는 함수

    // 출력 연산자 중복 정의를 위한 friend 함수 선언
    friend std::ostream &operator<<(std::ostream &os, const User &user);
};

// 출력 연산자 중복 정의
inline std::ostream &operator<<(std::ostream &os, const User &user)
{
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다";
    return os;
}

#endif
