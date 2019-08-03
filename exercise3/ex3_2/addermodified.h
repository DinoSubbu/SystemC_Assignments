#ifndef _ADDERMODIFIED_H_
#define _ADDERMODIFIED_H_

#include "systemc.h"


SC_MODULE(AdderModified)
{
  int x_val;
  int y_val;

  sc_fifo_in<int> x;
  sc_fifo_in<int> y;
  sc_fifo_out<int> s, t, u;

  void start_of_simulation () override;
  void add();

  SC_CTOR(AdderModified)
  {
    SC_THREAD(add);
    sensitive << x << y;
  }
};
#endif
