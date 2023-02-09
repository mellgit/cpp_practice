#include <iostream>
#include <string>
using namespace std;


void test_override();
void abstract_class();

int main()
{
    // test_override();
    abstract_class();
    return 0;
}


class Weapon 
{
    /*
    класс имеет чисто фиртуальную ф-ю -> класс абстрактный
    */
public:
    virtual void shoot() = 0; // чисто виртуальная ф-я

    /*
    в абстрактом классе также могу быть и обычные методы
    они также будут у наследников
    */
    void function()
    {
        cout<<"call function"<<endl;
    }
};



class Gun : public Weapon
{
public:
    void shoot() override
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

class Bazooka : public Weapon
{
public:
    void shoot() override
    {
        cout<<"badaboom"<<endl;
    }
};


class Knife : public Weapon
{
public:
    void shoot() override
    {
        cout<<"vjuhh"<<endl;
    }
};


class Player
{
public:
    void shoot(Weapon *wepon)
    {
        wepon->shoot();
    }
};

void abstract_class()
{
    /*
    виртуальная фу-я это ф-я без реализации
    абстрактный класс имеет виртуальные фу-ии, следует, что нельзя создать экземпляр класса
    */

   Bazooka bazooka;
   Knife knife;
   Player player;
   player.shoot(&bazooka);
   player.shoot(&knife);
}

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
    // player.shoot(&machine_gun);
    // player.shoot(&gun);
    // player.shoot(&bazooka);
}