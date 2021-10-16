#include <iostream>

using std::cin;
using std::cout;

int h, n;
int f[45005], s[505];

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = h; j >= s[i]; --j)
        {
            f[j] = std::max(f[j], f[j - s[i]] + s[i]);
        }
    }

    cout << f[h];
    return 0;
}
