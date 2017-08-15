//
// Created by Alvaro on 8/13/17.
//

#include "easylogging++.h"
#include "Lines.h"

INITIALIZE_EASYLOGGINGPP

int main(int, char* [])
{
    // Load configuration from file
    el::Configurations conf("easyl.conf");
    el::Loggers::reconfigureLogger("default", conf);

    for(int i  = 0 ; i < lines::quantity; ++i)
        LOG(INFO) << "easylog message #" << i << ": This is some text for your pleasurexxxxxxxxxxxxx";
    return 0;
}
