#ifndef USER_H
#define USER_H

#include <iostream>

class User
{
public:
    virtual ~User() = default;

    virtual void DecreaseHP(int dec_hp) = 0;
    virtual void IncreaseHP(int inc_hp) = 0;
    virtual int GetHP() const = 0;
    virtual int GetItemCnt() const = 0;
    virtual void IncreaseItemCnt() = 0;
    virtual void DoAttack() = 0;

    friend std::ostream &operator<<(std::ostream &os, const User &user);
};

class UserImpl : public User
{
protected:
    int hp;
    int itemCnt;

public:
    UserImpl();

    void DecreaseHP(int dec_hp) override;

    void IncreaseHP(int inc_hp) override;

    int GetHP() const override;
    int GetItemCnt() const override;

    void IncreaseItemCnt() override;

    virtual void DoAttack() override = 0;
};

class Magician : public UserImpl
{
public:
    void DoAttack() override;
};

class Warrior : public UserImpl
{
public:
    void DoAttack() override;
};

inline std::ostream &operator<<(std::ostream &os, const User &user)
{
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다";
    return os;
}

#endif
