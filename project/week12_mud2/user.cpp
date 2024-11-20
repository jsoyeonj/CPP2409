#include "user.h"

User::User() : hp(20), itemCnt(0) {}

void User::DecreaseHP(int dec_hp)
{
    hp = std::max(0, hp - dec_hp);
}

void User::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

int User::GetHP() const
{
    return hp;
}

int User::GetItemCnt() const
{
    return itemCnt;
}

void User::IncreaseItemCnt()
{
    itemCnt++;
}
void User::DoAttack()
{
    std::cout << "공격합니다" << std::endl;
}
void Magician::DoAttack()
{
    std::cout << "마법 사용" << std::endl;
}

void Warrior::DoAttack()
{
    std::cout << "베기 사용" << std::endl;
}