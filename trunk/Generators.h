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
    double ulDouble = ulDoubleParam;
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

void GenRandBoost()
{
    ///Cache parameters
    ulong amount = amountParam;
    ulong ulSeed = seedParam;
    string filename = filenameParam;
    double ulDouble = ulDoubleParam;
    double llDouble = llDoubleParam;
    int distributionSelection = distributionSelectionParam;
    int algorithmSelection = algorithmSelectionParam;
    ulong bits = bitsParam;

    ///Initialize pointer for variated generator
    variate_generator *vg;

    ///Open fstream
    fstream f(filename.c_str(), fstream::out);
    //Initialize counter
    ulong i;

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
            default: {break;}
        }
        ///Variate Generator
        variate_generator<boostEngine, boostDistribution> generator(algorithm, distribution);
        ///TODO: Main loop
        for(;i < amount;i++)
        {
            f << generator() << endl;
        }
}

template<class Algorithm>
void GetVariatedGenerator(int distribution, double ulDouble, double llDouble, Algorithm *algorithm) ///Boost Function
{
    ///Switch distribution
    switch(distribution)
        {
            case 0: ///Uniform small int
                {
                    uniform_smallint<double> smallInt(llDouble, ulDouble);
                    return variate_generator<Algorithm, uniform_smallint> vg(
                }
            case 1: ///Uniform integer
                {
                    uniform_int<double> uniInt(llDouble, ulDouble);
                    distribution = &uniInt;
                }
            case 2: ///Uniform 01
                {
                    //uniform_01<double, double> uni01(llDouble, ulDouble);
                    //distribution = &uni01;
                }
            case 3: ///Uniform real
                {
                    uniform_real<double> uniReal(llDouble, ulDouble);
                    distribution = &uniReal;

                }
            case 4: ///Triangle
                {
                    triangle_distribution<double> triangle(llDouble, ulDouble);
                    distribution = &triangle;
                }
            case 5: ///Bernoulli
                {
                    bernoulli_distribution<double> bernoulli(llDouble, ulDouble);
                    distribution = &bernoulli;
                }
            case 6: ///Cauchy
                {
                    cauchy_distribution<double> cauchy(llDouble, ulDouble);
                    distribution = &cauchy;
                }
            case 7: ///Exponential
                {
                    exponential_distribution<double> exponential(llDouble, ulDouble);
                    distribution = &exponential;
                }
            case 8: ///Geometric
                {
                    geometric_distribution<double> geometric(llDouble, ulDouble);
                    distribution = &geometric;
                }
            case 9: ///Normal
                {
                    normal_distribution<double> normal(llDouble, ulDouble);
                    distribution = &normal;
                }
            case 10: ///Lognormal
                {
                    lognormal_distribution<double> lognormal(llDouble, ulDouble);
                    distribution = &lognormal;
                }
            case 11: ///Uniform on Sphere
                {
                    uniform_on_sphere<double> uniSphere(llDouble, ulDouble);
                    distribution = &uniSphere;
                }
        }
}

#endif
