#include "master_extra.h"

void Master_Extra::action()
{
  unsigned data;
  wait(1000, SC_NS); // wait time to ensure that RAM is written

  // Reads values from Address 0 and 16
  unsigned data1, data2,data3;
  unsigned addr1=0;
  unsigned addr2=16;
  unsigned addr_read=1026;
  unsigned addr_write=64;
  while(addr1<=15 && addr2<=30)
  {
    cout << "Inside Extra Master" << endl;
    initiator_port->read(addr1, data1);
    cout << name() << " read(" << addr1 << ", " << data1 << ")"
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);
    initiator_port->read(addr2, data2);
    cout << name() << " read(" << addr2 << ", " << data2 << ")"
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);

    initiator_port->write(1024, data1);
    cout << name() << " write(" << 1024 << ", " << data1 << ")"
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);

    initiator_port->write(1025, data2);
    cout << name() << " write(" << 1025 << ", " << data2 << ")"
         << " at " << sc_time_stamp() << endl;
    wait(3, SC_NS);

    initiator_port->read(1026, data3);
    cout << name() << " read(" << 1026 << ", " << data3 << ")"
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);

    initiator_port->write(addr_write, data3);
    cout << name() << " write(" << addr_write << ", " << data3 << ")"
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);

    addr1++;
    addr2++;
    addr_write++;
  }

  wait();
}
