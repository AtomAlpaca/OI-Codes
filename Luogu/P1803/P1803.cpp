#include <bits/stdc++.h>

using std::cin;
using std::cout;

struct competition
{
	int startTime;
	int endTime;
};

int main()
{
	int * n = new int;
	cin >> *n;
	competition comp[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> comp[i].startTime >> comp[i].endTime;
	}

	std::sort(comp, comp + *n, [=](competition c1, competition c2){
		if (c1.endTime < c2.endTime)
		{
			return true;
		}
		else if (c1.endTime == c2.endTime)
		{
			return c1.startTime > c2.startTime;
		}
		return false;
	});

	int ans = 0, last = 0;
	for (int i = 0; i < *n; ++i)
	{
		if (last <= comp[i].startTime)
		{
			++ans;
			last = comp[i].endTime;
		}
	}
	cout << ans;

	delete n;
	return 0;
}
