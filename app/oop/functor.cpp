#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check_zero(int a)
{
    return a>0;
}

void bool_functor()
{
    /*
    предикаты - это функторы, которые возвращают булевое значение
    ипсользуются для проверки набора, вместо перебора циклом
    число больше нуля, четное или нечетное, есть подстрока в строке или нет
    */

    vector<int> v = {23,45,76,-234,-555,121};
    int result = count_if(v.begin(), v.end(), check_zero);
    cout<<result<<endl;
}


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
    // functor_fun();
    bool_functor();
    return 0;
}