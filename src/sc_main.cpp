#include <systemc>
#include "print.hpp"
#include "test_mutex.hpp"
#include "test_semaphore.hpp"
#include "test_fifo.hpp"
#include "test_port.hpp"

using namespace sc_core;

int sc_main(int args_num, char* args_info[]) {
  sc_clock clk("clk", 1, SC_SEC, 0.5, 1, SC_SEC, false);
  // Mutex mutex("mutex");
  // Semaphore semaphore("semaphore");
  // Fifo fifo("fifo");
  TEST_PORT1 producer("producer");
  TEST_PORT2 consumer("consumer");
  TEST_PORT3 checker("checker");

  producer.clk(clk);
  consumer.clk(clk);
  checker.clk(clk);
  sc_signal<int> p2; 
  sc_signal<int> p1;
  sc_signal<int> out; 
  sc_signal<int> sel;

  producer.p1(p1);
  consumer.p1(p1);
  
  producer.p2(p2);
  consumer.p2(p2);

  producer.sel(sel);
  consumer.sel(sel);

  consumer.out(out);
  checker.p1(out);

  sc_start(16,SC_SEC);
  return 0;
}
