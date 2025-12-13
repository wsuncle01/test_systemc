#pragma once

#include <systemc>
#include "print.hpp"

using namespace sc_core;

SC_MODULE(Fifo){
    sc_fifo<int> f1,f2;
    SC_CTOR(Fifo) : f1(4), f2(3){
        SC_THREAD(func_a);
        SC_THREAD(func_b);
        SC_THREAD(func_c);
    }
    void func_a();
    void func_b();
    void func_c();
};