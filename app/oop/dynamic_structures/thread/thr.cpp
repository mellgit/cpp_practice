#include <iostream>
#include <thread> // потоки
#include <chrono> // время
using namespace std;


void do_work()
{
    for (size_t i = 0; i < 10; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));     // time.sleep(1)
        cout << this_thread::get_id() << " - do_work " << i <<endl; // номер потока
    }
}

void thr_fun()
{

    cout << "start time" << endl;
    this_thread::sleep_for(chrono::milliseconds(500)); // time.sleep(1) - одна секунда
    cout << this_thread::get_id() << endl; // номер потока
    cout << "end time" << endl;

    thread th(do_work); // передача указателя на ф-ю, без скобок, тк это вызов ф-и
    thread th2(do_work); // создание еще одного потока
    /*
    выполняется до того момента, как отработает основной поток
    do_work sleep 1 sec
    thr_fun sleep 0.5 sec
    на данный момент thr_fun отработает быстрее,
    что в свою очередь не даст завершить do_work

    если не указывать detach или join то выпадет ошибка и  программа закроется
    через другой поток, одно из двух необходимо использовать в зависимости от задачи
    */
    // th.detach();

    for (size_t i = 0; i < 10; i++) // size_t - unsigned long int(псевдоним)
    {
        this_thread::sleep_for(chrono::milliseconds(500)); // time.sleep(0.5)
        cout << this_thread::get_id() << " - thr_fun " << i << endl; // номер потока
    }

    /*
    позволяет дождаться, пока все выполнится
    указывать join нужно в том месте, где необходимо дождаться завершения
    если указать join сразу после thread th(do_work), то все отработает поочереди
    но в разных потоках

    в таком случае задачи выполняются параллельно
    */
    th.join();
    th2.join();
}

int main()
{
    thr_fun();
    return 0;
}