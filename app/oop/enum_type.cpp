#include <iostream>
#include <string>
#include <typeinfo>
using namespace std; // для неявного использования, лучше не использовать 


void enum_function();
void name_space_cpp();
void template_class();
void inheritance_template_class();
void class_template_specialization();

int main()
{
    // enum_function();
    // name_space_cpp();
    // template_class();
    // inheritance_template_class();
    class_template_specialization();
    return 0;
}

template<typename NewTemp>
class Printer
{
public:
    void print(NewTemp value)
    {
        cout<<value<<endl;
        // cout<<typeid(value).name()<<endl;
    }
};

template<>
class Printer<string>
{
    /*
    данный шаблонный класс создан конкретно под строки
    для этого ипользуется - template<>
    больше похоже на перегрузку
    */
public:
    void print(string value)
    {
        cout << "___" << value << "___" << endl;
    }
};
void class_template_specialization()
{

    // Printer<int> p;
    // p.print(234); // отработает базовый класс
    Printer<string> p;
    p.print("hello"); // ___hello___ - отработает наследник
}




template <class Temp> 
class TypeSize
{

public:
    
    TypeSize(Temp value)
    {
        this->value = value;
    }
    void data_type_size()
    {
        cout << "sizeof=" << sizeof(value) << endl;
    }
    Temp my_function() { return value; }

protected:
    Temp value;
};

/*
class TypeInfo : public TypeSize<int> - либо привязать наследника к конкретному типу данных

template <typename T1>
class TypeInfo : public TypeSize<T1> - либо дать доступ на все типы, в 
таком случае наследуемый класс также должен быть шаблонным

*/
template <class Temp>
class TypeInfo : public TypeSize<Temp>
{
public:
    // error: member initializer 'TypeSize' does not name a non-static data member or base class
    // TypeInfo(Temp value):TypeSize(value)
    // {

    // }

    // void show_type_name()
    // {
    //     cout<<"type name: "<<typeid(value).name()<<endl;
    // }
private:
};

void inheritance_template_class()
{
    int a = 5;
    double x = 2.5;

    // TypeSize<int> c(a);
    // c.data_type_size();
    // cout << "value=" << c.my_function() << endl;

    // TypeInfo<double> b(x);
    // b.data_type_size();
    // b.show_type_name();
    // cout << "value=" << b.my_function() << endl;
}






template <typename T> // шаблонный тип данных T
// template<typename T1, typename T2> // чтобы типов данных было несколько
class MyClass
{

public:
/*
в шаблонном классе можно создавать шаблонные типы фу-й

*/
    MyClass(T value)
    {
        this->value = value;
    }
    void data_type_size()
    {
        cout << "sizeof=" << sizeof(value) << endl;
    }
    T my_function() { return value; }

private:
    T value;
};


void template_class()
{
    int a = 5;

    /*
    так как тип данных не известен, необходимо указывать тип данных
    для шаблонного класса, через скобки <>
    в эти скобки так же можно передавать тип созданного нами класса
    MyClass<NewMyClass> c(a);
    */
    MyClass<int> c(a);
    c.data_type_size();
    cout<<"value="<<c.my_function()<<endl;
}


namespace first_ns
{
    void func()
    {
        cout<<"first NS"<<endl;
    }
}
namespace second_ns
{
    void func()
    {
        cout << "second NS" << endl;
    }
}

void name_space_cpp()
{
    /*
    std - пространство именн с++
    */
    first_ns::func();
    second_ns::func();
}

class PC
{

public:
    enum PCState
    {
        //тут хранятся числа от 0 до N(N - количество значений в enum)
        OFF,
        ON,
        SLEEP,
        TIMER = 30 // значения можно устанавливать по необходимости
    };
 
    PCState get_state(){return state;}
    void set_state(PCState state)
    {
        this->state = state;
     }

private:
    PCState state;
};


void enum_function()
{
    /*
    enum - тип перечисления
    */

    PC pc;
    pc.set_state(PC::PCState::OFF);

    // применять можно в if
    if (pc.get_state() == PC::PCState::ON)
    {
        cout<<"PC on"<<endl;
    }

    // применять можно в switch
    switch (pc.get_state())
    {
    case PC::PCState::ON:
        cout<<"pc on"<<endl;
        break;
    case PC::PCState::OFF:
        cout << "pc off" << endl;
        break;
    case PC::PCState::SLEEP:
        cout << "pc sleep" << endl;
        break;

    default:
        break;
    }
    

    // определение состояния текстом, для разработчика
    // PCState s;
    // s = PCState::OFF;
}