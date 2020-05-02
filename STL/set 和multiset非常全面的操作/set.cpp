// set.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>
using namespace std;
struct strLess
{
    bool operator()(const char* s1, const char* s2)const
    {
        return strcmp(s1, s2) < 0;
    }


};
template <class T>
void printSet(multiset<T> s)
{
    for (auto x : s)
        cout << x << ' ';
    cout << '\n';
    
}
int main()
{
    //创建multiset对象,共五种方式

    //11111创建空的multiset对象,元素类型为int
    multiset<int> s1;

    //22222创建空的multiset对象,元素类型char*,比较函数对象为自定义strLess
    multiset<const char*, strLess> s2(strLess);

    //3333利用multiset对象s1创建新的对象
    multiset<int>s3(s1);

    //444利用迭代区间[first,end)创建multiset
    int iArray[] = { 13,32,19 };
    multiset<int> s4(iArray, iArray + 3);

    //利用迭代区间和比较器来创建multiset对象
    const char* szArray[] = { "hello","dog","bird" };
    multiset<const char*, strLess> s5(szArray, szArray + 3, strLess());

    printSet<int>(s1);
    printSet<int>(s3);
    printSet<int>(s4);

    //元素插入
    //1.插入value,通过返回的pair对象来判断是否插入成功
    pair<multiset<int>::iterator, bool> returnPair;
    /* 巧妙用法cout << s4.insert(41).second; */
    /*returnPair = s4.insert(41);*/
    
    
    if (returnPair.second)
    {
        cout << "41 insert success\n";
        printSet(s4);
    }
    else
    {
        cout << " 41 insert failed\n";
    }

    s4.insert(32);
    if (returnPair.second)
    {
        cout << "32 insert success\n";
        printSet(s4);
    }
    else
    {
        cout << " 32 insert failed\n";
    }
    //2.插入区间
    /*插入区间的函数原型是void insert(first,last);
    */
    int temp[] = { 12,90,100 };
     s4.insert(temp, temp + 3);
     cout << endl;
     printSet(s4);

     //3.在特定位置之前插入元素
     /*函数原型是 iterator insert(pos,value)
     */
     /*
     12 13 19 32 41 90 100
     */
     auto it = find(s4.begin(), s4.end(), 32);
     cout << *it;
     s4.insert(it, 33);
     cout << endl;
     printSet(s4);

     //元素删除
     /*
     1.size_type erase(value); //这个会把所有值为value的都删掉
     2.void erase(pos)          //这个输入一个迭代器会删迭代器
     3.void erase(first,last);  [first,last);
     4.void clear();

     12 13 19 32 33 41 90 100
     */
     s4.erase(32);
     s4.erase(100);
     cout << endl;
     printSet(s4);

     //元素查找
     /*
     1.count(value)
     2.iterator find(value) 返回value所在位置,找不到value将返回end()
     3.lower_bound(value),
    
     12 13 19 33 41 90
     */
     s4.insert(32);
     cout<<s4.count(32)<<endl;
     cout << s4.count(90)<<endl;
     cout << s4.empty()<<endl;

     //其他函数empty swap
     multiset<int> s9;
     s9.insert(1000);
     s4.swap(s9);
     cout << "printSet(s4);";
     printSet(s4);
     cout << " printSet(s9);";
     printSet(s9);
     
     
     
}


