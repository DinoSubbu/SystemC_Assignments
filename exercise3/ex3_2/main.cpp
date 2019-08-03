#include "systemc.h"
#include "src.h"
#include "dst.h"

#include "adder.h"
#include "multiplier.h"
#include "decimator.h"
#include "addermodified.h"

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
	/*	Here the source is simply connected to destination */

	// All the modules in a network are created in main.cpp
	// All the fifo channels are declared here.
	// Also the input port and output of every fifo channel is defined here.

	// FIFO Declarations
	// Src has 3 fifo channels
	sc_fifo<int> src_add1_fifo1, src_add1_fifo2, src_add2_fifo3;
	// In total, there are 12 fifo channels
	sc_fifo<int> add1_add2_fifo, add2_add3_fifo;
	sc_fifo<int> add3_add4_fifo, mul1_add3_fifo, add4_mul1_fifo;
	sc_fifo<int> add4_mul2_fifo, mul2_add4_fifo, add4_dec1_fifo;
	sc_fifo<int> dec1_dst_fifo;

	// Module Declarations
	src	data_source("data_source");
	dst	data_destination("data_destination");
	// KPN Network
  Adder add1("adder1"), add2("adder2"), add3("adder3");
	AdderModified add4("adder4");
	Multiplier mul1("multiplier1"), mul2("multiplier2");
	Decimator dec1("decimator1");

	// Ports and channel linking
	// Name of the ports are declared in corresponding modules as the
	// ports beling to those modules
	data_source.src_out1(src_add1_fifo1);
	data_source.src_out2(src_add1_fifo2);
	data_source.src_out3(src_add2_fifo3);

	add1.x(src_add1_fifo1);
	add1.y(src_add1_fifo2);
	add1.s(add1_add2_fifo);

	add2.x(src_add2_fifo3);
	add2.y(add1_add2_fifo);
	add2.s(add2_add3_fifo);

	add3.x(add2_add3_fifo);
	add3.y(mul1_add3_fifo);
	add3.s(add3_add4_fifo);

	add4.x(add3_add4_fifo);
	add4.y(mul2_add4_fifo);
	add4.s(add4_dec1_fifo);
	add4.t(add4_mul2_fifo);
	add4.u(add4_mul1_fifo);

	mul1.mul_in(add4_mul1_fifo);
	mul1.mul_out(mul1_add3_fifo);

	mul2.mul_in(add4_mul2_fifo);
	mul2.mul_out(mul2_add4_fifo);

	dec1.deci_in(add4_dec1_fifo);
	dec1.deci_out(dec1_dst_fifo);

	data_destination.input(dec1_dst_fifo);


	sc_start();

	cout << endl <<"simulation finished" << endl;
	return 0;
}
