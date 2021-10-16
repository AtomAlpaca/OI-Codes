#include <bits/stdc++.h>
using namespace std;

int getAns(int num)
{
	if (num == 1)
	{
		return 1;
	}
	else if (num == 2)
	{
		return 2;
	}
	return getAns(num - 1) * num;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << getAns(n);
	return 0;
}