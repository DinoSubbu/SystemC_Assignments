#ifndef _TESTBENCH_H_
#define _TESTBENCH_H_

#include "systemc.h"
#include "adder.h"
#include "multiplier.h"
#include "decimator.h"

SC_MODULE(Testbench)
{ 									// a top level module; no ports
  //sc_buffer<int> ch_x, ch_y, ch_s;  // channels
  sc_fifo<int> ch_x, ch_y, ch_s;
  sc_fifo<int> ch_mult_input, ch_mult_output;
  sc_fifo<int> ch_deci_input, ch_deci_output;

  Adder uut;						// Adder instance
  Multiplier mult;
  Decimator deci;

  void stim_add();
  void stim_mul();
  void stim_deci();						// stimuli process

  void check_add();						// checking process
  void check_mul();
  void check_deci();

  SC_CTOR(Testbench)
  : uut("uut"), ch_x(2), ch_y(2), ch_s(2), mult("mult"), deci("deci"), 
  ch_mult_input(1), ch_mult_output(1),
  ch_deci_input(10), ch_deci_output(1)
    {
    SC_THREAD(stim_add);				// without sensitivity
    SC_THREAD(stim_mul);				// without sensitivity
    SC_THREAD(stim_deci);				// without sensitivity

    SC_THREAD(check_add);       // modified this to make fifo work
    SC_THREAD(check_mul);
    SC_THREAD(check_deci);
    //sensitive << ch_s;			Not needed for Fifo	// sensitivity for check()
    // But sensitive can be used for SC_THREAD without FIFO
    uut.x(ch_x);					// port x of uut bound to ch_x
    uut.y(ch_y);					// port y of uut bound to ch_y
    uut.s(ch_s);					// port s of uut bound to ch_s

    mult.mul_in(ch_mult_input);
    mult.mul_out(ch_mult_output);

    deci.deci_in(ch_deci_input);
    deci.deci_out(ch_deci_output);
  }
};

#endif
