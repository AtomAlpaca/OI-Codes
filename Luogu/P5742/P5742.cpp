#include <bits/stdc++.h>
using namespace std;

struct student
{
	int ID;
	double numa,numb;
	bool flag;
};

int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	student stu[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> stu[i].ID >> stu[i].numa >> stu[i].numb;
		if (stu[i].numa + stu[i].numb > 140 and stu[i].numa * 0.7 + stu[i].numb * 0.3 >= 80)
		{
			stu[i].flag = true;
		}
		else
		{
			stu[i].flag = false;
		}
	}
	for (int i = 0; i < *n; ++i)
	{
		if (stu[i].flag == true)
		{
			cout << "Excellent" << endl;
		}
		else
		{			
			cout << "Not excellent" << endl;
		}
	}
	delete n;
	return 0;
}