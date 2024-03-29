#include "master.h"
#include "ram.h"
//#include "bus_pv.h"
#include "bus_cx.h"

int sc_main(int argc, char *argv[])
{
  Master master1("master1", 0, 17, 0);
  Ram    ram1("ram1", 0, 16);
  Master master2("master2", 20, 31, 1);
  Ram    ram2("ram2", 16,16);

  //Bus_pv bus("bus");
  // sc_set_time_resol... should be called before sc_time
  //variable declration
  //sc_set_time_resolution(1,SC_PS);
  // Declare the sc_time variables
  //sc_time             t1(10,SC_NS);

  Bus_cx bus("bus", 10,SC_NS);

  master1.initiator_port(bus.bus_export);
  master2.initiator_port(bus.bus_export);
  bus.bus_port(ram1.target_export);
  bus.bus_port(ram2.target_export);

  sc_start();
  return 0;
}
