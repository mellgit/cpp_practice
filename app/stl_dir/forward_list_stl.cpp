#include <iostream>
#include <vector>
#include <forward_list>
#include <array>
#include <deque> 
using namespace std;


void deque_fun()
{
    /*
    двустороння очередь
    методы схожы с листом, разница только в скорости выполнения
    */
    deque<int> dq = {23,34,65,7};

}

void array_operator()
{
    array<int, 5> arr1 = {32, 453, 7, 34, 444};
    array<int, 5> arr2 = {32, 453, 7, 34, 444};

    // сравнивать можно только однотипные контейнеры
    bool result = (arr1 == arr2);
    bool result2 = (arr1 != arr2);
    bool result3 = (arr1 > arr2);

    cout << result << endl;
    cout << result2 << endl;
    cout << result3 << endl;
}

void array_fun()
{
    /*
    vector - обертка динамического массива
    array - обертка статического массива, изменить, вставить, удалить нельзя
    */

    // <тип массива, количество элементов>
    array<int, 5> arr = {32,453,7,34,444};

    // cout<<arr[5]<<endl; // без провероки, тк 5 индекса нет
    // cout << arr.at(5) << endl; // с првоеркой, выпадет ошибка

    for (auto elem : arr)
    {
        cout<<elem<<endl;
    }
    
}


void forward_list_fun()
{
    forward_list<int> f1 = {23,43};

    f1.push_front(3);
    f1.push_front(34);

    /*
    метода push_back нет, тк forward_list это односвязный список, 
    которых хранит в себе только указатель на сладующий элемент

    для решения этого необходим итератор и метод insert_after()

    */

    for (auto elem : f1)
    {
        cout<<elem<<endl;
    }
    
}

int main()
{
    // forward_list_fun();
    // array_fun();
    array_operator();
    return 0;
}