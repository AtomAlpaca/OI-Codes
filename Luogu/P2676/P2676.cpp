#include <bits/stdc++.h>

using std::cin;
using std::cout;

int main()
{
	int * n = new int;
	int heigth;
	cin >> *n >> heigth;
	int cowHeigth[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> cowHeigth[i];
	}
	std::sort(cowHeigth, cowHeigth + *n, [=](int numa,int numb){
		return numa > numb;
	});
	int sum = 0;
	int ans = 0;
	while (heigth >= 0)
	{
		heigth -= cowHeigth[sum];
		++ans;
		++sum;
	}
	cout << ans;
	return 0;
}
