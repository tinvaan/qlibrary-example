add_subdirectory(core)

file(GLOB SRCS "*.cpp")

add_executable(example ${SRCS})
target_link_libraries(example Qt5::Core)
