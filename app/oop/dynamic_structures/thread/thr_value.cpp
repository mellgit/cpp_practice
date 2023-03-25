#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


void do_work(int &a)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    cout << "==== do_work start ====" << " thr_id="<< this_thread::get_id() << endl;
    
    this_thread::sleep_for(chrono::milliseconds(2000));
    
    a*=2;
    
    cout << "==== do_work end ====" << " thr_id="<< this_thread::get_id() << endl;
    
}


void return_thr_value()
{
    /*
    возвращение значения из потока
    
    передача параметров по ссылке, в фу-ю без отдельного потока работает
    и переменная а изменится, но в потоке это работает не так
    int a = 4;
    do_work(a); // void do_work(int a&){...}
    cout<<a<<endl;

    в случае потока необходимо использовать std::ref(a) как параметр
    ref() - создает объект ссылки, который передается в отдельный поток

    */
    int a = 4;
    // do_work(a);

    thread t(do_work, std::ref(a));
    
    for (size_t i = 0; i < 10; i++) 
    {
        this_thread::sleep_for(chrono::milliseconds(500)); 
        cout << this_thread::get_id() << " - thr_fun " << i << endl; // номер потока
    }

    t.join();
    cout<<a<<endl;

}

int main()
{
    return_thr_value();
    return 0;
}