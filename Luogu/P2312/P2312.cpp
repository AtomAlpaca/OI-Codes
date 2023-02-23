#include <iostream>

using std::cin;
using std::cout;

const int MAX = 105;
const int MOD = 1e9 + 7;

long long n, m, cnt;
long long a[MAX], ans[MAX];

template<typename T>void read(T &a)
{
    T x=0,f=1;char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')f=0;ch=getchar();
    }
    while(isdigit(ch))
    {
        x=((x<<1)%MOD+(x<<3)%MOD+ch-'0')%MOD;ch=getchar();
    }
    a=f?x:-x;
}

bool judge(long long x)
{
	long long sum = 0;
	for (int i = n; i > 0; --i)
	{
		sum = (sum + a[i]) * x;
		sum %= MOD;
	}
	sum += a[0];
	sum %= MOD;
	return (!sum);
}

int main()
{


	cin >> n >> m;
	for (int i = 0; i <= n; ++i)
	{
		read(a[i]);
	}

	for (int i = 1; i <= m; ++i)
	{
		if (judge(i))
		{
			++cnt;
			ans[cnt] = i;
		}
	}

	cout << cnt << '\n';

	for (int i = 1; i <= cnt; ++i)
	{
		cout << ans[i] << '\n';
	}
}
