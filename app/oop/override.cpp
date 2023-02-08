#include <iostream>
#include <string>
using namespace std;


void test_override();

int main()
{
    test_override();
    return 0;
}

class Gun
{
public:
    virtual void shoot()
    {
        /*
        virtual необходим для полиморфизма, чтобы рассширить функционал
        данного метода в другом классе
        */
        cout<<"bang"<<endl;
    }
};

class Submachine_Gun : public Gun
{
public:
    void shoot() override
    {
        /*
        override - необязательный функционал для полиморфизма
        но его необходимо использовать, тк в случае ошибки (неправильное имя метода, тип возвращаемого значение и тд)
        override подскажет, что эта уже совсем другой метод, а не переопределенный от
        базового класса

        virtual(в родительском классе) и override(в дочернем классе)
        */
        cout<<"bang bang"<<endl;
    }
};

class Bazooka : public Gun
{
public:
    void shoot() override
    {
        cout<<"badaboom"<<endl;
    }
};

class Player
{
public:
    void shoot(Gun *gun)
    {
        gun->shoot();
    }
};


void test_override()
{
    Gun gun;
    Submachine_Gun machine_gun;
    Bazooka bazooka;

    /*
    пример использования полиморфизма
    для переопределенного метода shoot
    */
    Player player;
    player.shoot(&machine_gun);
    player.shoot(&gun);
    player.shoot(&bazooka);
}