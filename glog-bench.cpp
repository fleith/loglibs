//
// Created by Alvaro on 8/13/17.
//

#include "glog/logging.h"
#include "Lines.h"


int main(int, char* argv[])
{
    FLAGS_logtostderr = 0;
    FLAGS_log_dir = "logs";
    google::InitGoogleLogging(argv[0]);
    for(int i  = 0 ; i < lines::quantity; ++i)
        LOG(INFO) << "glog message # " << i << ": This is some text for your ple";

    return 0;
}

