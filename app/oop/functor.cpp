#include <iostream>
using namespace std;

class MyFunctor
{
    /*
    синтаксис
    void operator ()()
    {

    }
    */
public:
    void operator ()()
    {
        cout<<"work functor"<<"\tcount="<<count<<endl;
        count++;
    }
    int operator ()(int a, int b)
    {
        cout<<"work functor2 - ";
        return a+b;
    }
private:
    // каждый вызов объекта сохраняет значение count
    int count = 0;

};

void functor_fun()
{
    /*
    функторы(функциональные объекты) - это класс в котором переопределен оператор ()
    (метод __call__)

    */
    MyFunctor f;
    f();
    f();
    f();
    int result = f(3,5);
    cout<<result<<endl;
}

int main()
{
    functor_fun();
    return 0;
}