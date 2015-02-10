ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(rawslabsplugin_SOURCES
  rawslabsplugin.cpp
  loadrawdialog.cpp)

SET(rawslabsplugin_HEADERS
  rawslabsplugin.h
  loadrawdialog.h)

#SET(rawslabsplugin_RESOURCES rawslabs.qrc)

SET(rawslabsplugin_FORMS loadrawdialog.ui)

QT5_WRAP_CPP(rawslabsplugin_HEADERS_MOC ${rawslabsplugin_HEADERS})
QT5_WRAP_UI(rawslabsplugin_FORMS_HEADERS ${rawslabsplugin_FORMS})
#QT5_ADD_RESOURCES(rawslabsplugin_RESOURCES_RCC ${rawslabsplugin_RESOURCES})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )

ADD_LIBRARY(rawslabsplugin SHARED ${rawslabsplugin_SOURCES} 
    ${rawslabsplugin_HEADERS_MOC}
    ${rawslabsplugin_FORMS_HEADERS})
#    ${rawslabsplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(rawslabsplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS rawslabsplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
