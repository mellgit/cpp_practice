#include <iostream>
using namespace std;

// создание класса string 45:51
class My_string
{
private:
    char *str;
public:
    My_string(char *str)
    {
        int len = strlen(str);
        // cout<<&str<<endl; // 0x16fba7778 - разныеячейки памяти
        cout<<"len str: "<<len<<endl;
        this->str = new char[len+1]; // новый символьный массив с +1 значением под '\0'

        for (int i = 0; i < len; i++)
        {
            this->str[i] = str[i];
        }
        this->str[len] = '\0'; // добавить конец сторки в строку

        // cout<<&this->str<<endl; // 0x16fba77f0 - разные ячейки памяти
        
    }
    My_string()
    {
        str = nullptr;
    }
    ~My_string()
    {
        delete [] this->str;
        this->str = nullptr;
    }

    My_string & operator =(const My_string & other)
    {
        if (this->str != nullptr)
        {
            delete [] str;
        }
        // код из конструктора необходимо перенесте в private фу-ю
        int len = strlen(str);
        this->str = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            this->str[i] = str[i];
        }
        this->str[len] = '\0';

        return *this;
    }
    void print()
    {
        cout<<str;
    }
};





int main()
{
    cout<<"============ BEGIN ============"<<endl;
    My_string str("hello");
    My_string str2("world!!!");

    str = str2;
    

    cout<<endl;
    return 0;
}