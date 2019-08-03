#include "watch.h"

void Watch::increment_sec()
{
  sec_counter.count();

  cout << "Seconds Incremented" << endl;

  if (sec_counter.overflow())
  {
    next_minute.notify();
    cout << "notified" << endl;
  }

}


void Watch::increment_min()
{

    min_counter.count();
    cout << "Minues Incremented" << endl;
    if (min_counter.overflow())
    {
      next_hour.notify();
      cout << "Minutes Notified" << endl;
    }


}

void Watch::increment_hr()
{


    hr_counter.count();
    if (hr_counter.overflow())
    {
      cout << "Hours Overflow!!" << endl;
    }


}


void Watch::print_time()
{
  cout << "Time -> Hour:" << hr_counter.read() << " Min:" << min_counter.read()
    << " Sec:" << sec_counter.read() << endl;
}
