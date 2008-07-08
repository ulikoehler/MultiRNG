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
static ulong postprocModulus;
static ulong postprocConcatLength;
static string postprocOffset;
static string postprocFillString;
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
template <class T1>
inline string hash(T1 input)
{
    static string inputString = lexical_cast<string>(input);
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
    return resultString;
}

#endif
