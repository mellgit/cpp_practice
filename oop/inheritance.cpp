#include <iostream>
#include <string>
using namespace std;


void inher();
void access_modifiers();
void constructor_call_order();
void call_basick_constr();


int main()
{
    // inher();
    // access_modifiers();
    // constructor_call_order();
    call_basick_constr();
    return 0;
}



class A_cls
{
private:
    string msg;
public:
    A_cls()
    {
        msg = "empty msg";
    }

    A_cls(string msg)
    {
        this->msg = msg;
    }
    void print()
    {
        cout<<msg<<endl;
    }
};

class B_cls : public A_cls
{
public:
    B_cls():A_cls("world")
    {
        /*
        если необходимо вызвать конструктор по умолчанию - B:A()
        но это уже и так делает компилятор, поэтому явно указывать не нужно
        если конструкторов несколько - B:A(args)
        передать необходимые аргументы и таким образов вызовут другой конструктор 
        */
        
    }
};


void call_basick_constr()
{
    A_cls a("hello");
    a.print();
    cout<<"___________"<<endl;
    B_cls b;
    b.print();
}

class One
{
public:
    One()
    {
        cout<<"call const one"<<endl;
    }
    ~One()
    {
        /*
        вызов деструкторов происходит в обратном порядке
        constr - 1 2 3
        destr - 3 2 1
        */
        cout << "call destructor one" << endl;
        cout << "========================" << endl;
    }
};

class Two : public One
{
public:
    Two()
    {
        cout << "call const two" << endl;
    }
    ~Two()
    {
        cout << "call destructor two" << endl;
    }
};

class Three : public Two
{
public:
    Three()
    {
        cout << "call const three" << endl;
    }
    ~Three()
    {
        cout << "call destructor three" << endl;
        
    }
};

void constructor_call_order()
{
    One one; // const one
    cout << "______________" << endl;
    Two two; // const one and const two
    cout << "______________" << endl;
    Three three; // const one and const two and const three
    cout << "______________" << endl;
}



class A
{
public:
    /*
    доступен всем и везде, также и вне класса на уровне объекта 
    */
    string one_msg = "one";
private:
    /*
    скрыт от всех и никому не доступно
    */
    string two_msg = "two";

protected:
    /*
    на уровне объекта вызвать нельзя, но в дочерних вызвать можно
    */
    string three_msg = "three";
};

class B : public A
{
    /*
    уровень доступа для дочерних
               public  private  protected
    public     pub     pri      pro
    private    pri     pri      pri
    protected  pro     pri      pro
    в завесимости от уровня доступа, меняются свойства доступа родителя
    */
public:
    void print_one()
    {
        cout<<one_msg<<endl;
    }

    void print_three()
    {
        cout << three_msg << endl;
    }
};

void access_modifiers()
{
    B b;
    b.print_one();
    b.print_three();
}



class Human
{
private:
    string name;
public:
    string get_name()
    {
        return name;
    }
    void set_name(string name)
    {
        this->name = name;
    }
};


class Student : public Human
{
    /*
    если у класса родителя есть pivate секция, то у дочерних она тоже есть
    но доступ из дочерних в родительский, так же закрыт
    */
public:
    string group;

    void learn()
    {
        cout<<"learn"<<endl;
    }
};

class Extramural_student : public Student
{
public:
    void learn()
    {
        cout<<"slow learn"<<endl;
    }
};


class Professor : public Human
{
public:
    
    string subject;
};

void inher()
{
    Student st;
    st.learn();
    st.set_name("bob");
    cout<<st.get_name()<<endl;

    cout<<"================="<<endl;

    Extramural_student ex_st;
    ex_st.learn();
    ex_st.set_name("rob");
    cout<<ex_st.get_name()<<endl; 

}