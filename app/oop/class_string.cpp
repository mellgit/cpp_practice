#include <iostream>
using namespace std;

// создание класса string 45:51
class My_class
{
private:
    char *str;
public:
    My_class(char *str)
    {
        int len = strlen(str);
        cout<<&str<<endl;
        cout<<"len str: "<<len<<endl;
        this->str = new char[len+1]; // новый символьный массив с +1 значением под '\0'

        for (int i = 0; i < len; i++)
        {
            this->str[i] = str[i];
        }
        this->str[len] = '\0'; // добавить конец сторки в строку

        cout<<&this->str<<endl;
        
    }
    My_class()
    {
        str = nullptr;
    }
    ~My_class()
    {
        delete [] this->str;
        this->str = nullptr;
    }
};





int main()
{
    cout<<"============ BEGIN ============"<<endl;
    My_class str("test");
    return 0;
}