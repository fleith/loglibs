#include <iostream>

#include <KTools/KLogger.h>
#include <bits/unique_ptr.h>

int main( void )
{
    int how_many = 1000000;

    std::unique_ptr<KLogger> logger(new KLogger( klogSBC, -1, "klog-bench", "klog-bench.txt",
                                                 klogPrefixOnHeader ));
    for(int i  = 0 ; i < how_many; ++i)
        logger->Log(klogInfo, "klogger message #%d : This is some text for your pleasure", i);

	return 0;
}

