#include <bits/stdc++.h>
using namespace std;

bool isPr(int num)
{
	if (num == 2 or num == 3)
	{
		return true;
	}
	if (num % 2 == 0 or num == 1)
	{
		return false;
	}
	for (int i = 3; i * i <= num; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

void printAns(int num)
{
	for (int i = 2; i < num; ++i)
	{
		if (isPr(i) and isPr(num - i))
		{
			cout << num << "=" << i << "+" << (num - i) << endl;
			break;
		}
	}
}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 4; i <= n; i += 2)
	{
		printAns(i);
	}
	return 0;
}