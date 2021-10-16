#include <bits/stdc++.h>
using namespace std;

double getLen(double x1,double y1,double x2,double y2)
{
	return sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
}

int main(int argc, char const *argv[])
{
	double x[3],y[3],ans = 0;
	for (int i = 0; i < 3; ++i)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		ans += getLen(x[i],y[i],x[(i + 1) % 3],y[(i + 1) % 3]);
	}
	printf("%.2lf",ans);
	return 0;
}