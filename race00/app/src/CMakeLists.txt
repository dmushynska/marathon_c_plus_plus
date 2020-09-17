aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_LIB)
add_library(libSnake STATIC ${SOURCE_LIB})
target_link_libraries(libSnake sfml-graphics sfml-window sfml-system)
