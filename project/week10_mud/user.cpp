#include "user.h"

User::User() : hp(20) {} // 생성자에서 체력을 20으로 초기화

void User::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
}

void User::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

int User::GetHP() const
{
    return hp;
}
