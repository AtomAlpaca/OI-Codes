#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int INF = 0x3f3f3f3f;

struct Item
{
    int c, w;
};

std::vector <Item> a[65];

int c, w, t, m, n, ans = -1, f[50005];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

	for (int i = 1; i <= m; ++i)
	{
		f[i] = -INF;
	}

    for (int i = 1; i <= m; ++i)
    {
        cin >> c >> w >> t;
        Item item = {c, c * w};
        if (t == 0)
        {
			a[i].insert(a[i].begin(), item);
        }
        else
        {
            a[t].push_back(item);
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        const int len = a[i].size();
        if (len == 0)
        {
            continue;        
        }
        for (int j = n; j >= 0; --j)
        {
            if (j >= a[i].at(0).c)
            {
                f[j] = std::max(f[j], f[j - a[i].at(0).c] + a[i].at(0).w);
                if ((len == 2 or len == 3) and j >= a[i].at(1).c + a[i].at(0).c)
                {
                    f[j] = std::max(f[j], f[j - a[i].at(1).c - a[i].at(0).c] 
                                  + a[i].at(1).w + a[i].at(0).w);
                }
                if (len == 3 and j >= a[i].at(2).c + a[i].at(0).c)
                {
                    f[j] = std::max(f[j], f[j - a[i].at(2).c - a[i].at(0).c]
                                  + a[i].at(2).w + a[i].at(0).w);
                }
                if (len == 3 and j >= a[i].at(2).c + a[i].at(1).c + a[i].at(0).c)
                {
                   f[j] = std::max(f[j], f[j - a[i].at(2).c - a[i].at(1).c - a[i].at(0).c]
                                  + a[i].at(2).w + a[i].at(1).w + a[i].at(0).w);
                }
            }
        }
    }

    for (int i = 0; i <= n; ++i)
    {
    	ans = std::max(ans, f[i]);
	}
	
	cout << ans;
    return 0;
}
