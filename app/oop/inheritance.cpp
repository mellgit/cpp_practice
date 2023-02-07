#include <iostream>
#include <string>
using namespace std;


void inher();

int main()
{
    inher();
    return 0;
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