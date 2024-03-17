add_library(arcade_solarfox SHARED)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_sources(arcade_solarfox
    PRIVATE
        ${SOURCES}
)

target_include_directories(arcade_solarfox
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/includes
)

set_target_properties(arcade_solarfox PROPERTIES PREFIX "")

install(TARGETS arcade_solarfox LIBRARY DESTINATION lib)
