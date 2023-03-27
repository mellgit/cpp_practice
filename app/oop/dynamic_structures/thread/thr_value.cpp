#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


int sum_for_time_measurement(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    
    cout << " thr_id="<< this_thread::get_id() << " ==== sum start ====" << endl;
    
    this_thread::sleep_for(chrono::milliseconds(5000));
    
    cout << " thr_id="<< this_thread::get_id() << " ==== sum end ====" << endl;
    
    return a+b;   
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

void time_measurement()
{
    /*
    измерение времени работы программы
    в #include <thread> уже есть chrono, если потоки не нужны, то можно использовать только chrono

    начало отсчета - auto start = chrono::high_resolution_clock::now();
    конец отсчета - auto end = chrono::high_resolution_clock::now();
    разница - chrono::duration<float> duration = end - start;
    */
    auto start = chrono::high_resolution_clock::now();

    int result;
    // тк sum_for_time_measurement выполняется в другом потоке, работать все будет быстрее чем в одном потоке
    thread t([&result](){result = sum_for_time_measurement(3,6);}); // 7 sec
    // result = sum_for_time_measurement(3,6); // 12 sec

    for (size_t i = 0; i < 10; i++) 
    {
        this_thread::sleep_for(chrono::milliseconds(500)); 
        cout << this_thread::get_id() << " - thr_fun " << i << endl; // номер потока
    }

    t.join();
    cout<<"result = "<<result<<endl;
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout<<"time program: "<<duration.count()<<"s"<<endl;

    //! using timer from class
    SimpleTimer st; 
    cout<<"using timer from class"<<endl;
    int result2;
    thread t2([&result2](){result2 = sum_for_time_measurement(3,6);}); 

    for (size_t i = 0; i < 10; i++) 
    {
        this_thread::sleep_for(chrono::milliseconds(500)); 
        cout << this_thread::get_id() << " - thr_fun " << i << endl; // номер потока
    }

    t2.join();
    cout<<"result = "<<result2<<endl;

}

int sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    cout << " thr_id="<< this_thread::get_id() << " ==== sum start ====" << endl;
    
    this_thread::sleep_for(chrono::milliseconds(2000));
    
    cout << " thr_id="<< this_thread::get_id() << " ==== sum end ====" << endl;
    
    return a+b;
    
}

void anon_fun_thread()
{
    /*
    вернуть значение из потока при помощи анонимной ф-и
    */

    int result;
    thread t([&result](){result = sum(3,6);});

    for (size_t i = 0; i < 10; i++) 
    {
        this_thread::sleep_for(chrono::milliseconds(500)); 
        cout << this_thread::get_id() << " - thr_fun " << i << endl; // номер потока
    }

    t.join();
    cout<<"result = "<<result<<endl;

}

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
    // return_thr_value();
    // anon_fun_thread();
    time_measurement();
    return 0;
}