#include <iostream>
#include <string>
#include <thread>
using namespace std;


class MyClass
{
private:
    /* data */
public:
    void do_work()
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
    
        cout << " thr_id="<< this_thread::get_id() << " ==== do_work start ====" << endl;
        
        this_thread::sleep_for(chrono::milliseconds(1000));
        
        cout << " thr_id="<< this_thread::get_id() << " ==== do_work end ====" << endl;
    }

    void do_work2(int a)
    {
        this_thread::sleep_for(chrono::milliseconds(2500));
    
        cout << " thr_id="<< this_thread::get_id() << " ==== do_work2 start ====" << endl;
        
        this_thread::sleep_for(chrono::milliseconds(2000));

        cout<<"do_work2 value: "<<a<<endl;
        
        cout << " thr_id="<< this_thread::get_id() << " ==== do_work2 end ====" << endl;
    }

    int sum(int a, int b)
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        
        cout << " thr_id="<< this_thread::get_id() << " ==== sum start ====" << endl;
        
        this_thread::sleep_for(chrono::milliseconds(1000));
        
        cout << " thr_id="<< this_thread::get_id() << " ==== sum end ====" << endl;
        
        return a+b;   
    }
};

void thr_class2()
{
    /*
    использование метод класса, который НЕ возвращает значение
    thread t(&ссылка_на_класс::вызываемый_метод, объект_класса);

    использование метод класса, который НЕ возвращает значение, но принимает параметры
    thread t(&ссылка_на_класс::вызываемый_метод, объект_класса, принимаемый_параметр);

    можно либо создавать лямбда ф-и, либо использовать метод выше
    */

    MyClass m;
    
    thread t(&MyClass::do_work, m);
    thread t2(&MyClass::do_work2, m,3);

    for (size_t i = 1; i < 10; i++) 
    {
        this_thread::sleep_for(chrono::milliseconds(500)); 
        cout << this_thread::get_id() << " - thr_class " << i << endl; // номер потока
    }

    t.join();
    t2.join();

}


void thr_class()
{
    /*
    использование метод класса, который возвращает значение
    */

    int result;
    MyClass m;
    

    thread t([&]()
    {
        result = m.sum(2,4);
    });

    for (size_t i = 1; i < 10; i++) 
    {
        this_thread::sleep_for(chrono::milliseconds(500)); 
        cout << this_thread::get_id() << " - thr_class " << i << endl; // номер потока
    }

    t.join();
    cout<<"result sum: "<<result<<endl;
}

int main()
{
    // thr_class();
    thr_class2();
    return 0;
}