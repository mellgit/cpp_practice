#include <iostream>
#include <iostream>
#include "my_class.h"
using namespace std;


// создание собственного namespace, чтобы не совпадало название методов, классов и тп
namespace my_ns 
{
    // void my_class::print_msg(const char str[]) // ++11
    void my_class::print_msg(char str[])
    {
        cout<<str<<endl;
    }

}
