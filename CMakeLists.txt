cmake_minimum_required(VERSION 3.0.0)
project(Sort VERSION 0.1.0)

include(CTest)
include_directories(include)
enable_testing()

aux_source_directory(sources _SOURCES_)
add_executable(Sort main.c ${_SOURCES_})

set(CMAEK_C_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
