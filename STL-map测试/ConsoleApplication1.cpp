// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;
void DelVectorVal(vector<int>& m)
{
    //
    if (m.size() == 0)
        return;
    
    for (int i = 0; i < m.size(); i++)
    {
         vector<int>::iterator begin = m.begin();
        if (m[i] % 5 == 0)
            m.erase(begin + i);
    }
    

 }

int main()
{
    //插入
    //map不允许重复的元素,我们用pair<iterator,bool> 来检查有没有插入成功
    map<int, int> m;
    pair< map<int, int>::iterator, bool> insert_pair;
    insert_pair = m.insert(map<int, int>::value_type(1, 11));
    insert_pair = m.insert(pair<int, int>(1, 20));
    if (insert_pair.second == true)
    {
        printf("success\n");
    }
    else
    {
        printf("failed\n");
    }
    //用下标会覆盖掉
    m[10] = 15;
    m[1] = 30;
    //
    m.insert(pair<int, int>(2, 22));
    m.insert(pair<int, int>(3, 33));
    m.insert(pair<int, int>(4, 44));

  /*  for (auto it = m.begin(); it != m.end(); it++)

    {

        cout << it->first << "->" << it->second << endl;
    }*/
    //按逆序打印噢
    /*for (auto it = m.rbegin(); it != m.rend(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }*/
    //使用下标访问的时候阿,[]里面的值是key
    /*for (int i = 1; i <= m.size(); i++)
    {
        cout << m[i] << " " << endl;
    }*/
    

    //map的查找
    //map的count是查key,
    //count无法定位数据的位置
    /*cout<<m.count(2)<<endl;
    cout << m.count(44);*/

    //map查找时 find是填key
    /*map<int, int>::iterator it;
    it = m.find(2);
    if (it != m.end())
    {
        cout << "success";
        cout << endl << "find(44)" << it->first << "->" << it->second << endl;
    }
    else
    {
        cout << "fail";
    }*/
    map<int, int>::iterator it=m.begin();
    for (; it != m.end();)
    {
        if (it->second == 22)
        {
            /*auto temp = it;
            temp++;
            m.erase(it);
            it = temp;*/
            //或者直接
            m.erase(it++);
            //第一步 传it
            //第二步 it++
            //第三步 迭代器失效
            
        }
        else
        {
            it++;
        }

    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

}


