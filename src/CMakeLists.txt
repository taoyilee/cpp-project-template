FILE (GLOB_RECURSE project_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
SET (project_MOC_HEADERS app.h)
SET (project_LIBS ${Boost_LIBRARIES} ${QT_LIBRARIES} ${Log4Cxx_LIBRARIES})
SET (project_BIN ${PROJECT_NAME})

QT4_WRAP_CPP(project_MOC_SRCS_GENERATED ${project_MOC_HEADERS})

ADD_EXECUTABLE(${project_BIN} ${project_SRCS} ${project_MOC_SRCS_GENERATED})
TARGET_LINK_LIBRARIES(${project_BIN} ${project_LIBS})

