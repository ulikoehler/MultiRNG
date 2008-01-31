#include <fstream>
#include <gmp.h>
#include <boost/lexical_cast.hpp>
#include <iostream>
using namespace std;
using namespace boost;

#define PROGRINTERV 100 ///Progress Gauge Interval

typedef unsigned long ulong;

static ulong amount;
static ulong seed;
static string filename;
static ulong ulLong;
static double ulDouble;
static double llDouble;
static int distributionSelection;
static int algorithmSelection;
static ulong bits;

static void GenRandMTH() ///Generate Pseudorandom numbers using MersenneTwister.h
{
    MTRand mtr(seed);

    ///Open fstream
    fstream f(filename.c_str(), fstream::out);

    unsigned long i = 0;


    ///Get random number and
    switch(distributionSelection)
                    {
                        case 0: ///32-Bit Real in [0,1]
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.rand() << endl;
                                    }
                                break;
                            }
                        case 1: ///32-Bit Real in [0,n]
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.rand(ulDouble) << endl;
                                    }
                                break;
                            }
                        case 2: ///32-Bit Real in [0,1)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randExc() << endl;
                                    }
                                break;
                            }
                        case 3: ///32-Bit Real in [0,n)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randExc(ulDouble) << endl;
                                    }
                                break;
                            }
                        case 4: ///32-Bit Real in (0,1)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randDblExc() << endl;
                                    }
                                break;
                            }
                        case 5: ///32-Bit Real in (0,n)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randDblExc(ulDouble) << endl;
                                    }
                                break;
                            }
                        case 6: ///Integer in [0,2^32-1]
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randInt() << endl;
                                    }
                                break;
                            }
                        case 7: ///Integer in [0,n] for n < 2^32
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randInt(ulLong) << endl;
                                    }
                                break;
                            }
                        case 8: ///53-bit real number in [0,1)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.rand53() << endl;
                                    }
                                break;
                            }
                        case 9: ///Nonuniform
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randNorm(llDouble, ulDouble) << endl;
                                    }
                                break;
                            }
                        default: break;
                    }
        f.close();

}

//static void GenRandGMP()
//{
//    ///GMP Init
//    gmp_randstate_t randstate;
//
//    mpz_t integer;
//    mpz_t n;
//    mpz_t seed;
//
//    mpz_init(integer);
//    mpz_init(seed);
//    mpz_init(n);
//    ///Get some required variables from GUI
//    mpz_set_str(seed, lexical_cast<string>(seed).c_str(), 10);
//    mpz_set_str(n, lexical_cast<string>(ulDouble).c_str(), 10);
//
//    ///Open fstream
//    fstream f(filename.c_str(), fstream::out);
//
//    unsigned long i = 0;
//    ///Init progressGauge
//    int steps = (int)floor(amount / 1000);
//    progressGauge->SetRange(steps);
//
//    switch(algorithmSelection)
//        {
//            case 0: ///MT 19937
//                {gmp_randinit_mt(randstate);break;}
//            case 1: ///Linear Congruential
//                {gmp_randinit_lc_2exp_size(randstate, bits);break;}
//            default: break;
//        }
//    gmp_randseed(randstate, seed);
//    for(;i < amount;i++)
//        {
//            mpz_urandomm(integer, randstate, n);
//            f << mpz_get_str(NULL, 10, integer) << endl;
//        }
//    f.close();
//    ///Clear all GMP variables
//    mpz_clear(integer);
//    mpz_clear(seed);
//    mpz_clear(n);
//    gmp_randclear(randstate);
//}
