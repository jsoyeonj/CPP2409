class User
{
private:
    int hp;

public:
    User();                      // 체력을 20으로 설정하는 생성자
    void DecreaseHP(int dec_hp); // 체력을 감소시키는 함수
    void IncreaseHP(int inc_hp); // 체력을 증가시키는 함수
    int GetHP() const;           // 현재 체력을 반환하는 함수
};
