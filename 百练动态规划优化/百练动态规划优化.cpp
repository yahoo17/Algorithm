// 百练-dp-动态规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//动态规划
#include <iostream>
#include <vector>
using namespace std;
#define N 101
int a[N][N];
int m[N][N];
#include <chrono>
int max(int a, int b)
{
    return a > b ? a : b;
}
int result(int r, int c, int n)
{
    if (m[r][c] != -1)
        return m[r][c];
    if (r == n)
        m[r][c]= a[r][c];
    else

    {
        m[r][c] = max(result(r + 1, c, n), result(r + 1,c + 1, n));
        
    }
    return m[r][c];
}
int main()
{
    //不优化494ms
    //优化238ms
  
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
            m[i][j] = -1;
        }
    }
    auto start = std::chrono::steady_clock::now();
    cout << result(1, 1, n);

  
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double,std::micro> elapsed = end - start; 
    std::cout << "time: " << elapsed.count() << "ms" << std::endl;




}






