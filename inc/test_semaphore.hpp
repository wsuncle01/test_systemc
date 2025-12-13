#pragma once

#include <systemc>
#include "print.hpp"

using namespace sc_core;

SC_MODULE(Semaphore){
    sc_semaphore s;
    SC_CTOR(Semaphore) : s(2){
        SC_THREAD(func_a);
        SC_THREAD(func_b);
        SC_THREAD(func_c);
    }
    void func_a();
    void func_b();
    void func_c();
};