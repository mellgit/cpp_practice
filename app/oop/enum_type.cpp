#include <iostream>
#include <string>
using namespace std;


void enum_function();


int main()
{
    enum_function();
    return 0;
}



class PC
{

public:
    enum PCState
    {
        //тут хранятся числа от 0 до N(N - количество значений в enum)
        OFF,
        ON,
        SLEEP,
        TIMER = 30 // значения можно устанавливать по необходимости
    };

    PCState get_state(){return state;}
    void set_state(PCState state)
    {
        this->state = state;
     }

private:
    PCState state;
};


void enum_function()
{
    /*
    enum - тип перечисления
    */

    PC pc;
    pc.set_state(PC::PCState::OFF);

    // применять можно в if
    if (pc.get_state() == PC::PCState::ON)
    {
        cout<<"PC on"<<endl;
    }

    // применять можно в switch
    switch (pc.get_state())
    {
    case PC::PCState::ON:
        cout<<"pc on"<<endl;
        break;
    case PC::PCState::OFF:
        cout << "pc off" << endl;
        break;
    case PC::PCState::SLEEP:
        cout << "pc sleep" << endl;
        break;

    default:
        break;
    }
    

    // определение состояния текстом, для разработчика
    // PCState s;
    // s = PCState::OFF;
}