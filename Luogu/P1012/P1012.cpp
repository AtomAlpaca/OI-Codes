#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	string nums[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
	}
	sort(nums,nums + *n,[=](string s1,string s2){
		return s1 + s2 > s2 + s1;
	});
	for (int i = 0; i < *n; ++i)
	{
		cout << nums[i];
	}
	delete n;
	return 0;
}