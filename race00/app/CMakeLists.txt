set(SOURCE_EXE main.cpp)
include_directories(../3dparty/SFML/include/ src)
add_subdirectory(src)

add_executable(race00 ${SOURCE_EXE})
# include_directories(race00 ${SFML_INCLUDE_DIR})
target_link_libraries(race00 sfml-graphics sfml-window sfml-system libSnake)
