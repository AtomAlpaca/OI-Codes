#include <bits/stdc++.h>
using namespace std;

struct mountain
{
	int nums[3];
};

double getAns(mountain m1,mountain m2)
{
	return sqrt(pow((m1.nums[0] - m2.nums[0]),2) + pow((m1.nums[1] - m2.nums[1]),2) + pow((m1.nums[2] - m2.nums[2]),2));
}

int main(int argc, char const *argv[])
{
	double ans = 0;
	int * n = new int;
	cin >> *n;
	mountain m[*n];
	for (int i = 0; i < *n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> m[i].nums[j];
		}
	}
	sort(m,m + *n,[=](mountain m1,mountain m2){
		return m1.nums[2] < m2.nums[2];
	});
	for (int i = 0; i < (*n - 1); ++i)
	{
		ans += getAns(m[i],m[i + 1]);
	}
	printf("%.3f",ans);
	return 0;
}