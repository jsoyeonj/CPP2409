#include <iostream>
#include <vector>
using namespace std;
template <typename T>
T add(T x, T y)
{
    return x + y;
}
vector<int> add(vector<int> &vec1, vector<int> &vec2)
{
    vector<int> result;
    result.reserve(vec1.size() + vec2.size());
    for (const int &item : vec1)
    {
        result.push_back(item);
    }
    for (const int &item : vec2)
    {
        result.push_back(item);
    }
    return result;
}
int main()
{
    int x = 100, y = 200;
    cout << add(x, y) << endl;
    vector<int> s1 = {1, 2, 3};
    vector<int> s2 = {4, 5, 6};
    vector<int> s3 = add(s1, s2);
    for (auto &item : s3)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
