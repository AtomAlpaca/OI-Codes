#include <iostream>

using std::cin;
using std::cout;

int n, M, T;

int m[105], t[105];

int f[205][205];

int main(int argc, char const *argv[])
{
    cin >> n >> M >> T;

    for (int i = 0; i < n; ++i)
    {
        cin >> m[i] >> t[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = M; j >= m[i]; --j)
        {
            for (int k = T; k >= t[i]; --k)
            {
                f[j][k] = std::max(f[j][k], f[j - m[i]][k - t[i]] + 1);
            }
        }
    }
    cout << f[M][T];
    return 0;
}
