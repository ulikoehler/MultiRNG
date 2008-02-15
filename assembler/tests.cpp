#include <iostream>

using namespace std;
extern "C" __int64 ReadTSC();

int main()
{
	__int64 TSC = ReadTSC();
	cout << "TSC: " << TSC << endl;
}
