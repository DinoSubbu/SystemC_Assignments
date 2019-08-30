#include "new_master.h"

void New_master::action()
{
  unsigned data1, data2, result;
  wait(2000, SC_NS);
  cout<< "From New Master!! " <<endl;
  initiator_port->write(1024, start_addr1 ,id);
  initiator_port->write(1025, start_addr2 ,id);
  initiator_port->write(1026, start_addr3 ,id);
  initiator_port->write(1027, block_size ,id);
  initiator_port->write(1028, 55555 ,id);

  while(1)
  {
  initiator_port->read(1028, data1 ,id);
  if (data1 ==0)
      sc_stop();
  else
    wait(20, SC_NS);
  }


  /*
  for( unsigned addr = 0; addr < 16; addr++ )
  {


    initiator_port->read(addr, data1,id);
    initiator_port->read(addr+16, data2,id);
    initiator_port->write(1024, data1,id);
    initiator_port->write(1025, data2,id);
    initiator_port->read(1026, result,id);
    initiator_port->write(addr+64, result,id);
  }
  */
  wait();
}
