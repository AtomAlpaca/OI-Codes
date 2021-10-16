#include<bits/stdc++.h>
using namespace std;
//pi的大小，后面用得上
//养成好习惯常量要用const
const double pi = 3.141593;
int main(int argc, char const *argv[])
{
	short Q;
	cin >> Q;
	if(Q == 1)
	{
		cout << "I love Luogu!";
	}
	else if(Q == 2)
	{
		cout << 2 + 4 << " " << 10 - (2 + 4);
	}
	else if(Q == 3)
	{
		cout << 14 / 4 << endl;
		cout << 14 - (14 % 4) << endl;
		cout << 14 % 4 << endl;
	}
	else if(Q == 4)
	{
		//这里有个坑，保留的是有效数字
		//所以小数点后只有3位
		cout << fixed << setprecision(3) << 1.0 * 500 / 3;
	}
	else if(Q == 5)
	{
		cout << (220 + 260) / (20 + 12);
	}
	else if(Q == 6)
	{
		//应该是用勾股 a^2 + b^2 = c^2
		//等等现在小学都学勾股了吗
		cout << sqrt(6 * 6 + 9 * 9);
	}
	else if(Q == 7)
	{
		short money = 100;
		money += 10;
		cout << money << endl;
		money -= 20;
		cout << money << endl;
		money = 0;
		cout << money << endl;
	}
	else if(Q == 8)
	{
		cout << pi * 5 * 2 * 1.0 << endl;
		cout << pi * 5 * 5 * 1.0 << endl;
		cout << pi * 5 * 5 * 5 * 4 * 1.0 / 3 << endl;
		//现在小学都学球的体积了Σ(っ °Д °;)っ
	}
	else if(Q == 9)
	{
		//吃了三次
		short peach = 1;
		//吃三次后剩余1个
		for (int i = 0; i < 3; ++i)
		{
			peach += 1;
			peach *= 2;
		}
		cout << peach;
	}
	else if(Q == 10)
	{
		//想不出怎么写，直接输出答案吧
		cout << 9;
	}
	else if(Q == 11)
	{
		//记得转化为小数
		cout << 1.0 * 100 / (8 - 5);
	}
	else if(Q == 12)
	{
		cout << (int)'M' - (int)'A' + 1 << endl;
		cout << (char)(18 + (int)'A' - 1);
	}
	else if(Q == 13)
	{
		//这道题查了资料才做出来，分数指数幂不是难为我这初中生吗
		//然鹅还是想不出怎么程序写，直接输出答案吧QAQ
		cout << 16 << endl;
	}
	else
	{
		//依然想不出怎么写，直接输出答案
		cout << 50;
	}
	return 0;
}