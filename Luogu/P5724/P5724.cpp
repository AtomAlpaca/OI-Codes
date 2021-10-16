#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,a[101] = {0};
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a,a + n);
	cout << a[n - 1] - a[0];
	return 0;
}