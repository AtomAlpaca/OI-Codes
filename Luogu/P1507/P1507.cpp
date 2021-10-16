#include <iostream>

using std::cin;
using std::cout;

int a, b, n;
int v[55], ca[55], cb[55];
int f[405][405];

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b
        >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> ca[i] >> cb[i] >> v[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = a; j > 0; --j)
        {
            for (int k = b; k > 0; --k)
            {
                if (j >= ca[i] and k >= cb[i])
                {
                    f[j][k] = std::max(f[j][k], f[j - ca[i]][k - cb[i]] + v[i]);
                }
            }
        }
    }

    cout << f[a][b];
    return 0;
}
