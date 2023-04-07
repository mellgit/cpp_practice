#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


void unique_fun()
{
    /*
    unique - уникальные элементы набора

    из статического массива повторяющиеся элементы не удаляются,
    они переносятся в конец массива

    но в других наборах(vector, list)
    можно использовать метод erase, для изменения текущего набора

    unique_copy - похож на unique, но позволяет скопировать данные 
    в другой контейнер
    сами контейнеры мб разные, но тип должен быть одинаковым
    vector<int>
    list<int>
    */
    // работает одинаково для других наборов
    int arr[] = {2,2,2,3,3,4,4,4};

    // result - итератор, указывающий на границу между нужными элементами от ненужных
    auto result = unique(begin(arr), end(arr));

    for_each(begin(arr), result, [](const int a)
    {
        // вывод уникальных элементов
        cout<<a<<endl;
    });

    cout<<"=== vector ==="<<endl;
    cout<<"before"<<endl;
    vector<int> v = {2,2,2,3,3,4,4,4};
    for(auto elem : v)
    {
        cout<<elem<<endl;
    }
    auto result2 = unique(begin(v), end(v));

    
    v.erase(result2, end(v));
    
    cout<<"after"<<endl;
    for(auto elem : v)
    {
        cout<<elem<<endl;
    }

    cout<<"=== vector to vector==="<<endl;
    vector<int> v1 = {2,2,2,3,3,4,4,4};
    vector<int> v2;

    unique_copy(begin(v1), end(v1),back_inserter(v2));
    for(auto elem : v2)
    {
        cout<<elem<<endl;
    }

}

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
    // работает одинаково для других наборов
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
    // for_each_fun();
    unique_fun();
    return 0;
}