#include <bits/stdc++.h>
using namespace std;

struct Apple
{
	int high,cost;
};
bool isSort(Apple x,Apple y)
{
	return x.cost < y.cost ? true : false;
}
int main(int argc, char const *argv[])
{
	int * n = new int;
	int a,b,s;
	cin >> *n >> s >> a >> b;
	Apple apple[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> apple[i].high >> apple[i].cost;
		if (apple[i].high > a + b)
		{
			apple[i].cost = s + 1;
		}
	}
	sort(apple,apple + *n,isSort);
	int m = 0;
	while (s >= apple[m].cost)
	{
		s -= apple[m].cost;
		++m;
	}
	cout << m++;
	delete n;
	return 0;
}