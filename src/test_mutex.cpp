#include "test_mutex.hpp"

void Mutex::func_a(){
    while(true){
        if(m.trylock() == -1){
            m.lock();
            PRINT("<",this->name(),":",__FUNCTION__,"@",sc_time_stamp(),">: ","m is locked by lock()");
        }
        else{
            PRINT("<",this->name(),":",__FUNCTION__,"@",sc_time_stamp(),">: ","m is locked by trylock()");
        }
        wait(2,SC_SEC);
        m.unlock();
        PRINT("<",this->name(),":",__FUNCTION__,"@",sc_time_stamp(),">: ","m is unlocked by unlock()");
        wait(SC_ZERO_TIME);
    }
}

void Mutex::func_b(){
    while(true){
        if(m.trylock() == -1){
            m.lock();
            PRINT("<",this->name(),":",__FUNCTION__,"@",sc_time_stamp(),">: ","m is locked by lock()");
        }
        else{
            PRINT("<",this->name(),":",__FUNCTION__,"@",sc_time_stamp(),">: ","m is locked by trylock()");
        }
        wait(3,SC_SEC);
        m.unlock();
        PRINT("<",this->name(),":",__FUNCTION__,"@",sc_time_stamp(),">: ","m is unlocked by unlock()");
        wait(SC_ZERO_TIME);
    }
}