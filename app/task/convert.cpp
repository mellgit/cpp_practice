#include <iostream>
#include <string>
using namespace std;

int string_to_number(const std::string &s)
{
    // stoi() - преобрабразование строки в число
    return stoi(s);
}

int main()
{
    cout<<"================= BEGIN ================="<<endl;
    string number = "-1234";
    
    cout<<string_to_number(number)<<endl;
    return 0;
}