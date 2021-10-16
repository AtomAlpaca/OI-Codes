#include <iostream>
using namespace std;

bool isPr(long long num)
{
	if (num % 2 == 0)
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

void printAns(long long ans1,long long ans2)
{
	if (ans1 > ans2)
	{
		cout << ans1;
	}
	else
	{
		cout << ans2;
	}
	return;
}

int main(int argc, char const *argv[])
{
	long long n;
	cin >> n;
	long long ans1,ans2;
	if (n % 2 == 0)
	{
		ans1 = 2;
		ans2 = n / 2;
		printAns(ans1,ans2);
		return 0;
	}
	for (long long i = 5; i < n; i += 2)
	{
		if (n % i == 0 and isPr(i) == true)
		{
			ans1 = i;
			break;
		}
	}
	ans2 = n / ans1;
	printAns(ans1,ans2);
	return 0;
}