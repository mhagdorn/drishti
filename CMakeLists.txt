CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (drishti)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# set version and export 
SET (Drishti_VERSION_MAJOR 2)
SET (Dristhi_VERSION_MINOR 6)
SET (Drishti_VERSION_MINCRO 1)

set(BIN_INSTALL_DIR bin CACHE PATH "Installation directory for executables")
set(LIB_INSTALL_DIR lib CACHE PATH "Installation directory for libraries")
set(PLUGIN_INSTALL_DIR ${LIB_INSTALL_DIR}/${PROJECT_NAME} CACHE PATH "Installation directory for plugins")
set(INCLUDE_INSTALL_DIR include CACHE PATH "Installation directory for headers")
set(DATA_INSTALL_DIR share/${PROJECT_NAME} CACHE PATH "Installation directory for data files")

if (IS_ABSOLUTE ${PLUGIN_INSTALL_DIR})
  set(FULL_PLUGIN_INSTALL_DIR ${PLUGIN_INSTALL_DIR})
else (IS_ABSOLUTE ${PLUGIN_INSTALL_DIR})
  set(FULL_PLUGIN_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/${PLUGIN_INSTALL_DIR})
endif (IS_ABSOLUTE ${PLUGIN_INSTALL_DIR})

INCLUDE(FindPkgConfig)

FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Xml REQUIRED)
FIND_PACKAGE(Qt5OpenGL REQUIRED)
FIND_PACKAGE(Qt5Network REQUIRED)
FIND_PACKAGE(Qt5Multimedia REQUIRED)
FIND_PACKAGE(Qt5MultimediaWidgets REQUIRED)

FIND_PACKAGE(GLUT REQUIRED)
INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIR})
LINK_DIRECTORIES(${GLUT_LIBRARIES})
ADD_DEFINITIONS(${GLUT_DEFINITIONS})
IF(NOT GLUT_FOUND)
    MESSAGE(ERROR " GLUT not found!")
ENDIF(NOT GLUT_FOUND)

FIND_PACKAGE(OpenGL REQUIRED)
INCLUDE_DIRECTORIES(${OpenGL_INCLUDE_DIR})
LINK_DIRECTORIES(${OpenGL_LIBRARIES})
ADD_DEFINITIONS(${OpenGL_DEFINITIONS})
IF(NOT OPENGL_FOUND)
    MESSAGE(ERROR " OPENGL not found!")
ENDIF(NOT OPENGL_FOUND)

FIND_PACKAGE(GLEW REQUIRED)
INCLUDE_DIRECTORIES(${GLEW_INCLUDE_PATH})
LINK_DIRECTORIES(${GLEW_LIBRARY})
ADD_DEFINITIONS(${GLEW_DEFINITIONS})
IF(NOT GLEW_FOUND)
    MESSAGE(ERROR " GLEW not found!")
ENDIF(NOT GLEW_FOUND)

FIND_PACKAGE(QGLVIEWER REQUIRED)
INCLUDE_DIRECTORIES(${QGLVIEWER_INCLUDE_DIR})
LINK_DIRECTORIES(${QGLVIEWER_LIBRARIES})
ADD_DEFINITIONS(${QGLVIEWER_DEFINITIONS})
IF(NOT QGLVIEWER_FOUND)
    MESSAGE(ERROR " QGLViewer not found!")
ENDIF(NOT QGLVIEWER_FOUND)

SET (NETCDF_CXX "YES")
FIND_PACKAGE(NetCDF REQUIRED)
INCLUDE_DIRECTORIES(${NETCDF_INCLUDES})
LINK_DIRECTORIES(${NETCDF_LIBRARIES})
IF(NOT NETCDF_FOUND)
    MESSAGE(ERROR " NetCDF not found!")
ENDIF(NOT NETCDF_FOUND)

CONFIGURE_FILE (${CMAKE_SOURCE_DIR}/DrishtiConfig.h.in ${CMAKE_BINARY_DIR}/DrishtiConfig.h)
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

FIND_PACKAGE(ITK REQUIRED)
INCLUDE(${ITK_USE_FILE})

ADD_SUBDIRECTORY(drishti)
ADD_SUBDIRECTORY(tools)
