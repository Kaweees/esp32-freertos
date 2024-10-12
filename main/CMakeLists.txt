# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.c" "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/*.cc" "${CMAKE_CURRENT_LIST_DIR}/src/*.cxx") # Define PROJECT_SOURCES as a list of all source files

idf_component_register(SRCS ${PROJECT_SOURCES}
                       INCLUDE_DIRS "include")