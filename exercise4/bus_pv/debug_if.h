#ifndef _DEBUG_IF_H_
#define _DEBUG_IF_H_

#include "systemc.h"
#include <iostream>
#include "stdio.h"

// It's an Abstract class. It serves as an interface as the method
// is pure vitual
class debug_if : virtual public sc_interface
{
public:
  virtual void dump(ostream &os) = 0;
};

#endif
