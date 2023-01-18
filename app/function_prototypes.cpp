#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// прототипы функций
void test_prototypes(string name);
void default_args(int a, int b=2) ;

int main()
{
    string name = "Bob";
    test_prototypes(name);
    
    
    int a = 5;
    default_args(a);
    default_args(a, 3);
    return 0;
}

void test_prototypes(string name){

    cout<<"Hello "<<name<<endl;
}


void default_args(int a, int b){
// аргументы по умолчанию всегда идут последними, перед обычными аргументами
// в фу-и прототип передается значение по умолчанию
// при объявлении прот.фу-и аргумент по умолчанию не передается

    cout<<a<<"^"<<b<<" = "<<pow(a,b)<<endl;
}