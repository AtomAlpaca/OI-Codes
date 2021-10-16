#include <iostream>

using std::cin;
using std::cout;

int n, v, c;
int f[10005], w[10005], x[10005];

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> n >> c;

    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> x[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = c; j >= x[i]; --j)
        {
            f[j] = std::max(f[j], f[j - x[i]] + w[i]);
        }
    }

    for (int i = 0; i <= c; i++)
    {
        if (f[i] >= v)
        {
            cout << c - i;
            return 0;
        }
    }
    cout << "Impossible";
    
    return 0;
}
