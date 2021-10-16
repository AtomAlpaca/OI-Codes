#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	int * m = new int;
	cin >> n >> *m;
	int nums[*m];
	for (int i = 0; i < *m; ++i)
	{
		cin >> nums[i];
	}
	sort(nums,nums + *m);
	for (int i = 0; i < *m; ++i)
	{
		cout << nums[i] << " ";
	}
	delete m;
	return 0;
}