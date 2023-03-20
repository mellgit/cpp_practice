#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
using namespace std;


void queue_fun()
{
    /*
    очередь и очередь с приоритетом - адаптеры контейнеров (тип обвяз)


    !не работает
    queue<int, list<int> q; - только с листом
    auto a = q._Get_conteiner();

    priority_queue<int, vector<int>> pq; - только с вектором
    */

    queue<int> q;
    q.push(2); // or emplace()
    q.push(4);
    q.push(25);
    
    // cout << q.front() << endl; // первый элемент
    // cout << q.back() << endl; // последний элемент
    // q.pop(); // удаляет первый элемент в очереди

    cout << " queue" << endl;
    cout << "len=" << q.size() << endl;
    // посмотреть все элементы в очереди
    cout<<"print full queue"<<endl;
    while (!q.empty())
    {
        cout << q.front() << endl; 
        q.pop();                   
    }

    cout << " priority_queue" << endl;

    priority_queue<int> pq; // элементы сортируются от большего с меньшему СРАЗУ
    pq.push(34);
    pq.push(342);
    pq.push(4);

    cout << "len=" << pq.size() << endl;
    cout << "print full priority_queue" << endl;
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}


void stack_fun()
{
    /*
    адаптеры контейнеров
    stack - fifo
    */

    stack<int> st;

    // в стек можно положить лист, вектор и тп
    // stack<int, list<int>> st;

    st.push(4);
    st.push(42);
    st.emplace(43); // одинаковые

    st.size(); 
    st.top(); // узнать какой был последний элемент добавлен в стек
    // st.pop(); // удалить элемент
    cout << st.top() << endl;





    /*
    в стеке можно работать только с последнем элементом,
    поэтому циклом его нельзя перебрать

    можно обойти циклом, но
    посмотреть все элементы стека без извлечения нельзя

    иначе использовать контейнеры
    */
    /*
    !не работает
    auto a = st._Get_conteiner();
    cout<<a[1]<<endl;
    */

    cout<<"cycle"<<endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    
}


int main()
{
    // stack_fun();
    queue_fun();
    return 0;
}