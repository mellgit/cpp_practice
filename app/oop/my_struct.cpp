#include <iostream>
#include <string>
using namespace std;


void my_struct();

int main()
{
    my_struct();
    return 0;
}

class MyClass
{
    int a = 22;
    void print(){cout<<a<<endl;};
};

struct MyStruct
{
    /*
    в структуре все поля и методы public по умолчанию (но их можно установить)
    так же и при наследовании

    у структур так же есть конструкторы(+перегрузка) и деструкторы
    */
    int a = 22;
    void print() { cout << a << endl; };
};

void my_struct()
{
    MyClass m;
    MyStruct ms;

    cout << ms.a << endl;
    ms.print();

    // с классом так не получится, тк нет уровня доступа public
    // cout << m.a << endl;
    // m.print();
}