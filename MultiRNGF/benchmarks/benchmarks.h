///This file may be copied under the condition of the GNU GPL
///Benchmark for MersenneTwister.h
#include <MersenneTwister.h> ///MersenneTwister.h
#include <asmlib.h> ///Agner Fog's great asmlib: http://agner.org
#include <asmlibran.h> ///Asmlib random number generators (MersenneTwister and Mother)
#include <iostream>
#ifndef BENCHM_H_INCLUDED
#define BENCHM_H_INCLUDED

#define NUMTESTS 100000 ///Number of tests

using namespace std;

void benchmarkMTH()
{
    ///Declare variables
    __int64 time[11];
    MTRand mtr(100);
    srand(100); ///Seed C rand
    double res[NUMTESTS];

    ///Run benchmark
    time[0] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {rand();}
    time[1] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {res[i] = mtr.rand();}
    time[2] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {mtr.rand(99.99);}
    time[3] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {mtr.randExc();}
    time[4] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {mtr.randExc(99.99);}
    time[5] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {mtr.randDblExc();}
    time[6] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {mtr.randDblExc(99.99);}
    time[7] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {mtr.randInt();}
    time[8] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {mtr.randInt(100000);}
    time[9] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) {mtr.rand53();}
    time[10] = ReadTSC();

    ///Display results
    cout << "rand() time:" << (time[1]-time[0])/NUMTESTS << endl;
    cout << "mtr.rand() time:" << (time[2]-time[1])/NUMTESTS << endl;
    cout << "mtr.rand(99.99) time:" << (time[3]-time[2])/NUMTESTS << endl;
    cout << "mtr.randExc() time:" << (time[4]-time[3])/NUMTESTS << endl;
    cout << "mtr.randExc(99.99) time:" << (time[5]-time[4])/NUMTESTS << endl;
    cout << "mtr.randDblExc() time:" << (time[6]-time[5])/NUMTESTS << endl;
    cout << "mtr.randDblExc(99.99) time:" << (time[7]-time[6])/NUMTESTS << endl;
    cout << "mtr.randInt() time:" << (time[8]-time[7])/NUMTESTS << endl;
    cout << "mtr.rand(100000) time:" << (time[9]-time[8])/NUMTESTS << endl;
    cout << "mtr.rand53() time:" << (time[10]-time[9])/NUMTESTS << endl;
}

void benchmarkAsmlibMT()
{
    MersenneRandomInit(100); ///Seed with 100

    ///Init counter vars
    __int64 time[5];

    ///Test speed and save results in time array
    time[0] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) MersenneIRandom(1, 100);
    time[1] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) MersenneIRandomX(1, 100);
    time[2] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) MersenneRandom();
    time[3] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) MersenneBRandom();
    time[4] = ReadTSC();

    ///Display results
    cout << "MersenneIRandom(1, 100); time:" << (time[1]-time[0])/NUMTESTS << endl;
    cout << "MersenneIRandomX(1, 100) time:" << (time[2]-time[1])/NUMTESTS << endl;
    cout << "MersenneRandom() time:" << (time[3]-time[2])/NUMTESTS << endl;
    cout << "MersenneBRandom() time:" << (time[4]-time[3])/NUMTESTS << endl;
}

void benchmarkAsmlibMother()
{
    MotherRandomInit(100); ///Seed with 100

    ///Init counter vars
    __int64 time[4];

    ///Test speed and save results in time array
    time[0] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) MotherIRandom(1, 100);
    time[1] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) MotherRandom();
    time[2] = ReadTSC();
    for(int i = 0;i < NUMTESTS;i++) MotherBRandom();
    time[3] = ReadTSC();

    ///Display results
    cout << "MotherIRandom(1, 100) time:" << (time[1]-time[0])/NUMTESTS << endl;
    cout << "MotherRandom() time:" << (time[2]-time[1])/NUMTESTS << endl;
    cout << "MotherBRandom() time:" << (time[3]-time[2])/NUMTESTS << endl;
}

#endif
