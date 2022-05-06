#include <iostream>

using std::cin;
using std::cout;

int a[3000005], ans[3000005], sta[3000005];
int top = 1;
int n;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for (int i = n; i >= 1; --i)
	{
		while (top and a[sta[top]] <= a[i])
		{
			sta[top] = 0;
			--top;
		}
		ans[i] = sta[top];
		++top;
		sta[top] = i;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}
