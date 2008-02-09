#ifndef GENERATORS_H
#define GENERATORS_H
#include "wx_pch.h"
using namespace std;
using namespace boost;
using namespace boost::random;

///Typedefs
typedef unsigned long ulong;

///Static variables,
static ulong amountParam;
static ulong seedParam;
static string filenameParam;
static string ulParam;
static string llParam;
static long boostAlgoParam1;
static long boostAlgoParam2;
static long boostAlgoParam3;
static long boostAlgoParam4;
static long boostAlgoParam5;
static long boostAlgoParam6;
static long boostAlgoParam7;
static int distributionSelectionParam;
static int algorithmSelectionParam;
static ulong bitsParam;

void GenRandMTH() ///Generate Pseudorandom numbers using MersenneTwister.h
{
    ///Cache parameters
    ulong amount = amountParam;
    ulong seed = seedParam;
    string filename = filenameParam;
    ulong ulLong = lexical_cast<long>(ulParam);
    double ulDouble = lexical_cast<double>(ulParam);
    double llDouble = lexical_cast<double>(llParam);
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
    double ulDouble = lexical_cast<double>(ulParam);
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


template<class Algorithm>
void ProcessBoostAlgorithm(Algorithm *algorithm) ///Process type of boost algorithm
{
    ///Cache parameters
    unsigned long amount = amountParam;
    int distributionSelection = distributionSelectionParam;
    double ulDouble = lexical_cast<double>(ulParam);
    double llDouble = lexical_cast<double>(llParam);
    int ulInt = lexical_cast<int>(ulParam);
    int llInt = lexical_cast<int>(llParam);
    string filename = filenameParam;

    ///Open fstream
    fstream f(filename.c_str(), fstream::out);

    ///Initialize counter

    ///Switch distribution
    switch(distributionSelection)
        {
            case 0: ///Uniform small int
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 1: ///Uniform integer
                {
                    uniform_int<int> uniInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_int<int> > generator(*algorithm, uniInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 2: ///Uniform 01
                {
//                    uniform_01<Algorithm, int> uni01(llInt, ulInt);
//                    variate_generator<Algorithm&, uniform_01<Algorithm, int> > generator(*algorithm, uni01);
//                    for(unsigned long i = 0;i < amount;i++)
//                        {
//                            f << generator() << endl;
//                        }
//                    break;
                }
            case 3: ///Uniform real
                {
                    uniform_real<double> uniReal(llDouble, ulDouble);
                    variate_generator<Algorithm&, uniform_real<double> > generator(*algorithm, uniReal);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 4: ///Triangle
                {
                    triangle_distribution<double> triangle(llInt, ulInt, 0); ///DUMMY TODO
                    variate_generator<Algorithm&, triangle_distribution<double> > generator(*algorithm, triangle);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 5: ///Bernoulli
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 6: ///Cauchy
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 7: ///Exponential
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 8: ///Geometric
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 9: ///Normal
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 10: ///Lognormal
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 11: ///Uniform on Sphere
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            default: break;
        }
}

void GenRandBoost()
{
    ///Cache required parameters
    ulong ulSeed = seedParam;
    int algorithmSelection = algorithmSelectionParam;

    ///Switch distribution
    switch(algorithmSelection)
        {
            case 0: ///MT 19937
                {
                    mt19937 mersenne(lexical_cast<unsigned int>(ulSeed));
                    ProcessBoostAlgorithm<mt19937>(&mersenne);
                    break;
                }
            case 1: ///Linear congruential
                {
                    minstd_rand0 linCongr(ulSeed);
                    //algorithm = &linCongr;
                    break;
                }
            case 2: ///Additive combine
                {
                    ecuyer1988 addComb(ulSeed);
                    ProcessBoostAlgorithm<ecuyer1988>(&addComb);
                    break;
                }
            case 3: ///Inverse congruential
                {
                    hellekalek1995 invCongr(ulSeed);
                    ProcessBoostAlgorithm<hellekalek1995>(&invCongr);
                    break;
                }
            case 4: ///Shuffle output
                {
                    kreutzer1986 shOut(ulSeed);
                    ProcessBoostAlgorithm<kreutzer1986>(&shOut);
                    break;
                }
            case 5: ///Lagged Fibonacci
                {
                    lagged_fibonacci<unsigned int,  lagFib(ulSeed);
                    algorithm = &lagFib;
                    break;
                }
            default: break;
        }
}

#endif