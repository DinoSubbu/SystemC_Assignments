#include "decimator.h"
void Decimator::decimate()
{
  int decimator_output;
  while(true){
    for (int i=0; i <10; i++)
      decimator_output = deci_in.read();

    cout << "Inside Decimator ->>  Result: " << decimator_output <<endl;
    deci_out.write(decimator_output);

}
}
