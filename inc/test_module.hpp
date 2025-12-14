#pragma once

#include <systemc>
#include "print.hpp"

SC_MODULE(MODULE_2){
    SC_CTOR(MODULE_2){
        SC_PRINT("");
    }
};

SC_MODULE(MODULE_1){
    SC_CTOR(MODULE_1){
        SC_PRINT("");
        MODULE_2 m2_1("m2_1");
        MODULE_2 m2_2("m2_2");
    }
};

