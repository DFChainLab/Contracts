add_contract(dfcio.system dfcio.system ${CMAKE_CURRENT_SOURCE_DIR}/src/dfcio.system.cpp)
#add_executable(dfcio.system.wasm ${CMAKE_CURRENT_SOURCE_DIR}/src/dfcio.system.cpp)
target_include_directories(dfcio.system.wasm
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${CMAKE_CURRENT_SOURCE_DIR}/../dfcio.token/include)

set_target_properties(dfcio.system.wasm
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
