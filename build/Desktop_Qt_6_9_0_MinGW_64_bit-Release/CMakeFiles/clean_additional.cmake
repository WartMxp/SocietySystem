# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\SocietySystem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SocietySystem_autogen.dir\\ParseCache.txt"
  "SocietySystem_autogen"
  )
endif()
