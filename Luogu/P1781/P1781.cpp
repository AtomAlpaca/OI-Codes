#include <bits/stdc++.h>
using namespace std;

struct people
{
	string num;
	int ID;
};

int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	people p[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> p[i].num;
		p[i].ID = i + 1;
	}
	sort(p,p + *n,[=](people p1,people p2){
		if (p1.num.length() > p2.num.length())
		{
			return true;
		}
		else if (p1.num.length() < p2.num.length())
		{
			return false;
		}
		else
		{
			for (int i = 0,len = p1.num.length(); i < len; ++i)
			{
				if (p1.num[i] > p2.num[i])
				{
					return true;
				}
				else if (p1.num[i] < p2.num[i])
				{
					return false;
				}
			}
			return false;
		}
	});
	cout << p[0].ID << endl << p[0].num;
	return 0;
}