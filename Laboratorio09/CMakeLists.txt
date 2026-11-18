cmake_minimum_required(VERSION 3.20)
project(seguimiento_academico LANGUAGES CXX)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
  "src/model/*.cpp"
  "src/patterns/*.cpp"
  "src/persistence/*.cpp"
  "src/controller/*.cpp"
  "src/view/*.cpp"
)

add_library(seguimiento_core ${PROJECT_SOURCES})
target_include_directories(seguimiento_core PUBLIC src)

add_executable(seguimiento src/main.cpp)
target_link_libraries(seguimiento PRIVATE seguimiento_core)

include(CTest)
if(BUILD_TESTING)
  add_executable(seguimiento_tests src/tests/test_main.cpp)
  target_link_libraries(seguimiento_tests PRIVATE seguimiento_core)
  add_test(NAME seguimiento_tests COMMAND seguimiento_tests)
  set_tests_properties(seguimiento_tests PROPERTIES WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif()
