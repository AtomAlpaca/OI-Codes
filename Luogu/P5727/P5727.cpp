#include <iostream>
using namespace std;

bool is(int num)
{
	if (num % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int ansNum = n;
	int ans[1000];
	int i = 0;
	while (n != 1)
	{
		if (is(n))
		{
			n /= 2;
			ans[i] = n;
		}
		else
		{
			n *= 3;
			n += 1;
			ans[i] = n;
		}
		++i;
	}
	--i;
	for (; i >= 0; --i)
	{
		cout << ans[i] << " ";
	}
	cout << ansNum;
	return 0;
}