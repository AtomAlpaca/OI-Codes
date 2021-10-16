#include <bits/stdc++.h>
using namespace std;

bool isPr(int num)
{
	if (num == 2 or num == 3)
	{
		return true;
	}
	else if (num == 1 or num == 0 or num % 2 == 0)
	{
		return false;
	}
	else
	{
		for (int i = 3; i * i <= num; i += 2)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	int nums[*n];
	bool flag[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
		flag[i] = isPr(nums[i]);
		if (flag[i] == true)
		{
			cout << nums[i] << " ";
		}
	}
	delete n;
	return 0;
}