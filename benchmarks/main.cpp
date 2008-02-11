#include "benchmarks.h"

using namespace std;

int main()
{
    cout << "Running MersenneTwister.h benchmarks:" << endl;
    benchmarkMTH();
    cout << "\nRunning Asmlib Mersenne Twister benchmarks:" << endl;
    benchmarkAsmlibMT();
    cout << "\nRunning Asmlib Mother benchmarks:" << endl;
    benchmarkAsmlibMother();
    return 0;
}
