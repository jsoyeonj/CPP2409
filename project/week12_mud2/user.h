#ifndef USER_H
#define USER_H

#include <iostream>

class User
{
protected:
    int hp;
    int itemCnt;

public:
    User(); // 생성자
    virtual ~User() = default;

    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;
    int GetItemCnt() const;
    void IncreaseItemCnt();

    virtual void DoAttack();

    friend std::ostream &operator<<(std::ostream &os, const User &user);
};

inline std::ostream &operator<<(std::ostream &os, const User &user)
{
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다";
    return os;
}

// Magician 클래스
class Magician : public User
{
public:
    Magician() : User() {}
    void DoAttack() override;
};

// Warrior 클래스
class Warrior : public User
{
public:
    Warrior() : User() {}
    void DoAttack() override;
};

#endif