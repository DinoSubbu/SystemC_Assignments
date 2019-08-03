# include "watch.h"
#include "systemc.h"

int sc_main(int argc, char *argv[])
{
  Watch watch("watch");
  sc_clock clk("clk", 1, SC_SEC);

  watch.clock(clk);
  sc_start(65, SC_SEC);

  return 0;
}
