#include <iostream>
#include <string>
using namespace std;

void interface();


int main()
{
    interface();
    return 0;
}

class IBicycle
{
    //абстрактный класс - если есть хотя бы одна виртуальныя ф-я
public:
    void virtual twist_the_wheel() = 0;
    void virtual ride() = 0;
};

class SimpleBicycle : public IBicycle
{
public:
    void twist_the_wheel() override
    {
        cout << "call twist simple bicycle" << endl;
    }
    void ride() override
    {
        cout << "call ride simple bicycle" << endl;
    }
};

class SportBicycle : public IBicycle
{
public:
    void twist_the_wheel() override
    {
        cout << "call twist sport bicycle" << endl;
    }
    void ride() override
    {
        cout << "call ride sport bicycle" << endl;
    }
};

class Human
{
public:
    void ride_on(IBicycle & bicycle)
    {
        cout << "twist the wheel"<<endl;
        bicycle.twist_the_wheel();
        cout << "ride"<<endl;
        bicycle.ride();
    }
};


void interface()
{
    /*
    интерфейсы нужно для определения чего одного схожено у двух объектов
    пример с простым велосипедом и спортивном
    если на простом найчился кататься, то и на спортивном получится
    тк подход(интерфейс) к реализации один и тот же
    */
    SimpleBicycle sb;
    SportBicycle sportb;

    Human h;
    h.ride_on(sb);
    cout<<endl;
    h.ride_on(sportb);
}