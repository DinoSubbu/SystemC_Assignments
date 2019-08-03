#include "testbench.h"

void Testbench::stim_add()  // SC_THREAD
{
  //wait(10, SC_NS);
  ch_x.write(3); ch_y.write(4);
    // first stimulus
  cout << "Adder Stimuli 1" <<endl;
  //wait(10, SC_NS);      // wait for 10 ns
  ch_x.write(7); ch_y.write(0);   // second stimulus
  cout << "Adder Stimuli 2" << endl;
  //wait(10, SC_NS);      // wait (no sensitivity!)
                        // further stimuli
  ch_x.write(8); ch_y.write(-4);
  cout << "Adder Stimuli 3" <<endl;
  //wait(10, SC_NS);
  ch_x.write(8); ch_y.write(-4);
  cout << "Adder Stimuli 4" <<endl;
}


void Testbench::stim_mul()
{

ch_mult_input.write(5);
cout << "Multiplication Stimuli 1" <<endl;

}

void Testbench::stim_deci()
{
  for (int i =1; i <11; i++) {
    ch_deci_input.write(i);
    cout << "Decimator Stimuli " << i <<endl;
}
}

void Testbench::check_add() // SC_THREAD was used because fifo caǹt wait
{
  int add_result;
  while(true){
    //wait(10, SC_NS);
    add_result = ch_s.read() ;
    cout << "Check: x + y = " << add_result <<endl;
    }
}

void Testbench::check_mul()
{
  int mul_result;
  while(true){
    mul_result = ch_mult_output.read();
    cout << "Check: Multiplier = " << mul_result << endl;
}
}

void Testbench::check_deci()
{
  int deci_result;
  while(true){
    deci_result = ch_deci_output.read();
    cout << "Check: Decimator = " << deci_result << endl;
}
}
