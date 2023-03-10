#include <iostream>
#include <string>
using namespace std;


void test_override();
void abstract_class();
void virtual_destructor();
void pure_virtual_destructor();

int main()
{
    // test_override();
    // abstract_class();
    // virtual_destructor();
    pure_virtual_destructor();
    return 0;
}


class One
{
public:
    One()
    {

    }
    virtual ~One() = 0;
    
};

One::~One() {};

class Two : public One
{
public:
    Two()
    {
    }
    ~Two()
    {
    }
};


void pure_virtual_destructor()
{
    /*
    чисто виртуальный диструктор
    объект класса родителя объявить не получится,
    но передать ссылку родителя для дочки можно,
    только в том случае, если вынести виртуальный диструктор вне класса
    One::~One() {};

    */
    One *oneptr = new Two;

    delete oneptr;
}




class A
{
public:
    A()
    {
        cout<< "dedicated dynamic memory  A class" << endl;
    }
    virtual ~A()
    {
        cout << "freed dynamic memory A class" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "dedicated dynamic memory  B class" << endl;
    }
    ~B() override
    {
        cout << "freed dynamic memory B class" << endl;
    }
};


void virtual_destructor()
{
    /*
    таким образом реализовалась утечка памяти для класса наследника
    память для родителя освободилась, а для дочки нет
    output:
        dedicated dynamic memory  A class
        dedicated dynamic memory  B class
        freed dynamic memory A class

    если использовать витруальный диктруктор, то все отработает правильно
    output:
        dedicated dynamic memory  A class
        dedicated dynamic memory  B class
        freed dynamic memory B class
        freed dynamic memory A class
    
    тк диструктор родителя стал виртуальным, память дочки так же освободилась 
    */
    A *bptr = new B;
    
    delete bptr;

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