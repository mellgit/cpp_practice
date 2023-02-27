#include <iostream>
#include <string>
using namespace std;



// error: declaration of 'T' shadows template parameter
template <typename T>
class List
{

public:
    List(/* args */);
    ~List();

    void push_back(T data); // добавление данных в конец списка

private:
    
    template<typename T>
    class Node 
    {
    public:
        Node *pNext; // адрес, по которому лежат данные
        T data;
        Node(T data=T(), Node *pNext=nullptr)
        {
            /*
             / *pNext=nullptr - если добавлять в конец списка, тк указателя на нем не будет
             data=T() - таким способом, в data не будет лежать мусор
            */
            this->data = data;
            this->pNext = pNext;

        }
    };
    
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
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {

    }
}

int main()
{
    /*
    односвязные списки
    */

    List<int> lst;
    lst.push_back(5);
        
    return 0;
} 