#
# This CMake Module locates the Log4Cxx library. 
#

FIND_PACKAGE(PkgConfig ${Log4Cxx_FIND_REQUIRED} ${Log4Cxx_FIND_QUIETLY})
IF (PkgConfig_FOUND)
    PKG_CHECK_MODULES (Log4Cxx liblog4cxx ${Log4Cxx_FIND_REQUIRED} ${Log4Cxx_FIND_QUIETLY})
    IF (Log4Cxx_FOUND)
        SET(Log4Cxx_LIBRARY ${Log4Cxx_LIBRARIES})
        SET(Log4Cxx_INCLUDE_DIR ${Log4Cxx_INCLUDE_DIRS})
    ENDIF(Log4Cxx_FOUND)
ENDIF (PkgConfig_FOUND)
