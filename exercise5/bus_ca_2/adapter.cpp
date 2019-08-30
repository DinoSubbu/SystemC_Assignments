#include "adapter.h"

void Adapter::write(unsigned addr, unsigned  data) {
  cout <<" Adapter Write" <<endl;
  switch(addr) {
  case 1024 :
    //x.write(data);
    start_addr1 = data;
    break;
  case 1025 :
    start_addr2 = data;
    //y.write(data);
    break;
  case 1026 :
      start_addr3 = data;
      //y.write(data);
      break;
  case 1027 :
      block_size = data;
      break;
  case 1028 :
      status = data;
      if (status!=0){
        cout << "Status Value: "<< status << endl;
        start_addition.notify();
      }
      break;
  default :
    cout << "Adapter: write to invalid address" << endl;
  }
}

void Adapter::read( unsigned addr, unsigned &data) {
  cout <<" Adapter Read" <<endl;
  switch(addr) {
  case 1024 :
    data= start_addr1;
    break;
  case 1025 :
    data =  start_addr2;
    break;
  case 1026 :
    data= start_addr3;
    break;
  case 1027 :
    data= block_size;
    break;
  case 1028 :
    data= status;
    break;
  default :
    cout << "Adapter: read from invalid address" << endl;
  }
}

void Adapter::do_addition()
{

  for (int i=0; i< block_size; i++)
  {
    //works as a master with ext_bus_if interface
    initiator_port->read(start_addr1+i, data_temp, id);
    cout<<"Inside Addition BLock" <<endl;
    //works as a slave with bus_if
    x.write(data_temp);
    initiator_port->read(start_addr2+i, data_temp, id);
    y.write(data_temp);
    data_temp = s.read();

    initiator_port->write(start_addr3+i, data_temp, id);

  }
  status = 0;
}
