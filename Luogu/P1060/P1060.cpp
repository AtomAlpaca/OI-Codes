#include <iostream>

using std::cin;
using std::cout;

int n, m;
int v[30], p[30], f[30000];

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> v[i] >> p[i];
        p[i] *= v[i];
    }
    

    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= v[i]; --j)
        {
            if (v[i] <= j)
            {
                f[j] = std::max(f[j], f[j - v[i]] + p[i]);
            }
            
        }
    }

    cout << f[n];
    
    return 0;
}
