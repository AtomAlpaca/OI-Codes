#include <iostream>

using std::cin;
using std::cout;

long long lose[1005], win[1005], use[1005];
long long f[1005];

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> lose[i] >> win[i] >> use[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = x; j >= 0; --j)
        {
            if (j >= use[i])
            {
                f[j] = std::max(f[j] + lose[i], f[j - use[i]] + win[i]);
            }
            else
            {
                f[j] += lose[i];
            }
        }
    }
    
    cout << f[x] * 5;
    return 0;
}
