#include <iostream>
#include "sum.h"
#include "my_class.h"
using namespace std;
// using namespace my_ns; // созданное пространство можно использовать и так


void test_my_class()
{
    my_ns::my_class a;
    a.print_msg("hello msg");
    
    
}

void test_sum_fun()
{
    int a; 
    int b;
    cout<<"enter a: ";
    cin>>a;
    cout<<"enter b: ";
    cin>>b;
    cout<<"result: "<<sum_fun(a, b)<<endl;
}

int main()
{
    cout<<"=========== begin ==========="<<endl;
    // test_sum_fun();
    test_my_class();
    cout<<__cplusplus<<endl;
    return 0;
}