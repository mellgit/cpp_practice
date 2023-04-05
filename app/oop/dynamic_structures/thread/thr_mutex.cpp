#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;


mutex mtx;


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
    SimpleTimer st;
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

int main()
{
    // mutex_fun();
    lock_guard_mutex();
    return 0;
}