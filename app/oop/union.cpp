#include <iostream>
#include <string>
#include <functional>
using namespace std;

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
    std_function();
    return 0;
}