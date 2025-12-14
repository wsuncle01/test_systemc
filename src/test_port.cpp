#include "test_port.hpp"

void TEST_PORT1::signal_gen(){
    while(true){
        p1->write(0);
        p2->write(1);
        sel->write(s);
        SC_PRINT("P1:",0," P2:",1," sel:",s);
        s+=1;
        wait();
    }
}

void TEST_PORT2::test_mux(){
    while(true){
        if(sel->read()%2==0){
            out->write(p1->read());
            SC_PRINT("Choose P1:",p1->read()," sel:",sel->read());
        }
        else{
            out->write(p2->read());
            SC_PRINT("Choose P2:",p2->read()," sel:",sel->read());
        }
        wait();
    }
}

void TEST_PORT3::get_output(){
    while(true){
        SC_PRINT("out:",p1->read());
        wait();
    }
}