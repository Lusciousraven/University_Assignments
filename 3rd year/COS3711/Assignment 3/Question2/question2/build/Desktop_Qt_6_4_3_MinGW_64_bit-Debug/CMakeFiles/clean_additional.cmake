# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\question2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\question2_autogen.dir\\ParseCache.txt"
  "question2_autogen"
  )
endif()
