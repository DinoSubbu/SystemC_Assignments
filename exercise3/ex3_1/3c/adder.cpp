#include "adder.h"
void Adder::add()
{

  int c;
  while(true){
  //wait(10, SC_NS);
  x_val = x.read();
  y_val = y.read();
  c = x_val + y_val;
  cout << x_val << "+" << y_val << "=" << c <<endl;
  s.write(c);
}
}
