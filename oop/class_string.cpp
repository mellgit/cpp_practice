#include <iostream>
using namespace std;

// создание класса string 45:51
class My_string
{
private:
    char *str;
    int len;
public:
    My_string(char *str)
    {
        len = strlen(str);
        // cout<<&str<<endl; // 0x16fba7778 - разные ячейки памяти
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
        len = 0;
    }
    ~My_string()
    {
        delete [] this->str;
        this->str = nullptr;
    }


    My_string(const My_string &other)
    {
        /*
        конструктор копирования необходим для создания точной копии объекта класса, но вдругой области памяти
        */
        len = strlen(other.str);
        this->str = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[len] = '\0';
    }

    My_string(My_string &&other)
    {
        /*
        конструктор перемещения, тк конструктор копирования занимает память и время
        */
        this->len = other.len;
        this->str = other.str;
        other.str = nullptr;
    }

    My_string & operator =(const My_string & other)
    {
        if (this->str != nullptr)
        {
            delete [] str;
        }
        // код из конструктора необходимо перенесте в private фу-ю
        len = strlen(other.str);
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
        new_str.len = this_len + other_len;

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

    bool operator ==(const My_string &other)
    {
        if (this->len != other.len)
            return false;

        for (int i = 0; i < this->len; i++)
        {
            if (this->str[i] != other.str[i])
                return false;
        }
        return true;
    }

    bool operator !=(const My_string &other)
    {
        return !(this->operator==(other));
    }

    char& operator [](int index)
    {
        /*
        ссылка нужна для того чтобы изменять объект класса
        */
        return this->str[index];
    }
    void print()
    {
        cout<<str;
    }

    int length()
    {
        /*
        узнать длинну строки
        */
        return len;
    }
};





int main()
{
    cout<<"============ BEGIN ============"<<endl;
    My_string str("hello");
    My_string str2("world");

    // перегрузка оператора присваивания
    // str = str2;

    cout << "methods length: " << str.length() << endl;
    cout << "methods length: " << str2.length() << endl;

    My_string result = str+str2;
    result.print();
    cout<< " len: " << result.length() << endl;


    bool equal = str == str2;
    cout << "result equal: " << equal << endl;
    bool no_equal = str != str2;
    cout << "result no equal: " << no_equal << endl;

    cout << "index operator: "<<str[0] << endl;

    cout<<"change symbol:"<<" ";
    str.print();
    cout<<" ";
    str[0] = 'R';
    str.print();

    cout<<endl;
    return 0;
}