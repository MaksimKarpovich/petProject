
cmake_minimum_required (VERSION 3.14)
project (Pet VERSION 0.1.0)


set(SOURCE_EXE main.c)

set(SOURCE_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/BSP/Drawing/Drawing.c
    ${CMAKE_CURRENT_SOURCE_DIR}/BSP/Moving/Moving.c)
set(HEADER_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/BSP/Drawing/Drawing.h
    ${CMAKE_CURRENT_SOURCE_DIR}/BSP/Moving/Moving.h)

set(HEADER_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/BSP/Drawing
    ${CMAKE_CURRENT_SOURCE_DIR}/BSP/Moving)

include_directories(${HEADER_DIRS})

add_library(foo STATIC ${SOURCE_LIB} ${HEADER_LIB})

add_executable(main ${SOURCE_EXE})


target_link_libraries(main foo)
