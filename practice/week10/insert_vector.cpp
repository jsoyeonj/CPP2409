#include <vector>
#include <iostream>
using namespace std;
int main(void)
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    cout << "현재의 v = ";
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    // it의 타입은 vector<int>::iterator
    auto it = v.begin() + 5;
    v.insert(it, 100);
    cout << "5번 인덱스에 값을 추가한 후 v = ";
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    return 0;
}
