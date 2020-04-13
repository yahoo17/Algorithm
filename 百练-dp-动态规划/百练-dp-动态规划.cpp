// 百练-dp-动态规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//动态规划
#include <iostream>
#include <vector>
using namespace std;
#define N 101
int a[N][N];
int max(int a, int b)
{
    return a > b ? a : b;
}
int result(int r, int c,int n)
{
    if (r == n)
        return a[r][c];
    else
        return a[r][c]+max(result(r + 1, c,n), result(r + 1, c + 1,n));
    
}
int main()
{
  /*  int group;
    cin >> group;
    vector <int> res;
    for (int i = 0; i < group; i++)
    {*/
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
                cin >> a[i][j];
        }
        
        cout << result(1, 1, n);










    
    
    
}

