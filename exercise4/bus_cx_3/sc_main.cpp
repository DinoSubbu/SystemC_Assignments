#include "master.h"
#include "ram.h"
//#include "bus_pv.h"
#include "bus_cx.h"
#include "adapter.h"
#include "adder.h"
#include "master_extra.h"

int sc_main(int argc, char *argv[])
{
  Master master1("master1", 0, 17, 0);
  Ram    ram1("ram1", 0, 15);
  Master master2("master2", 20, 31, 1);
  Ram    ram2("ram2", 16, 16);

  // Created a new RAM for storing results of Adder
  Ram ram3("ram3",64,16);
  //Bus_pv bus("bus");
  // sc_set_time_resol... should be called before sc_time
  //variable declration
  //sc_set_time_resolution(1,SC_PS);
  // Declare the sc_time variables
  //sc_time             t1(10,SC_NS);

  Master_Extra master_extra("master_extra", 2);
  Bus_cx bus("bus", 10,SC_NS);

  master1.initiator_port(bus.bus_export);
  master2.initiator_port(bus.bus_export);
  master_extra.initiator_port(bus.bus_export);

  sc_buffer<int> ch_x, ch_y, ch_s;
  Adder adder("Adder");
  Adapter adapter("Adapter");

  adder.x(ch_x);
  adder.y(ch_y);
  adder.s(ch_s);
  adapter.adapter_x(ch_x);
  adapter.adapter_y(ch_y);
  adapter.adapter_s(ch_s);


  bus.bus_port(ram1.target_export);
  bus.bus_port(ram2.target_export);

  // ram3 export is binded to multiport of bus_if
  bus.bus_port(ram3.target_export);
  bus.bus_port(adapter.adapter_export);


  sc_start();
  return 0;
}
