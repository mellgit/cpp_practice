#include <iostream>
#include <set> // бинарное дерево
#include <vector>
using namespace std;

typedef vector<int> int_vector; // alias 


void typedef_fun()
{
    /*
    typedef - присвоить типу данных псевдоним (alias)

    чаще всего не используют using namespace std и запись вектора будет выглядет следующем образом
    std::vector<int> my_vector;
    
    при помощи псевдонима, можно сократить название
    int_vector my_vector;

    */

    // записи равны между собой, не стал убирать std
    vector<int> my_vector = {23, 34, 54, 5};
    int_vector my_vector2 = {23, 34, 54, 5};

    cout << "default" << endl;
    for (auto elem : my_vector)
    {
        cout << elem << endl;
    }
    cout << "typedef" << endl;
    for (auto elem : my_vector2)
    {
        cout << elem << endl;
    }
}

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
    // set_fun();
    typedef_fun();
    return 0;
}