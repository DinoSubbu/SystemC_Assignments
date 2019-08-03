#include "dst.h"
void dst::behaviour()
{
	int received_value;

	while(true){
	input.read(received_value);
	cout <<  "DST Output: " << received_value<< "\n";
}
	//next_trigger(input.data_written_event());
}
