#pragma once

#include <systemc>
#include "print.hpp"

using namespace sc_core;

SC_MODULE(TEST_PORT1){
    //clk
    sc_in_clk clk;

    //out port
    sc_port<sc_signal_out_if<int>> p1;
    sc_port<sc_signal_out_if<int>> p2;
    sc_port<sc_signal_out_if<int>> sel;

    //in port
    
    //signal
    int s=0;

    //method
    SC_CTOR(TEST_PORT1){
        SC_THREAD(signal_gen);
        sensitive << clk.pos();
        dont_initialize();
    }
    void signal_gen();
};

SC_MODULE(TEST_PORT2){
    //clk
    sc_in_clk clk;

    //out port
    sc_port<sc_signal_out_if<int>> out;

    //in port
    sc_port<sc_signal_in_if<int>> p1;
    sc_port<sc_signal_in_if<int>> p2;
    sc_port<sc_signal_in_if<int>> sel;

    //signal

    //method
    SC_CTOR(TEST_PORT2){
        SC_THREAD(test_mux);
        sensitive << clk.pos();
        dont_initialize();
    }
    void test_mux();
};

SC_MODULE(TEST_PORT3){
    //clk
    sc_in_clk clk;

    //out port

    //in port
    sc_port<sc_signal_in_if<int>> p1;

    //signal

    //method
    SC_CTOR(TEST_PORT3){
        SC_THREAD(get_output);
        sensitive << clk.pos();
        dont_initialize();
    }
    void get_output();
};