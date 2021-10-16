#include <bits/stdc++.h>
using namespace std;

struct student
{
	int nums[3];
	int add = 0;
	int ID;
};

int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	student s[*n];
	for (int i = 0; i < *n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> s[i].nums[j];
			s[i].add += s[i].nums[j];
		}
		s[i].ID = i + 1;
	}
	sort(s,s + *n,[=](student s1,student s2){
		if (s1.add > s2.add)
		{
			return true;
		}
		else if (s1.add == s2.add)
		{
			if (s1.nums[0] > s2.nums[0])
			{
				return true;
			}
			else if (s1.nums[0] == s2.nums[0])
			{
				return s1.ID < s2.ID ? true : false;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;//我家编译器老警告，所有加上了这一句😂
	});
	for (int i = 0; i < 5; ++i)
	{
		cout << s[i].ID << " " << s[i].add << endl;
	}
	delete n;
	return 0;
}