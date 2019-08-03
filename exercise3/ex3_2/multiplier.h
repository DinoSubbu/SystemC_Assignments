#ifndef _MULTIPLIER_H_
#define _MULTIPLIER_H_

#include "systemc.h"
SC_MODULE(Multiplier)
{
  int mult_const;
  int in_val;

  sc_fifo_in<int> mul_in;
  sc_fifo_out<int> mul_out;

  void multiply();
  SC_CTOR(Multiplier): mult_const(6)
  {
    SC_THREAD(multiply);
    cout << "Multiplication Constant K : " << mult_const <<endl;
    //sensitive << x << y;
  }
};
#endif
