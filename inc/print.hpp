#pragma once

#include <stdarg.h>
#include <iostream>

#define PRINT(X...) \
    do{\
        sc_print::show(X);\
        std::cout<<std::endl;\
    } while(0);

#define PRINT_CONCAT(X...) \
    do{\
        sc_print::show(X);\
    } while(0);


#define SC_PRINT(X...) \
    do{\
        PRINT_CONCAT("<",this->name(),":",__FUNCTION__,"@",sc_time_stamp(),">: ");\
        PRINT(X);\
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
