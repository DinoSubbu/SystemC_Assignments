#ifndef _WATCH_H_
#define _WATCH_H_
#include "systemc.h"
#include "counter.h"

SC_MODULE(Watch)
{


sc_in<bool> clock;
  // CLK Input Port


  Counter sec_counter;
  Counter min_counter;
  Counter hr_counter;

    sc_event next_minute, next_hour;

public:
  void increment_sec();
  void increment_min();
  void increment_hr();
  void print_time();

SC_CTOR(Watch) : sec_counter(60), min_counter(60), hr_counter(24)
{
  SC_METHOD(increment_sec);
  sensitive << clock.pos();

  SC_METHOD(increment_min);
  sensitive << next_minute;
  dont_initialize();


  SC_METHOD(increment_hr);
    sensitive << next_hour;
  dont_initialize();


  SC_METHOD(print_time);
  sensitive << clock.neg();
}

};
#endif
