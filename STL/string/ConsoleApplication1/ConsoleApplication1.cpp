// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


class String
{
public:
    String(const char* str = NULL);  //构造函数
    String(const String& other);        //拷贝构造函数
    String& operator=(const String& other);///拷贝赋值函数
    ~String();                      //析构函数
    String& operator+(const String& other);//连接函数
    bool operator==(const String& other); //判断相等函数
    int length()const;           //返回长度
    void print()
    {
        printf("%s\n", m_data);
    }
private:
    char* m_data;
    inline int len(char *p)const 
    {
        int i = 0;
        while (*p++) i++;
        return i;

    }

};
String::String(const char * str)
{
    //const char* temp = str;
    //m_data =const_cast<char *>(temp);
    if (str == NULL)
    {
        m_data = new char[1];
        *m_data = '\n';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
        
    }

}
String::String(const String& other)
{
    
    if (!other.m_data)
    {
        m_data = 0;
    }
    else
    {

    }

}
String& String::operator=(const String& other)
{
    if (other.m_data != this->m_data)
    {
        delete m_data;
        if (other.m_data == 0)
            m_data = 0;
        else
        {
            m_data = new char[strlen(other.m_data) + 1];
            strcpy(m_data, other.m_data);
        }
    }
    return *this;
}
String::~String()
{
    if (m_data == NULL)
        return;
    delete m_data;
    m_data = NULL;

}
String& String::operator+(const String& other)
{
    String newString;
    if (!other.m_data)
    {
        return *this;
    }
    else if (!this->m_data)
    {
        newString = other;
        return newString;
    }
    else
    {

        newString.m_data = new char[strlen(m_data) + strlen(other.m_data) + 1];
        strcpy(newString.m_data, m_data);
        strcat(newString.m_data, other.m_data);
        return newString;
    }
    /*int l1 = this->length();
    int l2 = other.length();
    const int len = l1 + l2;
    char temp[100];
    for (int i = 0; i < l1; i++)
    {
        temp[i] = this->m_data[i];
    }
    int j = 0;
    for (int i = l1; i < l1 + l2; i++)
    {
        temp[i] = other.m_data[j++];

    }
    this->m_data = temp;
    return *this;*/
}
bool String::operator==(const String& other)
{
    //if (other.m_data == this->m_data)
    //    return true;
    //return false;
    if (strlen(m_data) != strlen(other.m_data))
    {
        return false;
    }
    else
        return strcmp(m_data, other.m_data) ? false : true;
}

int String::length()const
{
    return len(m_data);

}

int main()
{
    
    String a("my test String");

    String c("a");
    String d("b");
    String e = c + d;
    a.print();
 
    e.print();
    d.print();

    
}


