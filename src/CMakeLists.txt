include_directories(${CMAKE_SOURCE_DIR}/src/core)

add_subdirectory(core)

file(GLOB SRCS "*.cpp")

add_executable(example ${SRCS})
target_link_libraries(example compute Qt5::Core)
