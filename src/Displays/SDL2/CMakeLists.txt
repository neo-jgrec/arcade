add_library(arcade_sdl2 SHARED)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_sources(arcade_sdl2
    PRIVATE
        ${SOURCES}
)

target_include_directories(arcade_sdl2
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/includes
)


find_package(SDL2 REQUIRED)
target_link_libraries(arcade_sdl2
    PRIVATE
        SDL2::SDL2
)

install(TARGETS arcade_sdl2 LIBRARY DESTINATION lib)
