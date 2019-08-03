#include "addermodified.h"

void AdderModified::start_of_simulation()
{

	t.write(0);
	u.write(0);
	u.write(0);

}

void AdderModified::add()
{
  int c;
  while(true){
  x_val = x.read();
  y_val = y.read();
  c = x_val + y_val;
  cout << "Inside Modified Adder ->> " << x_val << "+" << y_val << "=" << c <<endl;
  s.write(c);
  t.write(c);
  u.write(c);
}
}
