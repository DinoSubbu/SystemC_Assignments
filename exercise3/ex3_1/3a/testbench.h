#ifndef _TESTBENCH_H_
#define _TESTBENCH_H_

#include "systemc.h"
#include "adder.h"
SC_MODULE(Testbench)
{ 									// a top level module; no ports
  sc_buffer<int> ch_x, ch_y, ch_s;  // channels
  Adder uut;						// Adder instance
  void stim();						// stimuli process
  void check();						// checking process
  SC_CTOR(Testbench)
  : uut("uut"), ch_x("ch_x")
  {
    SC_THREAD(stim);				// without sensitivity
    SC_METHOD(check);
    sensitive << ch_s;				// sensitivity for check()
    uut.x(ch_x);					// port x of uut bound to ch_x
    uut.y(ch_y);					// port y of uut bound to ch_y
    uut.s(ch_s);					// port s of uut bound to ch_s
  }
};

#endif

