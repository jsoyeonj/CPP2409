#include "user.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

const int MAPX = 5;
const int MAPY = 5;

// 사용자 정의 함수
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(const vector<vector<int>> &map, int mag_x, int mag_y, int war_x, int war_y);
bool CheckGoal(const vector<vector<int>> &map, int user_x, int user_y);
void CheckState(const vector<vector<int>> &map, int user_x, int user_y, User &user);
bool CheckUsers(const User &magician, const User &warrior);

int main()
{
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}};

    // 두 유저 생성
    unique_ptr<User> magician = make_unique<Magician>();
    unique_ptr<User> warrior = make_unique<Warrior>();

    // 각 유저의 위치
    int mag_x = 0, mag_y = 0; // 마법사 위치
    int war_x = 0, war_y = 0; // 전사 위치

    int current_player = 0; // 0: 마법사, 1: 전사

    while (true)
    {
        User &currentUser = (current_player == 0) ? *magician : *warrior;
        int &user_x = (current_player == 0) ? mag_x : war_x;
        int &user_y = (current_player == 0) ? mag_y : war_y;

        cout << "\n현재 플레이어: " << (current_player == 0 ? "마법사" : "전사") << endl;
        cout << "마법사 체력: " << magician->GetHP() << " | 전사 체력: " << warrior->GetHP() << endl;
        string user_input = "";

        cout << "명령어를 입력하세요 (up, down, left, right, map, info, attack, exit): ";
        cin >> user_input;

        if (user_input == "info")
        {
            cout << currentUser << endl;
        }
        else if (user_input == "attack")
        {
            currentUser.DoAttack();
        }
        else if (user_input == "up")
        {
            user_y -= 1;
            bool inMap = CheckXY(user_x, MAPX, user_y, MAPY);
            if (!inMap)
            {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            }
            else
            {
                cout << "위로 한 칸 올라갑니다." << endl;
                currentUser.DecreaseHP(1);
                DisplayMap(map, mag_x, mag_y, war_x, war_y);
                CheckState(map, user_x, user_y, currentUser);
            }
        }
        else if (user_input == "down")
        {
            user_y += 1;
            bool inMap = CheckXY(user_x, MAPX, user_y, MAPY);
            if (!inMap)
            {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            }
            else
            {
                cout << "아래로 한 칸 이동합니다." << endl;
                currentUser.DecreaseHP(1);
                DisplayMap(map, mag_x, mag_y, war_x, war_y);
                CheckState(map, user_x, user_y, currentUser);
            }
        }
        else if (user_input == "left")
        {
            user_x -= 1;
            bool inMap = CheckXY(user_x, MAPX, user_y, MAPY);
            if (!inMap)
            {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            }
            else
            {
                cout << "왼쪽으로 이동합니다." << endl;
                currentUser.DecreaseHP(1);
                DisplayMap(map, mag_x, mag_y, war_x, war_y);
                CheckState(map, user_x, user_y, currentUser);
            }
        }
        else if (user_input == "right")
        {
            user_x += 1;
            bool inMap = CheckXY(user_x, MAPX, user_y, MAPY);
            if (!inMap)
            {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            }
            else
            {
                cout << "오른쪽으로 이동합니다." << endl;
                currentUser.DecreaseHP(1);
                DisplayMap(map, mag_x, mag_y, war_x, war_y);
                CheckState(map, user_x, user_y, currentUser);
            }
        }
        else if (user_input == "map")
        {
            DisplayMap(map, mag_x, mag_y, war_x, war_y);
        }
        else if (user_input == "exit")
        {
            cout << "종료합니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        bool finish = CheckGoal(map, user_x, user_y);
        if (finish)
        {
            cout << (current_player == 0 ? "마법사" : "전사") << "가 목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        if (!CheckUsers(*magician, *warrior))
        {
            if (magician->GetHP() <= 0 && warrior->GetHP() <= 0)
                cout << "두 플레이어 모두 사망했습니다!" << endl;
            else if (magician->GetHP() <= 0)
                cout << "마법사가 사망했습니다!" << endl;
            else
                cout << "전사가 사망했습니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        current_player = (current_player + 1) % 2;
    }
    return 0;
}

bool CheckUsers(const User &magician, const User &warrior)
{
    return magician.GetHP() > 0 && warrior.GetHP() > 0;
}

bool CheckXY(int user_x, int mapX, int user_y, int mapY)
{
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

void DisplayMap(const vector<vector<int>> &map, int mag_x, int mag_y, int war_x, int war_y)
{
    for (int i = 0; i < MAPY; i++)
    {
        for (int j = 0; j < MAPX; j++)
        {
            // 같은 위치에 있는 경우
            if (i == mag_y && j == mag_x && i == war_y && j == war_x)
            {
                cout << " M&W  |";
            }
            // 마법사 위치
            else if (i == mag_y && j == mag_x)
            {
                cout << "  M   |";
            }
            // 전사 위치
            else if (i == war_y && j == war_x)
            {
                cout << "  W   |";
            }
            else
            {
                int posState = map[i][j];
                switch (posState)
                {
                case 0:
                    cout << "      |";
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |";
                    break;
                case 3:
                    cout << " 포션 |";
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

void CheckState(const vector<vector<int>> &map, int user_x, int user_y, User &user)
{
    int posState = map[user_y][user_x];
    if (posState == 2)
    {
        cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
        user.DecreaseHP(2);
    }
    else if (posState == 1)
    {
        cout << "아이템이 있습니다." << endl;
        user.IncreaseItemCnt();
    }
    else if (posState == 3)
    {
        cout << "포션이 있습니다. HP가 2 증가합니다." << endl;
        user.IncreaseHP(2);
    }
}

bool CheckGoal(const vector<vector<int>> &map, int user_x, int user_y)
{
    return map[user_y][user_x] == 4;
}