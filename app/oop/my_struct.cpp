#include <iostream>
#include <string>
#include <memory> // для работы с умными указателями
using namespace std;


void my_struct();
void smart_pointers();
void new_smart_pointer();


int main()
{
    // my_struct();
    // smart_pointers();
    new_smart_pointer();
    return 0;
}


void new_smart_pointer()
{
    /*
    auto_ptr - устарел и похож на unique_ptr (в 17 стандарте не работает)
    unique_ptr
    shared_ptr
    */

    // два указателя ссылаются на одну область памяти
    // unique_ptr<int> p1(new int(5));
    // unique_ptr<int> p2;

    // очистить указатель
    // p1.reset(); // удаляет указатель и данные из выделенной памяти
    // p1.release(); // удаляет только указатель

    // возвращает указатель
    // int *p = p1.get(); 
    // cout<<*p<<endl;

    
    // p2 = move(p1); // 1 вариант
    // p2.swap(p1); // 2 вариант

    // часто используемый вариант
    shared_ptr<int> p1(new int(5));
    shared_ptr<int> p2(p1);
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
    так же есть auto_point
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