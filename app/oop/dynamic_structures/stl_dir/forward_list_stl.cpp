#include <iostream>
#include <vector>
#include <forward_list>
#include <array>
using namespace std;


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
    array_fun();
    return 0;
}