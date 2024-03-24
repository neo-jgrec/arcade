add_library(arcade_ncurses SHARED)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_sources(arcade_ncurses
    PRIVATE
        ${SOURCES}
)

target_include_directories(arcade_ncurses
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/includes
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})

set_target_properties(arcade_ncurses PROPERTIES PREFIX "")

install(TARGETS arcade_ncurses LIBRARY DESTINATION lib)
