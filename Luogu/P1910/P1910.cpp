#include <iostream>

using std::cin;
using std::cout;

int n, m, x;
int cb[105], cc[105], w[105];
int f[1005][1005];

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i] >> cb[i] >> cc[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = m; j >= cb[i]; --j)
        {
            for (int k = x; k >= cc[i]; --k)
            {
                f[j][k] = std::max(f[j][k], f[j - cb[i]][k - cc[i]] + w[i]);
            }
        }
    }

    cout << f[m][x];
    return 0;
}
