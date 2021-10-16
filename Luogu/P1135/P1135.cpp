#include <iostream>

using std::cin;
using std::cout;

bool flag = false;
int a, b, n, ans = 0;
int f[205], k[205], g[205];

int main(int argc, char const *argv[])
{
    cin >> n >> a >> b;

    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        if ((i + k[i] == n or i - k[i] == n) and k[i] != 0)
        {
            flag = true;
        }
    }

    if (flag == false)
    {
        cout << -1;
        return 0;
    }
    
    f[a] = 1;

    while (f[b] == 0)
    {
        ++ans;
        for (int i = 1; i <= n; ++i)
        {
            if (i - k[i] > 0)
            {
                g[i - k[i]] += f[i];
            }
            if (i + k[i] <= n)
            {
                g[i + k[i]] += f[i];
            }
            
        }
        for (int i = 1; i <= n; ++i)
        {
            f[i] += g[i];
            g[i] = 0;
            //cout << f[i] << ' ';
        }
        //cout << '\n';
    }
    
    cout << ans;
    return 0;
}
