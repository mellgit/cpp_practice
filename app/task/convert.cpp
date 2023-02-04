#include <iostream>
#include <string>
using namespace std;

int string_to_number(const std::string &s)
{
    cout<<s<<endl;
    // 45 -> -
    // 48 - 57
    // cout<<"char = "<<(char)48<<endl;
    int len = s.length();
    
    for (int i = 0; i < len; i++)
    {
        // if (s[i] == '-')
        // {
        //     continue;
        // }
        
        if ((char)48 < s[i] < (char)57)
        {
            cout<<s[i]<<endl;
        }
        
    }
    
    
    

    return 0;
}

int main()
{
    cout<<"================= BEGIN ================="<<endl;
    string number = "1234";
    string_to_number(number);
    // cout<<string_to_number(number)<<endl;
    return 0;
}