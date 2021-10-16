#include <iostream>

using std::cin;
using std::cout;

int n, m;
int c[10005], w[10005];
long long f[10000005];

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        cin >> c[i] >> w[i];
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = c[i]; j <= n; ++j)
        {
            f[j] = std::max(f[j], f[j - c[i]] + w[i]); 
        }
    }

    cout << f[n];
    
    
    return 0;
}
