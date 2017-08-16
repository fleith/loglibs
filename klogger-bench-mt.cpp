#include <iostream>

#include <KTools/KLogger.h>
#include <memory>
#include <atomic>
#include <thread>
#include "Lines.h"

int main( int argc, char** argv )
{
    std::unique_ptr<KLogger> logger(new KLogger( klogSBC, -1, "klog-bench", "klog-bench.txt",
                                                 klogPrefixOnHeader ));
    int thread_count = 10;
    if(argc > 1)
        thread_count = atoi(argv[1]);

    using namespace std;

    std::atomic<int > msg_counter {0};
    vector<thread> threads;

    for (int t = 0; t < thread_count; ++t)
    {
        threads.push_back(std::thread([&]()
                                      {
                                          while (true)
                                          {
											  int counter = ++msg_counter;
                                              if (counter > lines::quantity) break;
                                              logger->Log(klogInfo, "klogger message #%d : This is some text for your pleasureX", counter);
                                          }
                                      }));
    }

    for(auto &t:threads)
    {
        t.join();
    };

    return 0;
}

