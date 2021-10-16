#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;

int Tsh, Tsm, Teh, Tem, T, n;

int t[10005], c[10005], p[10005], f[1005];

int main(int argc, char const *argv[])
{
    char * ch = new char;
    scanf("%d:%d %d:%d", &Tsh, &Tsm, &Teh, &Tem);
    T = Tem - Tsm + (Teh - Tsh) * 60;

    delete ch;
    //cout << Teh << Tem << Tsh << Tsm << ' ';
    //cout << T << '\n';
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] >> c[i] >> p[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (p[i] == 0) //完全
        {
            for (int j = t[i]; j <= T; ++j)
            {
                f[j] = std::max(f[j], f[j - t[i]] + c[i]);
            }
        }
        else if (p[i] == 1) //01
        {
            for (int j = T; j >= t[i]; --j)
            {
                f[j] = std::max(f[j], f[j - t[i]] + c[i]);
            }
        }
        else //多重
        {
            for (int a = 0; a < p[i]; ++a)
            {
                for (int j = T; j >= (a + 1) * t[i]; --j)
                {
                    f[j] = std::max(f[j], f[j - t[i]] + c[i]);
                }
            }
        }
    }

    cout << f[T];
    return 0;
}
