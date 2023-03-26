#include <iostream>
#include <string>
#include <functional>
#include <vector>
using namespace std;


class TestAnon
{
public:
    int a = 3434;
    void lampa()
    {
        auto f = [this]()
        {
            this->a;
        };
        f();
    }
};

void more_anonym_function()
{

    int a = 3;
    int b = 34;

    auto f = [&a, b]()
    {
        
        /*
        параметры можно передавать как по ссылке, так и по значению
        auto f = [=](){}; - передать все параметры по значению, которые лежат вне пространства анон ф-и
        auto f = [=]()mutable{}; - передать все параметры по значению
        auto f = [&](){}; - передать все параметры по ссылке
        auto f = [this](){}; - передать весь класс
        */
        cout<<a<<" - "<<b<<endl;
        a = 232;
    };
    f();
    cout<<a<<endl;

    // жестко указать тип возвращаемого типа ф-и (->)
    auto f2 = [&a]()->int
    {
        return a;
    };
    cout<<"return a from f2: "<<f2()<<endl;

}

void test_dowork(vector<int> &vc, function<void(int)> func)
{
    /*
    вызывает ф-ю func столько раз, сколько элементо в vc
    */
    for (auto elem : vc)
    {
        func(elem);
    }
}

void anonym_function()
{
    /*
    анонимные ф-и, синтаксис - [](){};
    у анон ф-и нет имени, вызывается через объект function, либо напрямую
    есть два варианта инициализации анонимной ф-и (вариант 1 и 2)

    у анон ф-и свое пространство имен, в нем не видны переменные и тп из другого пространства
    для этого необходимо в [] передать необходимые параметры по ссылке(вариант 3)
    в 14 стандарте есть возможность вызавать через auto
    auto f = [](){};

    тип анон ф-и определяется автоматичиски, если нет return - void,
    инача отталкивается от типа возвращаемого значения
    return 1; - int
    return 55.667; - float
    return true; - bool
    */
    vector<int> vc = {234,564,8634,475};
    
    // 1 вариант
    function<void(int)> f;
    f = [](int a){cout<<"call anonym function a = "<<a<<endl;};
    test_dowork(vc, f);
    cout<<"========================"<<endl;
    // 2 вариант
    test_dowork(vc, [](int a){
        cout<<"call anonym function a = "<<a<<endl;
    });

    // 3 вариант
    int p = 0;
    cout<<p<<endl;
    auto f2 = [&p]()
    {
        p = 4;
    };
    f2();
    cout<<p<<endl;

}


void foo()
{
    cout<<"call function foo()"<<endl;
}

int sum(int a, int b)
{
    return a+b;
}

void std_function()
{
    /*
    class std::function - обертка для ф-й (указатель на ф-ю), используется для полиморфизма и лямбда ф-й, те шаблон для ф-й
    для ее работы необходимо, чтобы совпадала сигнатура фу-и
    */
    function<void()> f; // объект function
    f = foo; // присвоение объекту значения
    f(); // вызов содержимого объекта, после назначения

    function<int(int, int)> f_sum;
    f_sum = sum;
    cout<<f_sum(3,5)<<endl;

}

union MyUnion
{
    short int a;
    int b;
    float c;
};

void union_fun()
{
    /*
    union - объединение
    позволяет хранить несколько переменных в одной области памяти
    если записать новые данные в область памяти для union, 
    то предыдущие данные будут утеренны

    объем выделяемой памяти для union равен самому большому значению в union (в MyUnion float)

    пример:
    */

    MyUnion u;

    u.a = 4; // a = 4 , b and c trash
    u.b = 45555; // b = 4555, a and c trash
    u.c = 466.11; // c = 466.11, a and b trash
    
}

int main()
{
    // union_fun();
    // std_function();
    // anonym_function();
    more_anonym_function();
    return 0;
}