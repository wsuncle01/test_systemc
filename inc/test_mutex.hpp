#pragma once
#include <systemc>
#include "print.hpp"
using namespace sc_core;

SC_MODULE(Mutex){
    sc_mutex m;
    SC_CTOR(Mutex){
        SC_THREAD(func_a);
        SC_THREAD(func_b);
    }
    void func_a();
    void func_b();
};
