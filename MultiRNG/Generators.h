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

///Structs / struct typedefs
template <class datatype>
struct rngProcessingParameters
{
   boost::function<void(datatype input)> postprocFunction;
   std::bitset<4> dataState; ///1: postprocQueue waiting; 2: writeQueue waiting; 3:postprocQueue end; 4: writeQueueEnd
   boost::mutex postprocMutex;
   boost::mutex writeMutex;
   boost::condition_variable postprocCond;
   boost::condition_variable writeCond;
   std::deque<datatype> *postprocQueue;
   std::deque<datatype> *writeQueue;
   string filename;
};

///Static variables,
static unsigned long long amountParam;
static string seedParam;
static string filenameParam;
static string ulParam;
static string llParam;
static int distributionSelectionParam;
static int algorithmSelectionParam;
static int postprocMethodParam;
static int postprocAlgorithmParam;
static ulong bitsParam;
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

    long long i = 0;

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

template <class datatype>
writeToFile(shared_ptr<rngProcessingParameters<datatype> > parameters)
{
    ofstream f(p.filename.c_str(), ofstream::out);
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

    ///Distribution main switch. TODO: Optimize!
    switch(distributionSelection)
        {
            case 0: ///Uniform small int
                {
                    ///Boost Random stuff
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
                    rngProcessingParameters<int> params = new rngProcessingParameters();
                    params.postprocQueue = new deque();
                    *params.postprocQueue.resize(100);
                    *params.writeQueue.resize(100);
                    switch(postprocSelection)
                    {
                        case 0: ///Nothing
                            {
                                for(unsigned long long i = 0;i < amount;i++)
                                    {
                                        ///Generate a random number for 10 times, push in queue and then check if a process is waiting
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());

                                        if(*params.dataState[0])
                                            {
                                                boost::lock_guard<boost::mutex> lock(params.writeMutex);
                                                *params.dataState[1] = false;
                                                params.writeCond.notify_all();
                                            }
                                    }
                                break;
                            }
                        case 1: ///Hash
                            {
                                shared_ptr<rngProcessingParameters<int> > p(params);
                                params.postprocFunction = boost::bind(&hash, p);
                                params.writeQueue = new deque();
                                ///Main loop
                                for(unsigned long long i = 0;i < amount;i++)
                                    {
                                        ///Generate a random number for 10 times, push in queue and then check if a process is waiting
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());
                                        params.postprocQueue.push_front(generator());

                                        if(*params.dataState[0])
                                            {
                                                boost::lock_guard<boost::mutex> lock(mut);
                                                *params.dataState[0] = false;
                                                params.postprocCond.notify_all();
                                            }
                                    }
                                break;
                            }
                        default: break;
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
                    uniform_smallint<int> smallInt(llInt, ulInt);
                    variate_generator<Algorithm&, uniform_smallint<int> > generator(*algorithm, smallInt);
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
                    uniform_smallint<int> smallInt(llInt, ulInt);
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
    ulong ulSeed = lexical_cast<unsigned long>(seedParam);
    long long llSeed = lexical_cast<long long>(seedParam);
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
