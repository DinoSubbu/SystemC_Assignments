#ifndef _SRC_H_
#define _SRC_H_

#include "systemc.h"
SC_MODULE(src)
{

	// src module has 3 output ports connected to 3 fifo channels.
	// So sc_fifo_out is used.
	sc_fifo_out<int> src_out1, src_out2, src_out3;

	void behaviour();
	void start_of_simulation () override;

	// Initialising 2 of the 3 fifo channels with initial tokens
	// Use the ports of src to write initial values to channels
	// When src module object is created and simulation is triggered, initially
	// it writes values (initial tokens) to 2 fifo channels

	SC_CTOR(src)
	{
		SC_THREAD(behaviour);
	}
};

#endif
