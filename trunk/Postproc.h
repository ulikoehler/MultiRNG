#ifndef POSTPROC_H
#define POSTPROC_H
#include "wx_pch.h"
///Custom includes
#include <hashlibpp.h>
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

///Constants

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
        case 3: //Convert to char(fulls)
            {
                return static_cast<string(*)(numType)>(&addNum<numType>);
                break;
            }
        case 4: //Convert to char(per digit)
            {
                return static_cast<string(*)(numType)>(&hash<numType>);

            }
        default: return NULL;
    }
    return NULL;
}

///NullFunction


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

///Add offset to input (whole number);
///Template to support double etc. too;
template<class T2>
inline string addNumber(T2 inputNumber)
{
    T2 offset = lexical_cast<T2>(postprocOffsetParam);
    return lexical_cast<string>((inputNumber % modulus) + offset);
}

template <class T3>
inline string addNumberPerConcat(T3 input)
{
    ///Init variables
    string inputString = lexical_cast<string>(inputString); ///Parameter converted into a string
    static int inputLength = inputString.length();
    static vector<string> partVec; ///Vector of partials, static to avoid frequent reserving
    partVec.reserve((size_t)ceil(inputLength/postprocConcatLength)); ///Speed up the operation by avoiding dynamic allocation

    ///Check the length of the input is dividable by the concat length
    static int fillTimes = inputLength % postprocConcatLength; //Times to fill with one character
    if(fillTimes != 0)
        {
            static int fillLength = postprocFillString.length();
            for(int i = 0;i < fillTimes;i++)
                {
                    inputString.append(fillLength[i % fillLength]); ///Append the corresponding character to the input string.
                }
        }

    ///Main loop
    for(int i < 0;i < inputLength / postprocConcatLength;i++)
    {

    }

}

#endif
