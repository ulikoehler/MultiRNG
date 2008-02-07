#ifndef GENERATORS_H
#define GENERATORS_H
#include <fstream>
#include <gmp.h>
#include <gmpxx.h>
#include <boost/lexical_cast.hpp>
#include <boost/random.hpp>
#include <boost/random/additive_combine.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/inversive_congruential.hpp>
#include <boost/random/shuffle_output.hpp>
#include <boost/random/lagged_fibonacci.hpp>
#include <iostream>
using namespace std;
using namespace boost;
using namespace boost::random;

///Typedefs
typedef unsigned long ulong;

///Static variables,
static ulong amountParam;
static ulong seedParam;
static string filenameParam;
static ulong ulLongParam;
static double ulDoubleParam;
static double llDoubleParam;
static int distributionSelectionParam;
static int algorithmSelectionParam;
static ulong bitsParam;

void GenRandMTH() ///Generate Pseudorandom numbers using MersenneTwister.h
{
    ///Cache parameters
    ulong amount = amountParam;
    ulong seed = seedParam;
    string filename = filenameParam;
    ulong ulLong =  ulLongParam;
    double ulDouble = ulDoubleParam;
    double llDouble = llDoubleParam;
    int distributionSelection = distributionSelectionParam;

    ///Initialize RNG state variable
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

void GenRandGMP()
{
    ///Cache parameters
    ulong amount = amountParam;
    ulong ulSeed = seedParam;
    string filename = filenameParam;
    ulong ulLong =  ulLongParam;
    double ulDouble = ulDoubleParam;
    double llDouble = llDoubleParam;
    int distributionSelection = distributionSelectionParam;
    int algorithmSelection = algorithmSelectionParam;
    ulong bits = bitsParam;

    ///GMP Init
    gmp_randstate_t randstate;

    mpz_t integer;
    mpz_t n;
    mpz_t seed;

    mpz_init(integer);
    mpz_init(seed);
    mpz_init(n);
    ///Get some required variables from GUI
    mpz_set_str(seed, lexical_cast<string>(ulSeed).c_str(), 10);
    mpz_set_str(n, lexical_cast<string>(ulDouble).c_str(), 10);

    ///Open fstream
    fstream f(filename.c_str(), fstream::out);

    unsigned long i = 0;

    switch(algorithmSelection)
        {
            case 0: ///MT 19937
                {gmp_randinit_mt(randstate);break;}
            case 1: ///Linear Congruential
                {gmp_randinit_lc_2exp_size(randstate, bits);break;}
            default: break;
        }
    gmp_randseed(randstate, seed);
    for(;i < amount;i++)
        {
            mpz_urandomm(integer, randstate, n);
            f << mpz_get_str(NULL, 10, integer)  << endl;
        }
    f.close();
    ///Clear all GMP variables
    mpz_clear(integer);
    mpz_clear(seed);
    mpz_clear(n);
    gmp_randclear(randstate);
}

template<class boostEngine, class boostDistribution>
void GenRandBoost()
{
    ///Cache parameters
    ulong amount = amountParam;
    ulong ulSeed = seedParam;
    string filename = filenameParam;
    ulong ulLong =  ulLongParam;
    double ulDouble = ulDoubleParam;
    double llDouble = llDoubleParam;
    int distributionSelection = distributionSelectionParam;
    int algorithmSelection = algorithmSelectionParam;
    ulong bits = bitsParam;

    ///Initialize template pointers
    boostEngine *algorithm;
    boostDistribution *distribution;


    ///Open fstream
    fstream f(filename.c_str(), fstream::out);

    ///Switch distribution
    switch(algorithmSelection)
        {
            case 0: ///MT 19937
                {
                    mt19937 mersenne(ulSeed);
                    algorithm = &mersenne;
                    break;
                }
            case 1: ///Linear congruential
                {
                    minstd_rand0 linCongr(ulSeed);
                    algorithm = &linCongr;
                    break;
                }
            case 2: ///Additive combine
                {
                    ecuyer1988 addComb(ulSeed);
                    algorithm = &addComb;
                    break;
                }
            case 3: ///Inverse congruential
                {
                    hellekalek1995 invCongr(ulSeed);
                    algorithm = &invCongr;
                    break;
                }
            case 4: ///Shuffle output
                {
                    kreutzer1986 shOut(ulSeed);
                    algorithm = &shOut;
                    break;
                }
//            case 5: ///Lagged Fibonacci
//                {
//                    lagged_fibonacci lagFib(ulSeed);
//                    algorithm = &lagFib;
//                    break;
//                }
            default: break;
        }
    ///Switch distribution
    switch(distributionSelection)
        {
            case 0: ///Uniform small int
                {

                }
            case 1: ///Uniform small int
                {

                }
            case 2: ///Uniform small int
                {

                }
            case 3: ///Uniform small int
                {

                }
            case 4: ///Uniform small int
                {

                }
            case 5: ///Uniform small int
                {

                }
            case 6: ///Uniform small int
                {

                }
            case 7: ///Uniform small int
                {

                }
            case 8: ///Uniform small int
                {

                }
            case 9: ///Uniform small int
                {

                }
            case 10: ///Uniform small int
                {

                }
            case 11: ///Uniform small int
                {

                }
            default: {break;}
        }
        ///TODO: Main loop
}

#endif
