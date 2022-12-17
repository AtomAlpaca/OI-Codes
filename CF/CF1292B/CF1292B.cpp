#include <iostream>

using std::cin;
using std::cout;

const long long MAX = 75;
const long long INF = 4e17;
long long _x0, _y0, ax, ay, bx, by, x, y, t;
int ans = 0;

struct Point
{
	long long x, y;
} p[MAX];

long long dis(long long x0, long long y0, long long x1, long long y1)
{
	return std::llabs(x1 - x0) + std::llabs(y1 - y0);
}

int init()
{
	p[0].x = _x0, p[0].y = _y0;
	int i = 1;
	for (i = 1; i <= 74; ++i)
	{
		p[i].x = ax * p[i - 1].x + bx;
		p[i].y = ay * p[i - 1].y + by;
		if (p[i].x > x and p[i].y > y and dis(_x0, _y0, p[i].x, p[i].y) > t)
		{
			break;
		}
	}
	return i;
}

int main()
{
	cin >> _x0 >> _y0 >> ax >> ay >> bx >> by;
	cin >> x >> y >> t;

	int o = init();

	for (int q = 0; q <= o; ++q)
	{
		int k = 0;
		long long w = t, xs = x, ys = y;
		for (int i = q; i >= 0; --i)
		{
			if (dis(xs, ys, p[i].x, p[i].y) > w)
			{
				break;
			}
			w -= dis(xs, ys, p[i].x, p[i].y);
			++k;
			xs = p[i].x;
			ys = p[i].y;
		}

		for (int i = q + 1; i <= o; ++i)
		{
			if (dis(xs, ys, p[i].x, p[i].y) > w)
			{
				break;
			}
			w -= dis(xs, ys, p[i].x, p[i].y);
			++k;
			xs = p[i].x;
			ys = p[i].y;
		}

		ans = std::max(ans, k);
	}
	cout << ans;
}
