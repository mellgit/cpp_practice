#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    Node *pNext; // адрес, по которому лежат данные
    T data;
    Node(T data = T(), Node *pNext = nullptr)
    {
        /*
         / *pNext=nullptr - если добавлять в конец списка, тк указателя на нем не будет
         data=T() - таким способом, в data не будет лежать мусор
        */
        this->data = data;
        this->pNext = pNext;
    }
};


template <typename T>
class List
{

public:
    List();
    ~List();

    void push_back(T data); // добавление данных в конец списка
    int get_size(){return size;}

    T& operator[](const int index);

private:
    /*
    в pivate должен быть класс Node, но выкидывает ошибку: error: declaration of 'T' shadows template parameter
    как вытащил из класса List, ошибки пропала
    */

    int size; // количество элементов списка
    Node<T> *head; // первый элемент списка
};

template <typename T>
List<T>::List(/* args */)
{
    size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List()
{
}

template <typename T>
void List<T>::push_back(T data)
{
    /*
    добавление в конец списка 
    */

    // если данных нет
    if (head == nullptr)
    {
        head = new Node<T>(data);
        
    }

    // если данные уже есть
    else
    {
        Node<T> *current = this->head; // временная переменная

        // пока не найдем элемент со значением nullptr
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data); // добавить в конец списка

    }

    size++;
}

template <typename T>
T &List<T>::operator[](const int index)
{
    /*
    перегрузка оперетора [], чтобы получить данные из списка
    */
    int counter = 0;
    Node<T> *current = this->head; // временная переменная

    while (current != nullptr)
    {
        // если индекс нашелся
        if (counter == index)
        {
            return current->data;
        }

        // если индекс не тот, переходим на следующий
        current = current->pNext;
        counter++;
    }
}

int main()
{
    /*
    односвязные списки
    */

    cout<<"========================= BEGIN ========================="<<endl;

    List<int> lst;

    int value_for_size;
    cout<<"enter list size: "; cin>>value_for_size;
    for (int i = 0; i < value_for_size; i++)
    {
        lst.push_back(rand()%20);
    }
    

    for (int i = 0; i < lst.get_size(); i++)
    {
        cout<<"elem: "<<lst[i]<<endl;
    }
    

    return 0;
} 