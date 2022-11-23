#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e4 + 5;

int n;
double ansx, ansy, ans;
int x[MAX], y[MAX], w[MAX];

double Rand()
{
	return (double)rand() / RAND_MAX;
}

double calc(double a, double b)
{
	double now = 0;
	for (int i = 1; i <= n; ++i)
	{
		double dx = x[i] - a, dy = y[i] - b;
		now += (double)sqrt(dx * dx + dy * dy) * w[i];
	}
	if (now < ans)
	{
		ansx = a;
		ansy = b;
		ans = now;
	}
	return now;
}

void solve()
{
	double t = 1000000;
	double nowx = ansx, nowy = ansy;
	while (t > 0.0001)
	{
		double nxtx = nowx + t * (Rand() * 2 - 1);
		double nxty = nowy + t * (Rand() * 2 - 1);
		double d = calc(nxtx, nxty) - calc(nowx, nowy);
		if (std::exp(-d / t) > Rand())
		{
			nowx = nxtx;
			nowy = nxty;
		}
		t *= 0.9991;
	}

	for (int i = 1; i <= 1000; ++i)
	{
		double nxtx = ansx + t * (Rand() * 2 - 1);
		double nxty = ansy + t * (Rand() * 2 - 1);
		double d = calc(nxtx, nxty);
	}
}

int main()
{
	srand(713114591);
	srand(rand());
	srand(rand());
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i] >> w[i];
		ansx += x[i];
		ansy += y[i];
	}

	ansx /= n;
	ansy /= n;
	ans = calc(ansx, ansy);

	solve();

	cout << std::fixed << std::setprecision(3) << ansx << ' ' << ansy;
}
