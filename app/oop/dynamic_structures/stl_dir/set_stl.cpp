#include <iostream>
#include <set> // бинарное дерево
using namespace std;


void set_fun()
{
    /*
    set - всегда упорядочные, все элементы уникальны, неизменяемы, очень быстрый поиск
    неизменяемы можно обойти, найти необходимый элемент, удалить его
    insert новый элемент в нужную позицию
    */
    set<int> my_set = {334,45,45,-678}; 

    my_set.insert(765);
    for (auto elem : my_set)
    {
        cout<<elem<<endl; // вывод от меньшего с большему
    }
    cout << "--------------- call find() ---------------" << endl;
    
    auto it = my_set.find(45); // возвращает итератор, если элемент найден, иначе итератор my_set.end()
    cout<<*it<<endl;

    cout << "--------------- call erase() ---------------" << endl;

    my_set.erase(4532); // удаляет элемент из дерева, если элемент есть в дереве, иначе ничего не делает
    for (auto elem : my_set)
    {
        cout << elem << endl; // вывод от меньшего с большему
    }

    cout << "--------------- multiset ---------------" << endl;
    multiset<int> my_multiset = {334, 45, 45, -678}; // все тоже самое как и set, только элементы мб не уникальными
    for (auto elem : my_multiset)
    {
        cout << elem << endl; // вывод от меньшего с большему
    }
}

int main()
{
    set_fun();
    return 0;
}