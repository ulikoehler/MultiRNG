///This file may be copied under the condition of the GNU GPL
///Benchmark for MersenneTwister.h
#include <MersenneTwister.h> ///MersenneTwister.h
#include <asmlib.h> ///Agner Fog's great asmlib: http://agner.org
#include <iostream>
#define MTHTEST

using namespace std;

inline void benchmarkMTH()
{
    ///Declare variables
    __int64 time[11];
    MTRand mtr(100);
    srand(100); ///Seed C rand

    ///Run benchmark
    time[0] = ReadTSC();
    rand();
    time[1] = ReadTSC();
    mtr.rand();
    time[2] = ReadTSC();
    mtr.rand(99.99);
    time[3] = ReadTSC();
    mtr.randExc();
    time[4] = ReadTSC();
    mtr.randExc(99.99);
    time[5] = ReadTSC();
    mtr.randDblExc();
    time[6] = ReadTSC();
    mtr.randDblExc(99.99);
    time[7] = ReadTSC();
    mtr.randInt();
    time[8] = ReadTSC();
    mtr.randInt(100000);
    time[9] = ReadTSC();
    mtr.rand53();
    time[10] = ReadTSC();

    ///Display results
    cout << "rand() time:" << time[1]-time[0] << endl;
    cout << "mtr.rand() time:" << time[2]-time[1] << endl;
    cout << "mtr.rand(99.99) time:" << time[3]-time[2] << endl;
    cout << "mtr.randExc() time:" << time[4]-time[3] << endl;
    cout << "mtr.randExc(99.99) time:" << time[5]-time[4] << endl;
    cout << "mtr.randDblExc() time:" << time[6]-time[5] << endl;
    cout << "mtr.randDblExc(99.99) time:" << time[7]-time[6] << endl;
    cout << "mtr.randInt() time:" << time[8]-time[7] << endl;
    cout << "mtr.rand(100000) time:" << time[9]-time[8] << endl;
    cout << "mtr.rand53() time:" << time[10]-time[9] << endl;
}
