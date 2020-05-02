// map给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
class Solution {
public:
    int importance = 0;
    map <int, Employee*> temp;
    int getImportance(vector<Employee*> employees, int id) {

        for (auto& x : employees)
            temp[x->id] = x;
        importance += digui(id);
    }
    int digui(int id)
    {
        if (temp[id]->subordinates.empty()==false)
        {
            for (auto x : temp[id]->subordinates)
                digui(x);
        }
        else if (temp[id]->subordinates.empty()==true)
            return temp[id]->importance;
    }
};
int main()
{
    /*Employee* ptr = new Employee();
    ptr->id = 10;
    ptr->importance = 20;
    
    map<int, Employee*> temp;
    temp.insert(make_pair(10, ptr));
    if (temp[11] != NULL)
        cout << 1;
    if (temp[10] != NULL)
        cout << 1;*/
}
