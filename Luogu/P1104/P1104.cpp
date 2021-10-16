#include <bits/stdc++.h>
using namespace std;

struct student
{
	string name;
	short nums[3];
	int ID;
};

int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	student s[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> s[i].name;
		for (int j = 0; j < 3; ++j)
		{
			cin >> s[i].nums[j];
		}
		s[i].ID = i;
	}
	sort(s,s + *n,[=](student s1,student s2){
		if (s1.nums[0] < s2.nums[0])
		{
			return true;
		}
		else if (s1.nums[0] > s2.nums[0])
		{
			return false;
		}
		else
		{
			if (s1.nums[1] < s2.nums[1])
			{
				return true;
			}
			else if (s1.nums[1] > s2.nums[1])
			{
				return false;
			}
			else
			{
				if (s1.nums[2] < s2.nums[2])
				{
					return true;
				}
				else if (s1.nums[2] > s2.nums[2])
				{
					return false;
				}
				else
				{
					if (s1.ID > s2.ID)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	});
	for (int i = 0; i < *n; ++i)
	{
		cout << s[i].name << endl;
	}
	delete n;
	return 0;
}