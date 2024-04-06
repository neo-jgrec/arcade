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
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(arcade_sdl2
    PRIVATE
        SDL2::SDL2
    -lSDL2 -lSDL2_ttf -lSDL2_image
)

set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")

install(TARGETS arcade_sdl2 LIBRARY DESTINATION lib)
