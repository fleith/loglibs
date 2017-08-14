project(liblogs)
cmake_minimum_required(VERSION 2.8.12)

set (CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#######
#spdlog
#######
add_executable(spdlog-bench spdlog-bench.cpp)
target_link_libraries(spdlog-bench ${CONAN_LIBS} Threads::Threads)

add_executable(spdlog-bench-mt spdlog-bench-mt.cpp)
target_link_libraries(spdlog-bench-mt ${CONAN_LIBS} Threads::Threads)

############
#easylogging
############
add_executable(easylogging-bench easylogging-bench.cpp)
target_link_libraries(easylogging-bench Threads::Threads)
target_include_directories(easylogging-bench PRIVATE 3rd_party/easyloggingpp_v9.95.0)
target_sources(easylogging-bench PRIVATE 3rd_party/easyloggingpp_v9.95.0/easylogging++.cc)
configure_file(easyl.conf bin/easyl.conf COPYONLY)