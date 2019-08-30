#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "bus_if.h"

class Adapter : public sc_module, public bus_if
{
public:
  sc_out<int> x;
  sc_out<int> y;
  sc_in<int>  s;

  // Extra attributes
  unsigned start_addr1,
  start_addr2, start_addr3, block_size, status, data_temp;
  unsigned id;

  // Extra port to make it master
  sc_port<ext_bus_if,1> initiator_port;

  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );

  // sc event for triggering addition
  sc_event start_addition;

  void do_addition();

  SC_HAS_PROCESS(Adapter);

  Adapter( sc_module_name mn, unsigned id ) : sc_module(mn),  id(id)
  {
    SC_THREAD(do_addition);
    sensitive << start_addition;
    dont_initialize();
    //return; // alternative: export the bus_if here
  }

};

#endif
