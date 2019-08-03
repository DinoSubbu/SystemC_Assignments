#ifndef _MASTER_EXTRA_H_
#define _MASTER_EXTRA_H_

#include "bus_if.h"

SC_MODULE( Master_Extra )
{
  sc_port<bus_if,1> initiator_port;
  void action();
  unsigned start, end, id;
  SC_HAS_PROCESS(Master_Extra);
  Master_Extra( sc_module_name mn, unsigned master_no)
  : sc_module( mn ), id(master_no)
  {
    SC_THREAD(action);
  }
};

#endif
