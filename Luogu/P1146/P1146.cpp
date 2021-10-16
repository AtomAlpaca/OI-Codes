#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	bool flag[100] = {false};
	cout << n << endl;
	for (int i = 0; i < n; ++i)
	{
		flag[i] = !flag[i];
		for (int j = 0; j < n; ++j)
		{
			flag[j] = !flag[j];
			cout << flag[j];
		}
		cout << endl;
	}
	return 0;
}