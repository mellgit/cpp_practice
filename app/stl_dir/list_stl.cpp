#include <iostream>
#include <vector>
#include <list>
using namespace std;


template<typename T>
void print_list(const list<T> &lst)
{
    for (auto i = lst.cbegin(); i != lst.cend(); ++i) // префикс
    {
        cout<<*i<<endl;
    }

    /*
    1 - for (auto i = lst.cbegin(); i != lst.cend(); ++i) // префикс
    2 - for (auto i = lst.cbegin(); i != lst.cend(); i++) // постфикс
    разница в скорости
    тк 2 создает промежуточный объект(не используя элеметн листа) и возвращает его
    а 1 увеличивает текущий объект листа 
    */
}

void list_funtction()
{
    /*
    list - структура, которая  быстро работает на добавлене\удаление эл-ов
    в list нет перегрузки [], используется только итератор
    */

    // list<int> my_list;
    list<int> my_list = {23,435,6};
    my_list.push_back(34);
    my_list.push_front(5);

    auto it = my_list.begin(); // итератор указанный на первый эл-т листа

    my_list.sort(); // сортировка от меньшего с большему
    my_list.pop_back(); // удаляет последний эл-т
    my_list.pop_front(); // удаляет первый эл-т
    my_list.size(); // размер листа
    my_list.unique();  // удаляет последовательные дубликаты
    my_list.reverse(); // обратный порядок значений
    my_list.clear(); // очистка листа
    my_list.remove(44); // удаляет по значению

    auto it2 = my_list.begin();
    my_list.insert(it2, 232); // вставка в лист

    /*
    проиххвольный индекс
    it2++; - работает
    it2+=3; - не работает, лист не поддерживает
    вопрос решит advance()

    auto it2 = my_list.begin();
    advance(it2, 3);
    my_list.insert(it2, 232); // вставка в лист произвольного индекса
    */

    // my_list.erase(it2); // удаление
    my_list.assign(4, 343434); // заполненный список одинаковыми значениями

    /*
    копирование(перезапись) листа
    list<int> my_list = {23,435,6};
    list<int> my_list2 = {323,4435,56};
    my_list.assign(my_list2.begin(), my_list2.end());
    */

    print_list(my_list);

    // вывод листа
    // for (auto i = my_list.begin(); i != my_list.end(); i++) // постфикс
    // {
    //     cout<<*i<<endl;
    // }
}


void foreach()
{
    int arr[] = {23,4,56,3};

    // синтаксис только для MVS
    // for each(auto var in arr)
    // {
    //     cout<<var<<endl;
    // }

    // стандарт cpp
    /*
    for (auto elem : arr)
    elem копируется по значению из массива -> массив не изменяется

    for (auto &elem : arr)
    elem копируется по ссылки из массива -> массив изменяется

    for (const auto &elem : arr)
    elem константа, копируется по ссылки из массива -> массив только для чтения

    */
    for (auto elem : arr)
    {
        cout<<elem<<endl;
    }
    
    list<int> my_list = {34,54,675,9,43};

    for (const auto &elem : my_list)
    {
        cout<<elem<<endl;
    }

}

int main()
{
    /*
    доп инфо
    auto - автоматическое присваение типа данных
    auto a = 10; -> int
    auto b = 1.343; -> double
    auto b; -> error: всегда должно быть значение, иначе ошибка
    на простых переменных, лучше не использовать из за читабельности

    лучше присваивать значение итератора вектора, тк запись сокращается
    auto it = my_vector.begin();
    вместо
    vaector<int>::iterator it = my_vector.begin();

    */
    // list_funtction();



    foreach();
    return 0;
}