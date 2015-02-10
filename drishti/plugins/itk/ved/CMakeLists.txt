ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(vedplugin_SOURCES 
  ved.cpp 
  filter.cpp)

SET(vedplugin_HEADERS
  ved.h 
  filter.h )

SET(vedplugin_FORMS ../../../propertyeditor.ui)

QT5_WRAP_CPP(vedplugin_HEADERS_MOC ${vedplugin_HEADERS})
QT5_WRAP_UI(vedplugin_FORMS_HEADERS ${vedplugin_FORMS})

ADD_LIBRARY(vedplugin SHARED ${vedplugin_SOURCES}
    ${vedplugin_HEADERS_MOC}
    ${vedgplugin_FORMS_HEADERS})
TARGET_LINK_LIBRARIES(vedplugin 
  common ${ITK_LIBRARIES}
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS vedplugin DESTINATION ${PLUGIN_INSTALL_DIR}/renderplugins/ITK)
