#include <iostream>

using std::cin;
using std::cout;

int m, n, ca, mc;
int a[1005], b[1005], f[1005], c[105][25];

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i] >> ca;
        ++c[ca][0];
        c[ca][c[ca][0]] = i;
        mc = std::max(mc, ca);
    }

    // for (int i = 1; i <= mc; ++i)
    // {
    //     cout << c[i][0] << ' ' << i << '\n';
    // }

    for (int i = 1; i <= mc; ++i)
    {
        for (int j = m; j >= 0; --j)
        {
            for (int k = 1; k <= c[i][0]; ++k)
            {
                if (j >= a[c[i][k]])
                {
                    f[j] = std::max(f[j], f[j - a[c[i][k]]] + b[c[i][k]]);
                }
            }
        }
    }

    cout << f[m];
    return 0;
}
