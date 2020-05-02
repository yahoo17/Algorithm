// stl-map.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
struct Studentinfo
{
    string name;
    int id;
};
int main()
{

    map<int, Studentinfo> temp;
    //排序的容器,
    Studentinfo  info;
    info.name = "yuanhao";
    info.id = 201830020446;
    Studentinfo  info2;
    info2.name = "yanhao";
    info2.id = 201830020440;
    Studentinfo  info3;
    info3.name = "等今明";
    info3.id = 2018301232131;
    temp.insert(make_pair(10, info));
    temp.insert(make_pair(3, info2));
    temp.insert(make_pair(3, info3));
    temp.insert(make_pair(17, info3));
    for (map<int, Studentinfo>::iterator it = temp.begin(); it != temp.end(); it++)
        cout << "分数是" << it->first << "  姓名是" << it->second.name << " 学号是" << it->second.id << endl;
    

  
    
}

