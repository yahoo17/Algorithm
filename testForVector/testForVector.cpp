// testForVector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
int main()
{
    vector<int> i1;
    i1.push_back(1);
    i1.push_back(3);
    vector<int>::iterator it ;
    cout << sizeof(it)/sizeof(int)<<endl;
    cout << typeid(it).name()<<endl;
    
}
