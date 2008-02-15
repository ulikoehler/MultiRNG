#include <iostream>

using namespace std;
#include "asm.h"

int main()
{
	//Read clockcycles
	__int64 TSC = ReadTSC();
	cout << "TSC: " << TSC << endl;
	//Calculate how many clockcycles ReadTSC() takes
	__int64 ref[2];
	ref[0] = ReadTSC();
	ref[1] = ReadTSC();
	cout << "ReadTSC() takes " << ref[1]-ref[0] << " clockcycles." << endl;
	return 0;
}
