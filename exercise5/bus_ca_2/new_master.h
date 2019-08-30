#ifndef _NEW_MASTER_H_
#define _NEW_MASTER_H_

#include "bus_if.h"

SC_MODULE(New_master)
{
  //sc_port<bus_if,1> initiator_port;

  sc_port<ext_bus_if,1> initiator_port;


  void action();
  SC_HAS_PROCESS(New_master);
  New_master( sc_module_name mn, unsigned ram1, unsigned ram2,
    unsigned ram3, unsigned size, unsigned id )
    : sc_module(mn), start_addr1(ram1),start_addr2(ram2), start_addr3(ram3),
      block_size(size),
    id(id)
  {
    SC_THREAD(action);
  }

private:
  unsigned id;
  // Extra variables
  unsigned start_addr1, start_addr2, start_addr3, block_size;
};

#endif
