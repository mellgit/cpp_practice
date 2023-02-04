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


    My_string(const My_string &other)
    {
        /*
        конструктор копирования
        */
        int len = strlen(other.str);
        this->str = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[len] = '\0';
        
    }

    My_string & operator =(const My_string & other)
    {
        if (this->str != nullptr)
        {
            delete [] str;
        }
        // код из конструктора необходимо перенесте в private фу-ю
        int len = strlen(other.str);
        this->str = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            this->str[i] = other. str[i];
        }
        this->str[len] = '\0';

        return *this;
    }

    My_string operator +(const My_string & other)
    {
        My_string new_str;

        int this_len = strlen(this->str);
        int other_len = strlen(other.str);

        new_str.str = new char[this_len + other_len + 1]; // +1 -> '\0'

        int i = 0;
        // цикл для первого слова
        for (; i < this_len; i++)
        {
            new_str.str[i] = this->str[i];
        }
        // цикл для второго слова
        for (int j = 0; j < other_len; j++, i++)
        {
            new_str.str[i] = other.str[j];
        }
        new_str.str[this_len + other_len] = '\0';
        return new_str;
        
        
    }
    void print()
    {
        cout<<str;
    }
};





int main()
{
    cout<<"============ BEGIN ============"<<endl;
    My_string str("hello ");
    My_string str2("world");

    // перегрузка оператора присваивания
    // str = str2;

    My_string result = str+str2;
    result.print();
    

    cout<<endl;
    return 0;
}