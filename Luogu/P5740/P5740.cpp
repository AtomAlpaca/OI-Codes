#include <bits/stdc++.h>
using namespace std;

struct student
{
	string name;
	int a,b,c;
	int add;
};


int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	student stu[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> stu[i].name >> stu[i].a >> stu[i].b >> stu[i].c;
		stu[i].add = stu[i].a + stu[i].b + stu[i].c;
	}
	sort(stu,stu + *n,[=](student stu1,student stu2){
		if (stu1.add > stu2.add)
		{
			return true;
		}
		else
		{
			return false;
		}
	});//这么好的东西用的人怎么这么少
	cout << stu[0].name << " " << stu[0].a << " " << stu[0].b << " " << stu[0].c;
	return 0;
}