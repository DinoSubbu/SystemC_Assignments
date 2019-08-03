#include "multiplier.h"
void Multiplier::multiply()
{
  int c;
  while(true){
  in_val = mul_in.read();
  c = in_val * mult_const;
  cout << "Inside Multiplier ->> Input Number: " << in_val << "; Multiplier Result: " << c <<endl;
  mul_out.write(c);
}
}
