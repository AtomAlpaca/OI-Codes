#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

struct node
{
    long long a, b, c;
} nodes[55];

inline bool cmp(node n1, node n2)
{
    return n1.c * n2.b < n2.c * n1.b;
}

long long ans;
long long f[100005];


int main(int argc, char const *argv[])
{
    long long T, n;

    cin >> T >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> nodes[i].a;
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> nodes[i].b;
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> nodes[i].c;
    }

    std::sort(nodes + 1, nodes + n + 1, cmp);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = T; (j >= 0); --j)
        {
            if (j + nodes[i].c <= T)
            {
                f[j + nodes[i].c] = std::max(f[j + nodes[i].c], f[j] + nodes[i].a - nodes[i].b * (j + nodes[i].c));
            }
        }
    }

    for (int i = 0; i <= T; ++i)
    {
        // if (f[i] != 0)
        // {
        //     //cout << f[i] << '\n';
        // }
        ans = std::max(ans, f[i]);
    }

    cout << ans;
    return 0;
}
