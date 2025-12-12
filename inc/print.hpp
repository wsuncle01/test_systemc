#pragma once

#include <stdarg.h>
#include <iostream>

#define PRINT(X...) \
    do{\
        sc_print::show(X);\
        std::cout<<std::endl;\
    } while(0);

namespace sc_print{
    template <typename T>
    void show(T first_data){
        std::cout << first_data;
    }
    template <typename T,typename ...Others>
    void show(T first_data,Others ...other_data){
        show(first_data);
        show(other_data...);
    }
};
