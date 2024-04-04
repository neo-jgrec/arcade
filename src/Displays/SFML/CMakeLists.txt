add_library(arcade_sfml SHARED)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_sources(arcade_sfml
    PRIVATE
        ${SOURCES}
)

target_include_directories(arcade_sfml
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/includes
)

find_package(SFML COMPONENTS graphics audio REQUIRED)

target_link_libraries(arcade_sfml
    PRIVATE
        sfml-graphics sfml-audio
)

set_target_properties(arcade_sfml PROPERTIES PREFIX "")

install(TARGETS arcade_sfml LIBRARY DESTINATION lib)