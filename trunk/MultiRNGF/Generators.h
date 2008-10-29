#ifndef GENERATORS_H
#define GENERATORS_H
#include "wx_pch.h"
using namespace std;
using namespace boost;
using namespace boost::random;

///Function Prototypes
int GenRandMTH();
int GenRandGMP();
template<class Algorithm> void ProcessBoostAlgorithm(Algorithm* algorithm);
void GenRandBoost();

///Typedefs
typedef unsigned long ulong;
typedef unsigned long long ctr_type; //Counter

///Static variables,
static unsigned long long amountParam;
static ulong seedParam;
static string filenameParam;
static unsigned long ulParam;
static unsigned long llParam;
static int distributionSelectionParam;
static int algorithmSelectionParam;
static string distParam1;

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

    ///Distribution main switch. TODO: Optimize!
    switch(distributionSelection)
        {
            case 0: ///Uniform small int
                {
                    ///Boost Random stuff
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
            case 2: ///Uniform real
                {
                    uniform_real<long double> uniReal(llDouble, ulDouble);
                    variate_generator<Algorithm&, uniform_real<long double> > generator(*algorithm, uniReal);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 3: ///Triangle
                {
                    triangle_distribution<double> triangle(llInt, ulInt, 0); ///DUMMY TODO
                    variate_generator<Algorithm&, triangle_distribution<double> > generator(*algorithm, triangle);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 4: ///Bernoulli
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 5: ///Cauchy
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 6: ///Exponential
                {
                    long double ldP1 = lexical_cast<long double>(distParam1);
                    exponential_distribution<long double> expDist(ldP1);
                    variate_generator<Algorithm&, exponential_distribution<long double> > generator(*algorithm, expDist);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 7: ///Geometric
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 8: ///Normal
                {
                    normal_distribution<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 9: ///Lognormal
                {
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    for(unsigned long i = 0;i < amount;i++)
                        {
                            f << generator() << endl;
                        }
                    break;
                }
            case 10: ///Uniform on Sphere
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
                    minstd_rand minstdrand(ulSeed);
                    ProcessBoostAlgorithm<minstd_rand>(&minstdrand);
                }
            case 2: ///Additive combine
                {
                    //ecuyer1988 addComb(lexical_cast<unsigned int>(ulSeed));
                    //ProcessBoostAlgorithm<ecuyer1988>(&addComb);
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
                    //lagged_fibonacci<int, int, int, int, boostIntParam3>lagFib(ulSeed);
                    break;
                }
            default: break;
        }
}


#endif
