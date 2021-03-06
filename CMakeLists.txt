cmake_minimum_required(VERSION 3.5)
project(dfcio_contracts VERSION 1.0.1)

set(DFCIO_CDT_VERSION_MIN "1.0")
set(DFCIO_CDT_VERSION_SOFT_MAX "1.0")
#set(DFCIO_CDT_VERSION_HARD_MAX "")

find_package(dfcio.cdt)

### Check the version of dfcio.cdt
set(VERSION_MATCH_ERROR_MSG "")
DFCIO_CHECK_VERSION(VERSION_OUTPUT "${DFCIO_CDT_VERSION}"
                                   "${DFCIO_CDT_VERSION_MIN}"
                                   "${DFCIO_CDT_VERSION_SOFT_MAX}"
                                   "${DFCIO_CDT_VERSION_HARD_MAX}"
                                   VERSION_MATCH_ERROR_MSG)
if(VERSION_OUTPUT STREQUAL "MATCH")
   message(STATUS "Using dfcio.cdt version ${DFCIO_CDT_VERSION}")
elseif(VERSION_OUTPUT STREQUAL "WARN")
   message(WARNING "Using dfcio.cdt version ${DFCIO_CDT_VERSION} even though it exceeds the maximum supported version of ${DFCIO_CDT_VERSION_SOFT_MAX}; continuing with configuration, however build may fail.\nIt is recommended to use dfcio.cdt version ${DFCIO_CDT_VERSION_SOFT_MAX}.x")
else() # INVALID OR MISMATCH
   message(FATAL_ERROR "Found dfcio.cdt version ${DFCIO_CDT_VERSION} but it does not satisfy version requirements: ${VERSION_MATCH_ERROR_MSG}\nPlease use dfcio.cdt version ${DFCIO_CDT_VERSION_SOFT_MAX}.x")
endif(VERSION_OUTPUT STREQUAL "MATCH")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
   set(TEST_BUILD_TYPE "Debug")
   set(CMAKE_BUILD_TYPE "Release")
else()
   set(TEST_BUILD_TYPE ${CMAKE_BUILD_TYPE})
endif()

add_subdirectory(dfcio.msig)
add_subdirectory(dfcio.wrap)
add_subdirectory(dfcio.system)
add_subdirectory(dfcio.token)

if (APPLE)
   set(OPENSSL_ROOT "/usr/local/opt/openssl")
elseif (UNIX)
   set(OPENSSL_ROOT "/usr/include/openssl")
endif()
set(SECP256K1_ROOT "/usr/local")

