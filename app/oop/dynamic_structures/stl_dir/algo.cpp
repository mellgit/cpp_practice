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
    algo_fun();
    return 0;
}