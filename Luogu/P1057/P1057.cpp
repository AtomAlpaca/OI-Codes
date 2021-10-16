#include <iostream>

using std::cin;
using std::cout;

int m, n;
int f[35][35];

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    f[0][1] = 1;

    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j == 1)
            {
                f[i][j] = f[i - 1][2] + f[i - 1][n];
            }
            else if (j == n)
            {
                f[i][j] = f[i - 1][1] + f[i - 1][n - 1];
            }
            else
            {
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
            }
        }
    }

    cout << f[m][1];
    return 0;
}
