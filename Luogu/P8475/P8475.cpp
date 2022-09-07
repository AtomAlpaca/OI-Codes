#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 10000005; // Set a right value according to your solution.
long long n;
int a[MAXN];
int t[MAXN];

namespace Generator {

unsigned long long k1, k2;
int thres;

inline unsigned long long xorShift128Plus() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4, k3 ^= (k3 << 23), k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

inline void generate() {
    for (int i = 1; i <= n; ++i) {
        a[i] = xorShift128Plus() % thres;
    }
}

}

void init(int n)
{
	a[0] = 2147483647;
	t[n] = n;
	for (int i = n - 1; i >= 1; --i)
	{
		if (a[i] < a[t[i + 1]])
		{
			t[i] = i;
		}
		else
		{
			t[i] = t[i + 1];
		}
	}
}

void solve()
{
	int o = 1;
	while (true)
	{
		if (o >= n)
		{
			return ;
		}
		if (a[o] <= a[t[o + 1]])
		{
			++o;
		}
		else
		{
			std::swap(a[o], a[t[o + 1]]);
			o = t[o + 1] + 1;
		}
	}
}

unsigned long long cal()
{
	unsigned long long ans = 0;
	for (unsigned long long i = 1; i <= n; ++i)
	{
		ans += (unsigned long long)(a[i]) * i;
	}
	return ans;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
    
	cin >> n >> Generator::k1 >> Generator::k2 >> Generator::thres;
    Generator::generate();

	init(n);
	solve();
	cout << cal();

    return 0;
}

