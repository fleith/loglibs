#include <iostream>
#include <spdlog/spdlog.h>
#include "Lines.h"

int main( void )
{
    namespace spd = spdlog;
    auto logger = spdlog::create<spd::sinks::simple_file_sink_st>("my_logger", "./logs/spdlog-bench.txt", false);
    logger->set_pattern("[%Y-%b-%d %T.%e]: %v");
    for(int i  = 0 ; i < lines::quantity; ++i)
        logger->info("spdlog message #{} : This is some text for your pleasurexxxxxxxxxxxx", i);
	return 0;
}

