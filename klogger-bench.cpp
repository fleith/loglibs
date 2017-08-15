#include <iostream>

#include <KTools/KLogger.h>
#include <memory>
#include "Lines.h"

int main( void )
{
    std::unique_ptr<KLogger> logger(new KLogger( klogSBC, -1, "klog-bench", "klog-bench.txt",
                                                 klogPrefixOnHeader ));
    for(int i  = 0 ; i < lines::quantity; ++i)
        logger->Log(klogInfo, "klogger message #%d : This is some text for your pleasureX", i);

	return 0;
}

