#include <bits/stdc++.h>
using namespace std;
int n,ans;
int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int * a = new int;
		scanf("%d",&(*a));
		ans ^= (*a);
		delete a;
	}
	printf("%d",ans);
	return 0;
}