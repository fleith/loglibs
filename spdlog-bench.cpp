#include <iostream>
#include <spdlog/spdlog.h>

int main( void )
{
    int how_many = 1000000;
    namespace spd = spdlog;
    auto logger = spdlog::create<spd::sinks::simple_file_sink_st>("my_logger", "spdlog-bench.txt", false);
    logger->set_pattern("[%Y-%b-%d %T.%e]: %v");
    for(int i  = 0 ; i < how_many; ++i)
        logger->info("spdlog message #{} : This is some text for your pleasure", i);
	return 0;
}

