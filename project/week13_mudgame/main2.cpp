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
void DisplayMap(const vector<vector<int>> &map, int user_x, int user_y);
bool CheckGoal(const vector<vector<int>> &map, int user_x, int user_y);
void CheckState(const vector<vector<int>> &map, int user_x, int user_y, User &user);

int main()
{
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}};

    // 직업 선택
    cout << "직업을 선택하세요 (1: 마법사, 2: 전사): ";
    int choice;
    unique_ptr<User> user;

    while (true)
    {
        cin >> choice;
        if (choice == 1)
        {
            user = make_unique<Magician>();
            cout << "마법사를 선택했습니다." << endl;
            break;
        }
        else if (choice == 2)
        {
            user = make_unique<Warrior>();
            cout << "전사를 선택했습니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 선택입니다. 다시 선택하세요 (1: 마법사, 2: 전사): ";
        }
    }

    // 유저의 위치
    int user_x = 0, user_y = 0;

    while (true)
    {
        cout << "\n체력: " << user->GetHP() << endl;
        string user_input = "";

        cout << "명령어를 입력하세요 (up, down, left, right, map, info, attack, exit): ";
        cin >> user_input;

        if (user_input == "info")
        {
            cout << *user << endl;
        }
        else if (user_input == "attack")
        {
            user->DoAttack();
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
                user->DecreaseHP(1);
                DisplayMap(map, user_x, user_y);
                CheckState(map, user_x, user_y, *user);
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
                user->DecreaseHP(1);
                DisplayMap(map, user_x, user_y);
                CheckState(map, user_x, user_y, *user);
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
                user->DecreaseHP(1);
                DisplayMap(map, user_x, user_y);
                CheckState(map, user_x, user_y, *user);
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
                user->DecreaseHP(1);
                DisplayMap(map, user_x, user_y);
                CheckState(map, user_x, user_y, *user);
            }
        }
        else if (user_input == "map")
        {
            DisplayMap(map, user_x, user_y);
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
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        if (user->GetHP() <= 0)
        {
            cout << "플레이어가 사망했습니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

bool CheckXY(int user_x, int mapX, int user_y, int mapY)
{
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

void DisplayMap(const vector<vector<int>> &map, int user_x, int user_y)
{
    for (int i = 0; i < MAPY; i++)
    {
        for (int j = 0; j < MAPX; j++)
        {
            if (i == user_y && j == user_x)
            {
                cout << " USER |";
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