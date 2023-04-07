#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


void foo(int a)
{
    cout<<a<<endl;
}

void for_each_fun()
{
    /*
    for_each() - похожа на ф-ю map() + идентичен циклу for each
    принимает начало, конец набора, а также ф-ю, которая применяется к этому набору

    так же можно передать лямбда ф-ю
    */
    int arr[] = {34,5465,23,5};
    for_each(begin(arr), end(arr), foo);
    cout<<"=== anon fun === "<<endl;
    for_each(begin(arr), end(arr), [](const int a)
    {
        cout<<a<<endl;
    });
}

int main()
{
    for_each_fun();
    return 0;
}