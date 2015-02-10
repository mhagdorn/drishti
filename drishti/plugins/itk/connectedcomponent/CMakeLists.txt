ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(connectedcomponentplugin_SOURCES 
  connectedcomponent.cpp 
  label.cpp)

SET(connectedcomponentplugin_HEADERS
  connectedcomponent.h 
  label.h )

SET(connectedcomponentplugin_FORMS ../../../propertyeditor.ui)


QT5_WRAP_CPP(connectedcomponentplugin_HEADERS_MOC ${connectedcomponentplugin_HEADERS})
QT5_WRAP_UI(connectedcomponentplugin_FORMS_HEADERS ${connectedcomponentplugin_FORMS})

ADD_LIBRARY(connectedcomponentplugin SHARED ${connectedcomponentplugin_SOURCES}
    ${connectedcomponentplugin_HEADERS_MOC}
    ${connectedcomponentgplugin_FORMS_HEADERS})
TARGET_LINK_LIBRARIES(connectedcomponentplugin 
  common ${ITK_LIBRARIES}
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS connectedcomponentplugin DESTINATION ${PLUGIN_INSTALL_DIR}/renderplugins/ITK)
