#include "testbench.h"
void Testbench::stim()  // SC_THREAD
{

  //wait(10, SC_NS);
  ch_x.write(3); ch_y.write(4);
    // first stimulus
  cout << "Stimuli 1" <<endl;
  //wait(10, SC_NS);      // wait for 10 ns
  ch_x.write(7); ch_y.write(0);   // second stimulus
  cout << "Stimuli 2" << endl;
  //wait(10, SC_NS);      // wait (no sensitivity!)
                        // further stimuli
  ch_x.write(8); ch_y.write(-4);
  cout << "Stimuli 3" <<endl;
  //wait(10, SC_NS);
  ch_x.write(8); ch_y.write(-4);
  cout << "Stimuli 4" <<endl;

  //wait(10, SC_NS);
}
void Testbench::check() // SC_THREAD was used because fifo caǹt wait
{

  while(true){
    //wait(10, SC_NS);
    cout << "Check: x + y = " << ch_s.read()<<endl;
    //wait (10, SC_NS);
    //cout << ch_x << "+" << ch_y << "=" << ch_s;  // debug output
    //if( ch_s != ch_x+ch_y ) sc_stop();     // stop simulation
    //else cout << " -> OK" << endl;
}
}
