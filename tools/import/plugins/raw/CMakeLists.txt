ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(rawplugin_SOURCES
  rawplugin.cpp
  loadrawdialog.cpp)

SET(rawplugin_HEADERS
  rawplugin.h
  loadrawdialog.h)

#SET(rawplugin_RESOURCES raw.qrc)

SET(rawplugin_FORMS loadrawdialog.ui)

QT5_WRAP_CPP(rawplugin_HEADERS_MOC ${rawplugin_HEADERS})
QT5_WRAP_UI(rawplugin_FORMS_HEADERS ${rawplugin_FORMS})
#QT5_ADD_RESOURCES(rawplugin_RESOURCES_RCC ${rawplugin_RESOURCES})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )

ADD_LIBRARY(rawplugin SHARED ${rawplugin_SOURCES} 
    ${rawplugin_HEADERS_MOC}
    ${rawplugin_FORMS_HEADERS})
#    ${rawplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(rawplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS rawplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
