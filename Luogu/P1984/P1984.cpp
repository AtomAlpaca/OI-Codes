#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

int n;
double ans, cost;

int main()
{
	cin >> n;
	
	cost = double(double(4200 * 100) / n);
	ans += cost;

	for (int i = 1; i < n; ++i)
	{
		cost *= double(double(2 * i - 1) / double(2 * i));
		ans += cost;
	}
	
	cout << std::fixed << std::setprecision(2) << ans;
	return 0;
}
