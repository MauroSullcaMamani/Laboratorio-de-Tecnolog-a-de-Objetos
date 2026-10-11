# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Actividades_autogen"
  "CMakeFiles\\Actividades_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Actividades_autogen.dir\\ParseCache.txt"
  )
endif()
