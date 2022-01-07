#include <iostream>

using std::cin;;
using std::cout;

long long k, m, min, now, len;
long long power[20],  nums[20];
int main()
{
	cin >> k >> m;
	power[0] = 1;

	for (int i = 1; i <= 20; ++i)
	{
		power[i] = power[i - 1] * 10;
	}

	for (int i = 0; i <= 20; ++i)
	{
		if (k == power[i] and m != i + 1)
		{
			cout << 0;
			return 0;
		}
	}
	
	std::string str;
	str = std::to_string(k);
	len = str.length();

	for (int i = 1; i < len; ++i)
	{
		nums[i] = k / power[(len - i)];
	}

	nums[0] = 0;
	nums[len] = k;

	for (int i = 1; i < 11; ++i)
	{
		if (k < power[i - 1])
		{
			break;
		}
		min += nums[i] - power[i - 1] + 1;
	}

	if (min > m)
	{
		cout << 0;
	}
	else if (min == m)
	{
		cout << k;
	}
	else
	{
		m -= min;
		long long ans = power[len];
		int i = 1;
		while (true)
		{
			long long tmp = k * power[i] - power[len + i - 1];
			if (m > tmp)
			{
				m -= tmp;
				ans *= 10;
				++i;
			}
			else
			{
				break;
			}
		}
		ans += m - 1;
		cout << ans;
	}
	return 0;
}
