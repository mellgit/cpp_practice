#include <iostream>
#include <string>
using namespace std;


void my_struct();
void smart_pointers();

int main()
{
    // my_struct();
    smart_pointers();
    return 0;
}

template<typename T>
class SmartPointer
{
public:

    SmartPointer(T *ptr)
    {
        this->ptr = ptr;
        cout << "constructor" << endl;
    }
    ~SmartPointer()
    {
        delete ptr;
        cout << "destructor" << endl;
    }

    T& operator *()
    {
        /*
        чтобы разименовать умный указатель, необходимо перегрузить
        указатель (*)
        */
        return *ptr;
    }
private:
    T *ptr;
};

void smart_pointers()
{
    /*
    умные указатели - примитивные сборщики мусора
    */

    // обычные указатели
    // int *ptr = new int(3);
    // delete ptr;
    // ptr = nullptr;

    SmartPointer<int> pointer = new int(4); // похож на обычный указатель
    cout << *pointer << endl; // использование перегрузки разименования
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