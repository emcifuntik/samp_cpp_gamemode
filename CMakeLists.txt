cmake_minimum_required(VERSION 2.8)

project(samp_cpp)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(AMXConfig)
include(AddSAMPPlugin)
include(PrecompiledHeaders)
include(cotire)

if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)
add_definitions(-DSAMPGDK_AMALGAMATION)
add_definitions(-DSAMPGDK_CPP_WRAPPERS)

file(GLOB_RECURSE PROJECT_SOURCE_FILES "src/*.cpp" "src/*.c" "src/export.def")

macro(GroupSources curdir groupindex)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)

  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      GroupSources(${curdir}/${child} ${groupindex}/${child})
    else()

      string(REPLACE "/" "\\" groupname ${groupindex})

      source_group(${groupname} FILES ${curdir}/${child})
    endif()
  endforeach()
endmacro()

GroupSources(${PROJECT_SOURCE_DIR}/src "Source Files")

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/internal
  ${CMAKE_CURRENT_SOURCE_DIR}/src/internal/amx
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vendor
)


add_samp_plugin(${PROJECT_NAME}
  ${PROJECT_SOURCE_FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 17
  RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/client"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/client"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/lib"
  COTIRE_CXX_PREFIX_HEADER_INIT src/stdafx.h
)

cotire(${PROJECT_NAME})
