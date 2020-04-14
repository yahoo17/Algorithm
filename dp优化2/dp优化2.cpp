// 百练-dp-动态规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//动态规划
#include <iostream>
#include <vector>
using namespace std;
#define N 101
int a[N][N];
int m[N];
#include <chrono>
int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    //不优化494ms
    //优化238ms
    //不用递归127ms
    //优化空间 197ms
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
            
        }
    }
    auto start = std::chrono::steady_clock::now();
    for (int i = 1; i <= n; i++)
        m[i] = a[n][i];
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            m[j]= a[i][j]+max(m[j ], m[j+ 1]);
        }

    }
    cout << m[1];
    
    


    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "time: " << elapsed.count() << "ms" << std::endl;




}






