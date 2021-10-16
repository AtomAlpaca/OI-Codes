#include <iostream>

using std::cout;
using std::cin;

int r[205][205];
int f[205];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            cin >> r[i][j];
        }
        f[i] = 2 << 16;
    }

    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            f[i] = std::min(f[i], f[j] + r[i][j]);
        }
    }

    cout << f[1];
    return 0;
}
