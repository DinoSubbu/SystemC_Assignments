#ifndef _DECIMATOR_H_
#define _DECIMATOR_H_

#include "systemc.h"
SC_MODULE(Decimator)
{


  sc_fifo_in<int> deci_in;
  sc_fifo_out<int> deci_out;

  void decimate();
  SC_CTOR(Decimator)
  {
    SC_THREAD(decimate);

  }
};
#endif
