
#calculate time
time ./spdlog-bench-mt
#track file descriptors
valgrind -q --track-fds=yes ./spdlog-bench
#call graph using valgrind
valgrind -q --tool=callgrind ./spdlog-bench
#print result of callgrind
callgrind_annotate callgrind.out.PID
#show callgrind on gui application
qcachegrind

