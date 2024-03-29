#include "new_master.h"

void New_master::action()
{
  unsigned data1, data2, result;
  wait(500, SC_NS);
  for( unsigned addr = 0; addr < 16; addr++ )
  {
    initiator_port->read(addr, data1,id);
    initiator_port->read(addr+16, data2,id);
    initiator_port->write(1024, data1,id);
    initiator_port->write(1025, data2,id);
    initiator_port->read(1026, result,id);
    initiator_port->write(addr+64, result,id);
  }
  wait();
}
