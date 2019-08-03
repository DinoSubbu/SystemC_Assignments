#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "bus_if.h"

// It's an interface bus
class Adapter : public sc_module, public bus_if
{
public:
  sc_export<bus_if> adapter_export;
  sc_out <int> adapter_x, adapter_y;
  sc_in <int> adapter_s;
  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );

  //void end_of_elaboration();
  //unsigned *starts, *ends;
  Adapter( sc_module_name mn )
  : sc_module(mn)
  {
    adapter_export.bind(*this);
  }
};

#endif
