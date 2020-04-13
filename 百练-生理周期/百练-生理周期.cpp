// 百练-生理周期.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//暴力解法
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = d; i < 21252; i++)
    {
        if ((i - a) % 23 == 0 && (i - b) % 28 == 0 && (i - c) % 33 == 0)
            cout << i << endl;
    }
   
}

//int main()
//{
//	int p, e, i, d;
//
//	cin >> p >> e >> i >> d;
//	int now=d;
//	for ( ; (now - p) % 23 != 0; now++);
//	for (; (now - e) % 28 != 0; now+=23);
//	for (; ((now - i) % 33 != 0)&&now<=21252; now += 23 * 28);
//	cout << now-d;
//}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜