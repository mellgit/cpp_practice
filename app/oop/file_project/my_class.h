#pragma once
/*
pragma once - защита от повторного включения (вложенность a.h в b.h + b.h в a.h), 
так же можно использовать условную компиляцию
тк это работает для всех компиляторов


пример условной компиляции - работает точно также как и pragma once
ifndef - if not defined (если не определено)

#ifndef _MY_CLASS_H_
#define _MY_CLASS_H_

#include <iostream>
namespace my_ns 
{
    class my_class
    {
    public:
        void print_msg(char str[]);   
    };
}

#endif

*/
namespace my_ns 
{
    class my_class
    {
    
    public:
        // void print_msg(const char str[]); // ++11
        void print_msg(char str[]);
        
    };


}

