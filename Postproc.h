#ifndef POSTPROC_H
#define POSTPROC_H
#include <hashlibpp.h>
#include "wx_pch.h"
///Custom includes
using namespace std;
using namespace boost;
using namespace boost::random;

///Static parameters
static int postprocAlgorithm;
static int postprocMethod;
static short postprocSelection;

///Constants

///Forward declarations
template <class T1> inline string hash(T1 input);

template<class numType>
inline boost::function<string(numType)> getPostprocessFunction()
{
    switch(postprocSelection)
    {
        default: break;
        case 1: //Hash
            {
                ///TODO
                //return static_cast<string(*)(numType)>(&addNumber<numType>);
                break;
            }
    }
    return NULL;
}

///NullFunction


///Calculate a hash value of the input string
template <class T>
void hash(shared_ptr<rngProcessingParameters<T> > params)
{
    while(!*params.dataState[2] && params->postprocQueue.empty()) ///While not 'EOF' in postprocQueue
    {
        if(params->postprocQueue.empty())
            {
                params.datastate[0] = true;
                boost::unique_lock<boost::mutex> lock(*params.postprocCond);

            }
        string inputString = lexical_cast<string>(params->prostprocQueue.back());
        params->postprocQueue.pop_back();
        string resultString;
        switch(postprocAlgorithm)
                {
                    case 0: ///MD5
                        {
                            hashwrapper *md5 = new md5wrapper();
                            resultString = md5->getHashFromString(inputString);
                            break;
                        }
                    case 1: ///SHA1
                        {
                            sha1wrapper *sha1 = new sha1wrapper();
                            resultString = sha1->getHashFromString(inputString);
                        }
                    case 2: ///SHA256
                        {
                            sha256wrapper *sha256 = new sha256wrapper();
                            resultString = sha256->getHashFromString(inputString);
                            break;
                        }
                    case 3: ///SHA384
                        {
                            sha384wrapper *sha384 = new sha384wrapper();
                            resultString = sha384->getHashFromString(inputString);
                            break;
                        }
                    case 4: ///SHA512
                        {
                            sha512wrapper *sha512 = new sha512wrapper();
                            resultString = sha512->getHashFromString(inputString);
                            break;
                        }
                    default: break;
                }
        params->writeQueue.push_front(lexical_cast<T>(resultString));
        if(*params.dataState[0])
                         {
                              boost::lock_guard<boost::mutex> lock(*params.writeMutex);
                              *params.dataState[1] = false;
                              params.writeCond.notify_all();
                         }
    }
    *params.dataState[3] = true;
}

#endif
