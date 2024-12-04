#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> my_list = {10, 20, 30, 40};
    auto it = my_list.begin();
    it++;
    it++;
    my_list.insert(it, 25);
    for (auto &n : my_list)
        cout << n << " ";
    cout << endl;
    return 0;
}