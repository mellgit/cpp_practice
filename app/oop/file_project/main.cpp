#include <iostream>
#include "sum.h"
using namespace std;

int main()
{
    int a; 
    int b;
    cout<<"enter a: ";
    cin>>a;
    cout<<"enter b: ";
    cin>>b;
    cout<<"result: "<<sum_fun(a, b)<<endl;
    return 0;
}