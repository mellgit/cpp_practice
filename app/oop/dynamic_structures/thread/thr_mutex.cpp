#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;


mutex mtx;

void print(char ch)
{
    mtx.lock();
    for (int i=0; i<=5; i++)
    {
        for (int j=0; j<=5; j++)
        {
            cout<<ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }   
        cout<<endl;
    }
    cout<<endl;
    mtx.unlock();
}

void mutex_fun()
{
    /*
    mutex - синхронизация потоков (защита разделяемых данных, в момент изменения этих данных)
    флаг, который говорит, что ипользовать данные другими потоками, нельзя 
    
    mutex mtx; - инициализация mutex
    между mtx.lock() и mtx.unlock(), выполняется инструкция, которая
    не должна исопльзовать в других потоках, это означает, что
    пока выполняется конструкция, другие потоки ничего делать не могут

    mutex должны использовать по необходимости, в зависимости от задачи
    */
    thread t(print, '#');
    thread t2(print, '@');

    t.join();
    t2.join();
}

int main()
{
    mutex_fun();
    return 0;
}