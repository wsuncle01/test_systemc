#include "test_mutex.hpp"

void Mutex::func_a(){
    while(true){
        if(m.trylock() == -1){
            m.lock();
            SC_PRINT("m is locked by lock()");
        }
        else{
            SC_PRINT("m is locked by trylock()");
        }
        wait(2,SC_SEC);
        m.unlock();
        SC_PRINT("m is unlocked by unlock()");
        wait(SC_ZERO_TIME);
    }
}

void Mutex::func_b(){
    while(true){
        if(m.trylock() == -1){
            m.lock();
            SC_PRINT("m is locked by lock()");
        }
        else{
            SC_PRINT("m is locked by trylock()");
        }
        wait(3,SC_SEC);
        m.unlock();
        SC_PRINT("m is unlocked by unlock()");
        wait(SC_ZERO_TIME);
    }
}