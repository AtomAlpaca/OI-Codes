#include <bits/stdc++.h>

using std::cin;
using std::cout;

double a, b, c, d, sum;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> a >> b >> c >> d;
	
	for (double x = -100.0; x <= 100.0; x += 0.01)
	{
		if (a * x * x * x + b * x * x + c * x + d <= 0.001
		and a * x * x * x + b * x * x + c * x + d >= -0.001)
		{
			cout << std::fixed << std::setprecision(2) << x << ' ';
			++sum;
		}
		if (sum == 3)
		{
			break;
		}
	}
	
	return 0;
}
