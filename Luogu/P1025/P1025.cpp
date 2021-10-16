#include <iostream>

using std::cin;
using std::cout;

int f[205][8];

int main(int argc, char const *argv[])
{
    int n, k;

    cin >> n >> k;

    for (int i = 0; i <= n; ++i)
    {
        f[i][1] = 1;
        f[i][0] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= k; ++j)
        {
            f[i][j] = f[i - 1][j - 1];
            if (i > j)
            {
                f[i][j] += f[i - j][j];
            }
        }
    }

    cout << f[n][k];
    return 0;
}
