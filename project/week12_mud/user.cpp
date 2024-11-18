#include "user.h"

// 생성자 - hp를 20으로, itemCnt를 0으로 초기화
User::User() : hp(20), itemCnt(0) {}

// HP 감소 함수
void User::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
}

// HP 증가 함수
void User::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

// HP 가져오기
int User::GetHP() const
{
    return hp;
}

// 아이템 개수 가져오기
int User::GetItemCnt() const
{
    return itemCnt;
}

// 아이템 개수 증가
void User::IncreaseItemCnt()
{
    itemCnt++;
}