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

inline string hash(string inputString);

inline boost::function<string(string)> getPostprocessFunction()
{
    boost::function<string(string)> f;
    switch(postprocMethodParam)
    {
        case 1: //Hash
            {
                f = &hash;
                break;
            }
        default: break;
    }
    return f;
}

inline string hash(string inputString)
{
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

#endif
