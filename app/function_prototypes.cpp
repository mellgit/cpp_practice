#include <iostream>
#include <string>
using namespace std;

// прототипы функций
void test_prototypes(string name);

int main()
{
    string name = "Bob";
    test_prototypes(name);
    return 0;
}

void test_prototypes(string name){

    cout<<"Hello "<<name<<endl;
}