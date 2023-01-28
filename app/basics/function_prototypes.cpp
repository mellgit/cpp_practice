#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// прототипы функций
void test_prototypes(string name);
void default_args(int a, int b=2) ;
int fact(int n);
int fact2(int n);

// шаблонная функция, может работать только с одним типом (int or double)
// template <class T> из c++
template <typename T> // из c (разницы нет)
// void sum(T a, T b) - можно не возвращать значения
T sum(T a, T b)
{
    return a+b;
}

// шалон может работать одновременно с разными типами (int and double)
template <typename T1, typename T2>
T1 sub(T1 a, T2 b)
{
    return a - b;
}

int main()
{
    // string name = "Bob";
    // test_prototypes(name);
    
    // int a = 5;
    // default_args(a);
    // default_args(a, 3);

    // cout<<sum(5,9)<<endl;
    // cout << sum(5.3, 9.4) << endl;
    // cout << sub(5, 9.3) << endl;

    cout << fact(0)<< endl;
    cout << fact2(0) << endl;

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

int fact2(int n){
    int temp = 0;
    int temp1 = 1;
    if (n==0){
        return 0;
    }
    while (n>=2)
    {
        temp = n * (n-1);
        temp1*=temp;
        n = n-2;
    }
    return temp1;
    
}

int fact(int n){

    if (n==1){
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    return n * fact(n-1);
}