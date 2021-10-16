#include <algorithm>
#include <iostream>
#include <queue>

using std::cout;
using std::cin;

int main(int argc, char const *argv[])
{
    int m, n, s, ans = 0;
    cin >> m >> n;

    std::queue<int> mem;
    bool flag[1005] = {false};
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        if (flag[s] == false)
        {
            
            mem.push(s);
            flag[s] = true;
            if (mem.size() > m)
            {
                flag[mem.front()] = false;
                mem.pop();
            }
            ++ans;
        }
    }
    
    cout << ans;
    return 0;
}
