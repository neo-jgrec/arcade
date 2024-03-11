add_library(arcade_snake SHARED)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_sources(arcade_snake
    PRIVATE
        ${SOURCES}
)

target_include_directories(arcade_snake
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/includes
)

install(TARGETS arcade_snake LIBRARY DESTINATION lib)
