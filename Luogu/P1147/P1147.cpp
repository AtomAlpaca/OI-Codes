#include <iostream>

using std::cin;
using std::cout;

int m, l, r;

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;

    for (int i = 1, max = (m >> 1) + 1; i < max; ++i)
    {
        for (int j = i; j <= m; ++j)
        {
            if ((j * (j + 1) - i * (i - 1)) > (m << 1))
            {
                break;
            }
            else if ((j * (j + 1) - i * (i - 1)) == (m << 1))
            {
                cout << i << ' ' << j << '\n';
                break;
            }    
        }
    }
    return 0;
}
