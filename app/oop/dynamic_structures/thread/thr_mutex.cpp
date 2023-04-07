#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;


mutex mtx;

mutex mtx1;
mutex mtx2;

recursive_mutex rm;


void foo(int a)
{
    rm.lock();
    cout<<a<<" ";

    this_thread::sleep_for(chrono::milliseconds(200));

    if(a<=1)
    {
        cout<<endl;
        rm.unlock();
        return; // выход из ф-и

    }
    a--;
    foo(a);
    rm.unlock();
}


void recursive_mutex_fun()
{
    /*
    recursive_mutex - рекурсивная блокировка 
    захват рекурсивного mtx может происходить несколько раз, 
    но освобождать придется столько же раз

    exp:
    rm.lock();
    rm.lock();

    rm.unlock();
    rm.unlock();

    если вместо rm использовать mtx в потоке, 
    то получится, что в одном потоке возвался дважды один и тотже mtx,
    что приведет к ошибке
    */

    thread t1(foo, 10);
    thread t2(foo, 10);

    t1.join();
    t2.join();

    
}

void print_1(char ch)
{
    /*
    this_thread::sleep_for(chrono::milliseconds(1)); - остановка на одну милисекунду нужна
    для того, чтобы поток 2 успел взять данные для потока 1, иначе не получить взяимной блокировки
    тк поток 1 все равно запускается раньше, но это работает не всегда
    программа может, как заработать, так и не заработать 

    проблема взаимной блокировки
    mtx2.lock();
    this_thread::sleep_for(chrono::milliseconds(1));
    mtx1.lock();

    решение взаимной блокировки (выполнен правильный порядок захвата mtx)
    mtx1.lock();
    this_thread::sleep_for(chrono::milliseconds(1));
    mtx2.lock();
    */
    mtx1.lock();
    this_thread::sleep_for(chrono::milliseconds(1));
    mtx2.lock();

    
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
    mtx1.unlock();
    mtx2.unlock();

}

void print_2(char ch)
{
    /*
    
    */
    mtx1.lock();
    this_thread::sleep_for(chrono::milliseconds(1));
    mtx2.lock();

    
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
    mtx1.unlock();
    mtx2.unlock();

}

void dead_lock_mtx()
{
    /*
    dead lock - взаимная блокировка, когда поток 1 взял данные потока 2, а поток 2 взял данные потока 1
    и они оба не могу начать действовать, тк нет необходимых данных для работы

    чтобы избежать такой проблемы, необходимо заранее позаботиться о том, какой поток
    в какой момент времени будет делать, те сначала дать данные потока 1 на потока 1, 
    а потом данные потока 2 на поток 2
    те, соблюдать порядок захвата mtx
    */
    thread t(print_1, '#');
    thread t2(print_2, '@');

    t.join();
    t2.join();
    
}


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

void print_lock_guard(char ch)
{
    /*
    комментарий 1 - в таком случае, mtx закроется как только закончится область
    видимости этого mtx, те в конце ф-и, но иногда необходимо использовать mtx только в 
    определенных частях ф-и, для этого используется отдельный namespace прямо в ф-и

    комментарий 2 - выделенный namespace для mtx
    */
    this_thread::sleep_for(chrono::milliseconds(2000));

    // lock_guard<mutex> guard(mtx); // комментарий 1
    {
        // комментарий 2
        lock_guard<mutex> guard(mtx);
        for (int i=0; i<=5; i++)
        {
            for (int j=0; j<=5; j++)
            {
                cout<<ch;
                this_thread::sleep_for(chrono::milliseconds(20));
            }   
            cout<<endl;
        }
    }
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

}

void lock_guard_mutex()
{
    /*
    класс lock_guard - передача mutex в конструктор класса, использование его в классе
    и при вызове диструктора, mutex уничтожается

    после открытия mutex всегда необходимо его закрыть, класс lock_guard решает эту проблему
    */
    thread t(print_lock_guard, '#');
    thread t2(print_lock_guard, '@');

    t.join();
    t2.join();
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


class SimpleTimer
{
public:
    /*
        чтобы не писать постоянно счетчики времени, проще описать класс для таймера
        при объявлении объекта класса SimpleTimer в ф-и, запуститься таймер
        как только ф-я закончит свое действие вызовится деструктор, в котором будет результат выполнения

    */
    SimpleTimer()
    {
        start = chrono::high_resolution_clock::now();
    }
    ~SimpleTimer()
    {
        end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        cout<<"duration time: "<<duration.count()<<"s"<<endl;
    }
private:
    // std::chrono::_V2::system_clock::time_point std::chrono::_V2::system_clock::now() - что возвращает метдо now()
    // chrono::time_point<chrono::steady_clock> start, end; // неотработало
    chrono::_V2::system_clock::time_point start, end; // отработало
};


int main()
{
    SimpleTimer st;
    // mutex_fun();
    // lock_guard_mutex();
    // dead_lock_mtx();
    recursive_mutex_fun();
    return 0;
}