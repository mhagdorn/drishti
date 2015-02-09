ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(edgepreservingplugin_SOURCES 
  smoothing.cpp 
  filter.cpp)

SET(edgepreservingplugin_HEADERS
  smoothing.h 
  filter.h )

SET(edgepreservingplugin_FORMS ../../../propertyeditor.ui)


QT4_WRAP_CPP(edgepreservingplugin_HEADERS_MOC ${edgepreservingplugin_HEADERS})
QT4_WRAP_UI(edgepreservingplugin_FORMS_HEADERS ${edgepreservingplugin_FORMS})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_LIBRARY(edgepreservingplugin SHARED ${edgepreservingplugin_SOURCES}
    ${edgepreservingplugin_HEADERS_MOC}
    ${edgepreservinggplugin_FORMS_HEADERS})
TARGET_LINK_LIBRARIES(edgepreservingplugin 
  common ${ITK_LIBRARIES}
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS edgepreservingplugin DESTINATION ${PLUGIN_INSTALL_DIR}/renderplugins/ITK)
