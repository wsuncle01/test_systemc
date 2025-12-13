#include "test_semaphore.hpp"

void Semaphore::func_a(){
    while(true){
        if(s.trywait() == -1){
            SC_PRINT("hanged by semaphore.wait(), cur value is ",s.get_value());
            s.wait();
        }
        else{
            SC_PRINT("semaphore has resource, cur value is ",s.get_value());
        }
        wait(1,SC_SEC);
        s.post();
        SC_PRINT("resource has been released,cur value is ",s.get_value());
    }
}

void Semaphore::func_b(){
    while(true){
        if(s.trywait() == -1){
            SC_PRINT("hanged by semaphore.wait(), cur value is ",s.get_value());
            s.wait();
        }
        else{
            SC_PRINT("semaphore has resource, cur value is ",s.get_value());
        }
        wait(2,SC_SEC);
        s.post();
        SC_PRINT("resource has been released,cur value is ",s.get_value());
    }
}

void Semaphore::func_c(){
    while(true){
        if(s.trywait() == -1){
            SC_PRINT("hanged by semaphore.wait(), cur value is ",s.get_value());
            s.wait();
        }
        else{
            SC_PRINT("semaphore has resource, cur value is ",s.get_value());
        }
        wait(3,SC_SEC);
        s.post();
        SC_PRINT("resource has been released,cur value is ",s.get_value());
    }
}