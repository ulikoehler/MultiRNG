#ifndef GENERATORS_H
#define GENERATORS_H
#include "wx_pch.h"
///Custom includes
#include "Postproc.h" ///Postprocessing header
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

///Static variables,
static ulong amountParam;
static string seedParam;
static string filenameParam;
static string ulParam;
static string llParam;
static ulong boostAlgoParam1Param;
static ulong boostAlgoParam2Param;
static ulong boostAlgoParam3Param;
static ulong boostAlgoParam4Param;
static ulong boostAlgoParam5Param;
static ulong boostAlgoParam6Param;
static ulong boostAlgoParam7Param;
static ulong boostAlgoParam8Param;
static ulong boostAlgoParam9Param;
static int distributionSelectionParam;
static int algorithmSelectionParam;
static ulong bitsParam;
static bool customAlgorithmParam;
static bool postprocEnabledParam;

int GenRandMTH() ///Generate Pseudorandom numbers using MersenneTwister.h
{
    ///Cache parameters
    ulong amount = amountParam;
    ulong seed = lexical_cast<unsigned long>(seedParam);
    string filename = filenameParam;
    ulong ulLong = lexical_cast<long>(ulParam);
    double ulDouble = lexical_cast<double>(ulParam);
    double llDouble = lexical_cast<double>(llParam);
    int distributionSelection = distributionSelectionParam;
    bool postproc = postprocEnabledParam;
    //boost::function postprocFunction;

    ///Initialize RNG state variable
    MTRand mtr(seed);

    ///Check if file already exists; if yes ask to overwrite it.
    struct stat stFileInfo;
    if(stat(filename.c_str(),&stFileInfo) == 0)
        {
            wxMessageDialog *fileExistsDialog = new wxMessageDialog(NULL, wxT("File already exists. Overwrite?"), wxT("Overwrite file"), wxYES_NO, wxDefaultPosition);
            if(fileExistsDialog->ShowModal() == wxID_NO) {return 1;}
        }
    ///Open fstream
    fstream f(filename.c_str(), fstream::out | fstream::trunc); //Open for writing and truncate if exists (user is asked first)

    unsigned long i = 0;


    ///Get random number and
    switch(distributionSelection)
                    {
                        case 0: ///32-Bit Real in [0,1]
                            {
                                if(postproc)
                                {
                                    boost::function<string(double)> postproc = getPostprocessFunction<double>();
                                    for(;i < amount;i++)
                                        {
                                            f << postproc(mtr.rand()) << endl;
                                        }
                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.rand() << endl;
                                    }
                                break;
                            }
                        case 1: ///32-Bit Real in [0,n]
                            {
                                if(postproc)
                                {
                                    boost::function<string(double)> postproc = getPostprocessFunction<double>();
                                    for(;i < amount;i++)
                                        {
                                            f << postproc(mtr.rand(ulDouble)) << endl;
                                        }
                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.rand(ulDouble) << endl;
                                    }
                                break;
                            }
                        case 2: ///32-Bit Real in [0,1)
                            {
                                if(postproc)
                                {
                                    boost::function<string(double)> postproc = getPostprocessFunction<double>();
                                    for(;i < amount;i++)
                                        {
                                            f << postproc(mtr.randExc()) << endl;
                                        }
                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randExc() << endl;
                                    }
                                break;
                            }
                        case 3: ///32-Bit Real in [0,n)
                            {
                                if(postproc)
                                {
                                    boost::function<string(double)> postproc = getPostprocessFunction<double>();
                                    for(;i < amount;i++)
                                        {
                                            f << postproc(mtr.randExc(ulDouble)) << endl;
                                        }
                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randExc(ulDouble) << endl;
                                    }
                                break;
                            }
                        case 4: ///32-Bit Real in (0,1)
                            {
                                if(postproc)
                                {
                                    boost::function<string(double)> postproc = getPostprocessFunction<double>();
                                    for(;i < amount;i++)
                                        {
                                            f << postproc(mtr.randDblExc()) << endl;
                                        }

                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randDblExc() << endl;
                                    }
                                break;
                            }
                        case 5: ///32-Bit Real in (0,n)
                            {
                                if(postproc)
                                {
                                    boost::function<string(double)> postproc = getPostprocessFunction<double>();
                                    for(;i < amount;i++)
                                        {
                                            f << postproc(mtr.randDblExc(ulDouble)) << endl;
                                        }

                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randDblExc(ulDouble) << endl;
                                    }
                                break;
                            }
                        case 6: ///Integer in [0,2^32-1]
                            {
                                if(postproc)
                                {
                                    boost::function<string(unsigned long)> postproc = getPostprocessFunction<unsigned long>();
                                    for(;i < amount;i++)
                                        {
                                            f << postproc(mtr.randInt()) << endl;
                                        }

                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randInt() << endl;
                                    }
                                break;
                            }
                        case 7: ///Integer in [0,n] for n < 2^32
                            {
                                if(postproc)
                                {
                                    boost::function<string(unsigned long)> postproc = getPostprocessFunction<unsigned long>();
                                    for(;i < amount;i++)
                                        {
                                            f << postproc(mtr.randInt(ulLong)) << endl;
                                        }

                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randInt(ulLong) << endl;
                                    }
                                break;
                            }
                        case 8: ///53-bit real number in [0,1)
                            {
                                if(postproc)
                                {
                                    boost::function<string(double)> postproc = getPostprocessFunction<double>();
                                    for(;i < amount;i++)
                                        {
                                            f << postproc(mtr.rand53()) << endl;
                                        }

                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.rand53() << endl;
                                    }
                                break;
                            }
                        case 9: ///Nonuniform
                            {
                                if(postproc)
                                {
                                    boost::function<string(double)> postproc = getPostprocessFunction<double>();
                                    for(;i < amount;i++)
                                        {
                                            f << mtr.randNorm(llDouble, ulDouble) << endl;
                                        }

                                }
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randNorm(llDouble, ulDouble) << endl;
                                    }
                                break;
                            }
                        default: break;
                    }
        f.close();
        return 0;
}

int GenRandGMP()
{
    ///Cache parameters
    ulong amount = amountParam;
    string seed = seedParam;
    string filename = filenameParam;
    string ulString = ulParam;
    int algorithmSelection = algorithmSelectionParam;
    ulong bits = bitsParam;

    ///GMP Init
    gmp_randstate_t randstate;

    mpz_t integer;
    mpz_t n;
    mpz_t mseed;

    mpz_init(integer);
    mpz_init(mseed);
    mpz_init(n);
    ///Set values of the pz_t variables
    mpz_set_str(mseed, seed.c_str(), 10);
    mpz_set_str(n, ulString.c_str(), 10);

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
    gmp_randseed(randstate, mseed);
    for(;i < amount;i++)
        {
            mpz_urandomm(integer, randstate, n);
            f << mpz_get_str(NULL, 10, integer)  << endl;
        }
    f.close();
    ///Clear all GMP variables
    mpz_clear(integer);
    mpz_clear(mseed);
    mpz_clear(n);
    gmp_randclear(randstate);
    return 0;
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
    ulong ulSeed = lexical_cast<unsigned long>(seedParam);
    int algorithmSelection = algorithmSelectionParam;
    bool customAlgorithm = customAlgorithmParam;
    //Custom algorithm parameters
    ulong boostAlgoParam1 = boostAlgoParam1Param;
    ulong boostAlgoParam2 = boostAlgoParam2Param;
    ulong boostAlgoParam3 = boostAlgoParam3Param;
    ulong boostAlgoParam4 = boostAlgoParam4Param;
    ulong boostAlgoParam5 = boostAlgoParam5Param;
    ulong boostAlgoParam6 = boostAlgoParam6Param;
    ulong boostAlgoParam7 = boostAlgoParam7Param;
    ulong boostAlgoParam8 = boostAlgoParam8Param;
    ulong boostAlgoParam9 = boostAlgoParam9Param;

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
                    if(!customAlgorithm)
                        {
                            minstd_rand0 linCongr(ulSeed);
                            ProcessBoostAlgorithm<minstd_rand0>(linCongr);
                        }
                    else
                        {
                            linear_congruential<ulong,  boostAlgoParam1, boostAlgoParam2, boostAlgoParam3, boostAlgoParam4> linCongr();
                            ProcessBoostAlgorithm<linear_congruential>(linCongr);
                        }
                    break;
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
