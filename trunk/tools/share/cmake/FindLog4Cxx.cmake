#
# This CMake Module locates the Log4Cxx library. 
#

INCLUDE (FindPackageHandleStandardArgs)
FIND_PACKAGE(PkgConfig ${Log4Cxx_FIND_REQUIRED} ${Log4Cxx_FIND_QUIETLY})
IF (PKG_CONFIG_FOUND)
    SET(PKG_CONFIG_PATH_ENV_VAR $ENV{PKG_CONFIG_PATH})
    IF (NOT PKG_CONFIG_PATH_ENV_VAR)
        MESSAGE (FATAL_ERROR "Environment variable PKG_CONFIG_PATH not set. Setting this variable is required in order for pkg-config to locate installed software packages.")
    ENDIF (NOT PKG_CONFIG_PATH_ENV_VAR)
    PKG_CHECK_MODULES (Log4Cxx liblog4cxx)
    IF (Log4Cxx_FOUND)
        SET(Log4Cxx_LIBRARY ${Log4Cxx_LIBRARIES})
        SET(Log4Cxx_INCLUDE_DIR ${Log4Cxx_INCLUDEDIR})
    ENDIF(Log4Cxx_FOUND)
ENDIF (PKG_CONFIG_FOUND)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Log4Cxx DEFAULT_MSG Log4Cxx_LIBRARY Log4Cxx_INCLUDE_DIR)

