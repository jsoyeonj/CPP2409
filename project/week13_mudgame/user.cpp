#include "user.h"
UserImpl::UserImpl() : hp(20), itemCnt(0) {}

void UserImpl::DecreaseHP(int dec_hp)
{
    hp = std::max(0, hp - dec_hp);
}

void UserImpl::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

int UserImpl::GetHP() const
{
    return hp;
}

int UserImpl::GetItemCnt() const
{
    return itemCnt;
}

void UserImpl::IncreaseItemCnt()
{
    itemCnt++;
}

// Magician과 Warrior의 구현
void Magician::DoAttack()
{
    std::cout << "마법 사용" << std::endl;
}

void Warrior::DoAttack()
{
    std::cout << "베기 사용" << std::endl;
}