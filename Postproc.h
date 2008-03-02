#ifndef POSTPROC_H
#define POSTPROC_H
#include "wx_pch.h"
///Custom includes
#include <hashlibpp.h>
using namespace std;
using namespace boost;
using namespace boost::random;

///Static parameters
static int postprocAlgorithmParam;
static int postprocMethodParam;
static string postprocOffsetParam;

///Forward declarations
template <class T1> inline string hash(T1 input);
template <class T2> inline string addNumber(T2 inputNumber);

template<class numType>
inline boost::function<string(numType)> getPostprocessFunction()
{
    switch(postprocMethodParam)
    {
        case 1: //Hash
            {
                return static_cast<string(*)(numType)>(&addNumber<numType>);
                break;
            }
        case 2: //Add
            {
                return static_cast<string(*)(numType)>(&hash<numType>);
                break;
            }
        default: return NULL;
    }
    return NULL;
}

///Calculate a hash value of the input string
template <class T1>
inline string hash(T1 input)
{
    string inputString = lexical_cast<string>(input);
    string resultString;
    switch(postprocAlgorithmParam)
            {
                case 0: ///MD5
                    {
                        hashwrapper *md5 = new md5wrapper();
                        resultString = md5->getHashFromString(inputString);
                        break;
                    }
                case 1: ///SHA1
                    {
                        hashwrapper *sha1 = new sha1wrapper();
                        resultString = sha1->getHashFromString(inputString);
                    }
                case 2: ///SHA256
                    {
                        hashwrapper *sha256 = new sha256wrapper();
                        resultString = sha256->getHashFromString(inputString);
                        break;
                    }
                case 3: ///SHA384
                    {
                        hashwrapper *sha384 = new sha384wrapper();
                        resultString = sha384->getHashFromString(inputString);
                        break;
                    }
                case 4: ///SHA512
                    {
                        hashwrapper *sha512 = new sha512wrapper();
                        resultString = sha512->getHashFromString(inputString);
                        break;
                    }
                default: break;
            }
    return resultString;
}

///Add offset to input;
///Template to support double etc. too;
template<class T2>
inline string addNumber(T2 inputNumber)
{
    T2 offset = lexical_cast<T2>(postprocOffsetParam);
    return lexical_cast<string>(inputNumber + offset);
}

#endif