#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


bool check_zero(int a)
{
    return a>0;
}

bool my_pred(int a, int b)
{
    return a>b;
}

class Person
{
public:
    string name;
    int score;

    Person(string name, int score)
    {
        this->name = name;
        this->score = score;
    }

    bool operator()(const Person &p)
    {
        return p.score >180;
    }
};


void find_fun()
{
    /*
    find, find_if, find_if_not
    find - найти элемент в коллекции, возвращает итератор элемента
    find_if - возвращает true, если элемент в наборе найден по определенным условиям
    find_if_not - возвращает true, если предикат возвращает false(обратный fing_if)
    */
    vector<int> v = {34,5,76,234,45,98};

    cout<<" === find === "<<endl;
    // если result будет указывать на мусор(конец набора), элемент не найден
    auto result = find(v.begin(), v.end(), 5232);
    
    if (result == v.end())
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"found"<<endl;
    }


    vector<int> v2 = {34,6,234,98}; // четные
    // vector<int> v2 = {343,63,235,93}; // нечетные

    cout<<" === find_if === "<<endl;
    auto result2 = find_if(v2.begin(), v2.end(), [](int a)
    {
        // проверка на то, что в наборе только четные числа
        return a%2==0;
    });
    
    if (result2 == v2.end())
    {
        cout<<"only odd"<<endl;
    }
    else
    {
        cout<<"only even"<<endl;
    }
    

    vector<int> v3 = {-333,-34,-6,-234,-98}; 
    cout<<" === find_if_not === "<<endl;
    auto result3 = find_if_not(v3.begin(), v3.end(), [](int a)
    {
        return a<0;
    });
    
    if (result3 == v3.end())
    {
        cout<<"all > 0"<<endl;
    }
    else
    {
        cout<<"< 0"<<endl;
    }

    cout<<"===== class Person ====="<<endl;
    // лучше не перегружать оператор сравнения, тк больше напряга, проще предикатом
    vector<Person> person{
        Person("bob", 232),
        Person("alice", 32),
        Person("john", 22),
        Person("mike", 172),
    };

    auto result4 = find_if(person.begin(), person.end(),[](const Person &p)
    {
        // return p.name == "mike";
        return p.name == "mike" && p.score == 172; // поиск по нескольким кретериям
    });
    
    if (result4 == person.end())
    {
        cout<<"person not found"<<endl;
    }
    else
    {
        cout<<"person found"<<endl;
    }
}

void algo_fun()
{
    /*
    алгоритмы + предикаты
    унарный предикат - предикат, который принимает один параметр
    бинарный предикат - предикат, который принимает два параметра   

    sort - сортировка набора
    sort(начало набора, конец набора, предикат, по которому сортирует)
    */
    vector<int> v = {34,5,254,67,88,6,4};

    // sort(v.begin(), v.end()); // сортировка от меньшего к большему
    
    // sort(v.begin(), v.end(), my_pred); // сортировка от большего к меньшему 

    // но в такому случае лучше использовать анонимную ф-ю
    sort(v.begin(), v.end(), [](int a, int b)
    {
        return a>b;
    });

    for (auto elem : v)
    {
        cout<<elem<<endl;
    }

    cout<<"sort int arr"<<endl;
    // сортировка обычного массива
    const int size = 7;
    int arr[size] = {34,5,254,67,88,6,4};

    // первый элемент массива - это указатель на первый эл-т массива
    // arr+size - арифметика указателей, чтобы добраться до последнего элемента
    sort(arr, arr+size);
    for (auto elem : arr)
    {
        cout<<elem<<endl;
    }

    cout<<"===== class Person ====="<<endl;
    vector<Person> person{
        Person("bob", 232),
        Person("alice", 32),
        Person("john", 22),
        Person("mike", 172),
    };

    cout<<" = name sort = "<<endl;
    // сортировка по имени, по алфавиту
    sort(person.begin(), person.end(), [](const Person &p1, const Person &p2)
    {
        // const чтобы не изменить случайно, & чтобы не копировать весь объект
        return p1.name < p2.name;
    });
    for (auto elem : person)
    {
        cout<<"name: "<<elem.name<<"\tscore: "<<elem.score<<endl;
    }

    cout<<" = score sort = "<<endl;
    // сортировка по баллам, от большего к меньшему
    sort(person.begin(), person.end(), [](const Person &p1, const Person &p2)
    {
        return p1.score > p2.score;
    });
    for (auto elem : person)
    {
        cout<<"name: "<<elem.name<<"\tscore: "<<elem.score<<endl;
    }

}

int main()
{
    // algo_fun();
    find_fun();
    return 0;
}