add_executable(arcade)

file(GLOB_RECURSE SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_sources(arcade
  PRIVATE
    ${SOURCES}
)

target_include_directories(arcade
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/includes
)

install(TARGETS arcade)
