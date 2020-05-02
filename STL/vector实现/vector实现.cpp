
#include <iostream>
#include <string.h>
namespace stl {


template <class T>
class vector
{
public:

    vector();
    
    //构造函数
    vector(int size);
    vector(const vector& vec);//拷贝构造函数
    ~vector();//析构函数
public:
    //重载操作符
    vector<T>& operator=(const vector<T>& vec)const;
    T& operator[] (int index);
    void push_back(T temp)
    {
        if (truesize < size)
            data[truesize] = temp;
        truesize++;
        
    }
    friend std::ostream& operator<<(std::ostream& os,vector<T> temp)
    {
        for (int i = 0; i < temp.truesize; i++)
        {
            os << temp.data[i] << " ";
        }
        return os;
    }
private:
    T *data;
public:
    int size;
    int truesize;
};
template<class T>
T &  vector<T>::operator[](int index)
{
    return data[index];
}
template<class T>
vector<T>& vector<T>::operator=(const vector<T>& vec)const
{
    if (vec == *this)
        return this;
    delete []this->data;
    this->size = vec.size;
    this->data = new T[size];
    for (int i = 0; i < size; i++)
    {
        this->data[i] = vec[i];

    }
    return *this;
}



template <typename  T>
vector<T>::vector(int size)
{
    data = new T[size];
}
template<typename T>
vector<T>::vector(const vector& vec)
{
    vector<T> temp;
    for (int i = 0; i < vec.size; i++)
        temp.data[i] = vec.data[i];
}

template<class T>
vector<T>::~vector()
{
    delete[] data;
}

template<class T>
vector<T>::vector()
{
    data = new T[100];
    size = 100;
    truesize = 0;
    for (int i = 0; i < size; i++)
    {
        data[i] = 0;
    }

}
}
using std::cout;
int main()
{
    stl::vector<int> a;
    std::cout << "a.size=" << a.size << "\n";
    cout << "a.truesize=" << a.truesize << std::endl;
    a.push_back(5);
    a.push_back(10);
    cout << a;
}
 

