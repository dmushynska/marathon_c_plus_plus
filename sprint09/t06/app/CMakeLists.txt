aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_EXE)
include_directories(src)

add_subdirectory(src)
add_executable(simpleWorkerV1 ${SOURCE_EXE})
target_link_libraries(simpleWorkerV1 lib)
