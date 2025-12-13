#include "test_fifo.hpp"

void Fifo::func_a(){
    int count=0;
    while(true){
        f1.write(count);
        SC_PRINT("value:",count," is writen to f1 by write()");
        wait(1,SC_SEC);
        count+=1;
    }
}

void Fifo::func_b(){
    while(true){
        int count = f1.read();
        SC_PRINT("value:",count," is read from f1 by read()");
        wait(SC_ZERO_TIME);
        if(f2.nb_write(count)){
            SC_PRINT("value:",count," is nb_writen to f2 by nb_write()");
        }
        else{
            SC_PRINT("f2 is full");
            wait(f2.data_read_event());
            f2.nb_write(count);
            SC_PRINT("value:",count," is nb_writen to f2 by nb_write()");
        }
        wait(1,SC_SEC);
    }
}

void Fifo::func_c(){
    while(true){
        int count;
        if(f2.nb_read(count)){
            SC_PRINT("value:",count," is read from f2 by nb_read()");
        }
        else{
            SC_PRINT("f2 is empty");
            wait(f2.data_written_event());
            f2.nb_read(count);
            SC_PRINT("value:",count," is nb_writen to f2 by nb_write()");
        }
        wait(SC_ZERO_TIME);
        f2.write(count);
        SC_PRINT("value:",count," is nb_writen to f1 by write()");
        wait(1,SC_SEC);
    }
}
