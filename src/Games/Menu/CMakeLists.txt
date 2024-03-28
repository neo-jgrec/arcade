add_library(arcade_menu SHARED)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_sources(arcade_menu
    PRIVATE
        ${SOURCES}
)

target_include_directories(arcade_menu
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/includes
)

set_target_properties(arcade_menu PROPERTIES PREFIX "")

install(TARGETS arcade_menu LIBRARY DESTINATION lib)
