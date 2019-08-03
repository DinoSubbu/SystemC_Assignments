#include "adapter.h"

void Adapter::write( unsigned addr, unsigned  data )
{

  if (addr == 1024)
    adapter_x.write(data);
  else if (addr == 1025)
    adapter_y.write(data);
  else
    cout << "Forbidden !! " << addr << endl;

}

void Adapter::read(  unsigned addr, unsigned &data )
{
  if (addr == 1024)
    data = adapter_x.read();
  else if (addr == 1025)
    data = adapter_y.read();
  else if (addr == 1026)
    data = adapter_s.read();
  else
    cout <<"Forbidden" << endl;

}

/*
void Adapter::end_of_elaboration()
{
  unsigned i, slave_start, slave_end;
  ifstream mem_map("mem_map.txt");
  unsigned slaves = bus_port.size();
  starts = new unsigned[slaves];
  ends   = new unsigned[slaves];
  mem_map >> i;
  while( mem_map )
  {
    mem_map >> slave_start >> slave_end;
    if( i >= slaves )
    {
       cout << "Bus ERROR: slave number does not exist" << endl;
       sc_stop();
    }
    else
    {
      starts[i] = slave_start;
      ends[i]   = slave_end;
      cout << "Bus slave " << i << " starts "
           << slave_start << " ends " << slave_end << endl;
    }
    mem_map >> i;
  }
}
*/
