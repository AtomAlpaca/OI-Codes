#include <bits/stdc++.h>
using namespace std;

int get(int n1)
{
	return n1 >= 0 ? n1 : -n1;
}

struct student
{
	int num1;
	int num2;
	int num3;
	int add;
};

int main(int argc, char const *argv[])
{
	int * n = new int;
	int ans = 0;
	cin >> *n;
	student stu[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> stu[i].num1 >> stu[i].num2 >> stu[i].num3;
		stu[i].add = stu[i].num1 + stu[i].num2 + stu[i].num3;
		for (int j = i - 1; j >= 0; --j)
		{
			if (get(stu[i].num1 - stu[j].num1) <= 5 and get(stu[i].num2 - stu[j].num2) <= 5 and get(stu[i].num3 - stu[j].num3) <= 5 and get(stu[i].add - stu[j].add) <= 10)
			{
				++ans;
			}
		}
	}
	cout << ans;
	delete n;
	return 0;
}