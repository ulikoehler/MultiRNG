#include "wx_pch.h"


void writeToFile(shared_ptr<rngProcessingParameters<T> > params)
{
    fstream f(*params.filename.c_str(), fstream::out);
    while(!*params.dataState[3] && !params->writeQueue.empty()) ///Stop if no data will come and no data is available
    {
        if(params->writeQueue.empty())
            {
                *params.datastate[1] = true;
                boost::unique_lock<boost::mutex> lock(*params.);
                while(*params.dataState[1])
                    {
                        *params.writeCond.wait()
                    }
            }
        f << params->writeQueue.back();
        params->writeQueue.pop_back();
    }
}
