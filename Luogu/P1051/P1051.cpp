#include <bits/stdc++.h>
using std::cin;
using std::cout;

struct student
{
	std::string name;
	int finaScore;
	int clasScore;
	char isOffic;
	char isWest;
	int paperNum;
	int money;
	int id;
};

int getMoney(student stu)
{
	int	ans = 0;
	if (stu.finaScore > 80 and stu.paperNum >= 1)
	{
		ans += 8000;
	}
	if (stu.finaScore > 85 and stu.clasScore > 80)
	{
		ans += 4000;
	}
	if (stu.finaScore > 90)
	{
		ans += 2000;
	}
	if (stu.finaScore > 85 and stu.isWest == 'Y')
	{
		ans += 1000;
	}
	if (stu.clasScore > 80 and stu.isOffic == 'Y')
	{
		ans += 850;
	}
	return ans;
}

int main()
{
	int * n = new int;
	int ans = 0;
	cin >> *n;
	student stu[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> stu[i].name 
		>> stu[i].finaScore 
		>> stu[i].clasScore 
		>> stu[i].isOffic 
		>> stu[i].isWest 
		>> stu[i].paperNum;
		stu[i].money = getMoney(stu[i]);
		ans += stu[i].money;
		stu[i].id = i;
	}
	std::sort(stu, stu + *n, [=](student stu1,student stu2){
		if (stu1.money != stu2.money)
		{
			return stu1.money > stu2.money;
		}
		return stu1.id < stu2.id;
	});
	cout << stu[0].name << "\n" << stu[0].money << "\n" << ans;
	delete n;
	return 0;
}

