#include <iostream>
#include <string>
using namespace std;

void interface();
void virtual_inheritance();
void virtual_inheritance_2();

int main()
{
    // interface();
    virtual_inheritance();
    cout<<endl<<"________________________"<<endl;
    virtual_inheritance_2();
    return 0;
}

class Character
{
public:
    int HP;
    Character()
    {
        cout << "constuctor Character" << endl;
        
    }
};

class Orc : public virtual Character
{
public:
    Orc()
    {
        cout << "constructor Orc" << endl;
    }
};

class Warrior : public virtual Character
{
public:
    Warrior()
    {
        cout << "constructor Warrior" << endl;
    }
};

class OrcWarrior : public Orc, public Warrior
{
public:
    OrcWarrior()
    {
        cout << "constructor OrcWarrior" << endl;
    }
};

void virtual_inheritance_2()
{
    /*
    ромбовидное наследование
    позволяет двум наследникам использовать один экземпляр класса родителя
    тк при инициализации отрабатывают конструкторы Memory и GPU (родитель Comnonent)
    то каждый из них имеет свой экземпляр класса Component,
    иногда так делать необходимо, иногда нет

    пример без использование виртуального наследования:
        constuctor Component
        constructor GPU
        constuctor Component
        constructor Memory
        constructor GraphicCard

    для того, чтобы конструктор класса родителя не был вызван дважды
    используют ромбовидное наследование при помощи виртуального наследования
    в примере класса Character
    наследники Character это Orc и Warrior они наследуются виртуально,
    засчет этого повторное использование конструктора класса родителся (Character)
    не будет реализовано

    пример с использованием виртуального наследования:

        constuctor Character
        constructor Orc
        constructor Warrior
        constructor OrcWarrior

    ромбовидное наследование используется от задачи
    */
    OrcWarrior ow;
}

class Component
{
public:
    string company_name;
    Component(string company_name)
    {
        cout << "constuctor Component" << endl;
        this->company_name = company_name;
    }
};

class GPU : public Component
{
public:
    GPU(string company_name) : Component(company_name)
    {
        cout << "constructor GPU" << endl;
    }
};

class Memory : public Component
{
public:
    Memory(string company_name) : Component(company_name)
    {
        cout << "constructor Memory" << endl;
    }
};

class GraphicCard : public GPU, public Memory
{
public:
    GraphicCard(string GPU_company_name, string Memory_company_name) : GPU(GPU_company_name), Memory(Memory_company_name)
    {
        cout << "constructor GraphicCard"<<endl;
    }
};

void virtual_inheritance()
{
    /*
    ромбовидное наследование
    позволяет двум наследникам использовать один экземпляр класса родителя
    тк при инициализации отрабатывают конструкторы Memory и GPU (родитель Comnonent)
    то каждый из них имеет свой экземпляр класса Component,
    иногда так делать необходимо, иногда нет, 
    для того, чтобы конструктор класса Component не был вызван дважды
    используют ромбовидное наследование при помощи виртуального наследования
    */
    GraphicCard gc("amd", "sumsung");
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