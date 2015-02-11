message(STATUS "Setup Zlib ...")

set(proj ZLIB)

set(DEFAULT_USE_SYSTEM_ZLIB  ON)

SETUP_SYSTEM_LIBRARY(PROJECT ${proj} DOC "  Use a system build of Zlib.")

ADD_SYSTEM_PREFIX(PROJECT ${proj} CMAKE_ALIAS ZLIB_ROOT)

if(USE_SYSTEM_ZLIB)
  message(STATUS "  Using Zlib system version")
else()
  
  set(ZLIB_SB_BUILD_DIR ${CMAKE_BINARY_DIR}/${proj}/build)
  set(ZLIB_SB_SRC ${CMAKE_BINARY_DIR}/${proj}/src/${proj})
  
  # Try official release 1.2.8
  ExternalProject_Add(${proj}
    PREFIX ${proj}
    URL "http://sourceforge.net/projects/libpng/files/zlib/1.2.8/zlib-1.2.8.tar.gz/download"
    URL_MD5 44d667c142d7cda120332623eab69f40
    BINARY_DIR ${ZLIB_SB_BUILD_DIR}
    INSTALL_DIR ${CMAKE_INSTALL_PREFIX}
    CMAKE_CACHE_ARGS
      -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
      -DCMAKE_BUILD_TYPE:STRING=Release
      #-DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER}
      #-DCMAKE_C_COMPILER:FILEPATH=${CMAKE_C_COMPILER}
      -DBUILD_SHARED_LIBS:BOOL=ON
  )
  
    if(MSVC)
      ExternalProject_Add_Step(${proj} msvc_copy_hell
        COMMAND ${CMAKE_COMMAND} -E copy ${ZLIB_SB_BUILD_DIR}/zlib.lib ${CMAKE_INSTALL_PREFIX}/lib/zdll.lib
        DEPENDEES install
      )  
    endif()

     message(STATUS "  Using zlib SuperBuild version")
endif()