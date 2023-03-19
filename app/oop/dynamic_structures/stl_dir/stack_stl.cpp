#include <iostream>
#include <vector>
#include <stack>
using namespace std;


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
    stack_fun();
    return 0;
}