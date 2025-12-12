#include <systemc>
#include "print.hpp"
#include "test_mutex.hpp"

using namespace sc_core;

int sc_main(int args_num, char* args_info[]) {
  Mutex mutex("mutex");
  sc_start(16,SC_SEC);
  return 0;
}
