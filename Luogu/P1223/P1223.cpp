#include <bits/stdc++.h>

using std::cout;
using std::cin;

struct students
{
	int id;
	int time;
};


int main()
{
	int * n = new int;
	cin >> *n;
	students nums[*n];
	double ans = 0;

	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i].time;
		nums[i].id = i + 1;
	}

	std::sort(nums, nums + (*n), [=](students stu1, students stu2){
		return stu1.time < stu2.time;
	});

	for (int i = 0; i < *n; ++i)
	{
		cout << nums[i].id << " ";
		ans += nums[i].time * (*n - i - 1);		
	}
	cout << std::endl;

	ans /= (*n);

	printf("%.2f", ans);
	delete n;
	return 0;
}
