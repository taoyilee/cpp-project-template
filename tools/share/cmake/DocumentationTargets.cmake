FIND_PACKAGE (Doxygen)
IF (DOXYGEN_FOUND)
    IF (EXISTS ${PROJECT_SOURCE_DIR}/Doxyfile)
        ADD_CUSTOM_TARGET(
            doxygen
            ${DOXYGEN_EXECUTABLE} Doxyfile
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            COMMENT "Generating doxygen project documentation." VERBATIM
        )
        ADD_CUSTOM_TARGET(documentation DEPENDS doxygen)
        ADD_CUSTOM_TARGET(docs DEPENDS doxygen)
    ENDIF (EXISTS ${PROJECT_SOURCE_DIR}/Doxyfile)
ELSE (DOXYGEN_FOUND)
    ADD_CUSTOM_TARGET(doxygen COMMENT "Doxygen not found. Please install doxygen to use this target.")
    ADD_CUSTOM_TARGET(documentation DEPENDS doxygen)
    ADD_CUSTOM_TARGET(docs DEPENDS doxygen)
ENDIF (DOXYGEN_FOUND)
